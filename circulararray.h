#include <iostream>
using namespace std;

template <class T>
class CircularArray
{
private:
    T *array;
    int capacity;
    int back, front;
    
public:
    CircularArray();
    CircularArray(int _capacity);
    virtual ~CircularArray();
    void push_front(T data);  //
    void push_back(T data);    //
    void insert(T data, int pos);
    T pop_front();
    T pop_back();
    bool is_full();    
    bool is_empty();  //realizado
    int size() ;     
    void clear();
    T &operator[](int);
    void sort();
    bool is_sorted();
    void reverse();
    string to_string(string sep=" ");

private:
    int next(int);
    int prev(int);
};

template <class T>
CircularArray<T>::CircularArray()
{
    CircularArray(0);
}

template <class T>
CircularArray<T>::CircularArray(int _capacity)
{
    this->array = new T[_capacity];
    this->capacity = _capacity;
    this->front = this->back = -1;
}

template <class T>
CircularArray<T>::~CircularArray()
{
    delete[] array;
}

template <class T>
int CircularArray<T>::prev(int index)
{
    return (index == 0) ? capacity - 1 : index - 1;
}

template <class T>
int CircularArray<T>::next(int index)
{
    return (index + 1) % capacity;
}


template <class T>
void CircularArray<T>::push_front(T data)
{
   
}

template <class T>
void CircularArray<T>::push_back(T data)
{
    if(is_full()){
        throw "Array is full";
    }
    if(is_empty()){
        front = back = 0;
        array[back] = data;
    }
    else{
        array[next(back)] = data;
        back = next(back);
    }
}

template <class T>
T CircularArray<T>::pop_front()
{
    if(front == back){
        front = -1;
        back = -1;
    }
    else if(front == capacity - 1)
    {
        front = 0;
    }
    else{
        front += 1;
    }
}

template <class T>
T CircularArray<T>::pop_back()
{
    if (front == back){
        front = -1;
        back = -1;
    }
    else if (back == 0)
    {
        back = capacity - 1;
    }
    else{
        back -= 1;
    }
}

template <class T>
bool CircularArray<T>::is_full()
{
    if(back == capacity-1 && front == 0)
    {
        return true;
    } else if (front == back-1 || back == front - 1){
        return true;
    } else {
        return false;
    }
}

template <class T>
bool CircularArray<T>::is_empty()
{
    if (back == front)
    {
        return true;
    }
    return false;
}

template <class T>
int CircularArray<T>::size()
{
    if (is_empty())
    {
        return 0;
    }
    if (front == back) 
    {
        return 1;
    }
    if (front > back) 
    {
        return (capacity - front) + (back + 1);
    } else 
    {
        return back - front + 1;
    }
}

template <class T>
void CircularArray<T>::clear()
{
    front = back = -1;
}

template <class T>
T &CircularArray<T>::operator[](int)
{

}

template <class T>
void CircularArray<T>::sort()
{

}

template <class T>
bool CircularArray<T>::is_sorted()
{
    
}

template <class T>
void CircularArray<T>::reverse()
{
    int par_array= size()%2;
    if(par_array  == 0)
    {
        for (int i = 0; i < size()/2; ++i)
        {
            swap((*this)[i], (*this)[size()-1-i]);
        }
    }
}

template <class T>
string CircularArray<T>::to_string(string sep)
{
    string result = ""; 
    for(int i = 0; i < size(); i++)
        result += std::to_string((*this)[i]) + sep;
    return result;    
}