//
//  main.cpp
//  Queue
//
//  Created by Tatyana Volkorezova on 30.11.2017.
//  Copyright © 2017 shpp.com. All rights reserved.
//

#include <iostream>
const int SIZE_OF_ARRAY = 100;
using namespace std;


class Queue{
public:
    int q[20];
    int* first;
    int* last;
    
    Queue(){
        first = q;
        last = q;
    }
    void putToQueue(int value){
        *last = value;
        last++;
    }
    int getFromQueue(){
        int data = *first;
        first++;
        return data;
    }
    
    //is queue full or empty
    string isVoidQueue(){
        string result;
        if (first == last){
            result = "yes";
        }else{
            result = "no";
        }
        return result;
    }
};

class Stack{
public:
    int stack[20];
    int* top;
    int counterOfStack;
    
    Stack(){
        top = stack;
        counterOfStack = 0;//stack is empty
    }
    
    void putToStack(int value){
        *top = value;
        top++;
        counterOfStack++;
    }
    
    int getFromStack(){
        //if the first element - move back on one position for display data
        if (*top == 0){
            top--;
        }
        int value = *top;
        top--;
        counterOfStack--;
        return value;
    }
    
    //is stack empty or full
    string isVoidStack(){
        string result;
        if (counterOfStack == 0){
            result = "yes";
        }else{
            result = "no";
        }
        return result;
    }
    
};

class Map{
public:
    int array[SIZE_OF_ARRAY];
    
    int hash(char* str){
        int hashResult = 0;
        for(int i = 0; i < SIZE_OF_ARRAY; i++) {
            hashResult = strlen(str)+array[i];
        }
        cout<<"result"<<hashResult<<endl;
        return hashResult;
    }
    
    int getFromMap(char* str){
        return array[hash(str)];
    }
    
    void putToMap(char* str, int value){
        array[hash(str)] = value;
    }
};

int main(int argc, const char * argv[]) {
    
    //work with queue
    Queue queue;
    cout<<"Is it end of queue? = "<<queue.isVoidQueue()<<endl;
    queue.putToQueue(2);
    queue.putToQueue(8);
    queue.putToQueue(3);
    queue.putToQueue(0);
    
    cout<<"-"<<queue.getFromQueue()<<endl;
    cout<<"-"<<queue.getFromQueue()<<endl;
    cout<<"-"<<queue.getFromQueue()<<endl;
    cout<<"Is it end of queue? =  "<<queue.isVoidQueue()<<endl;
    
    //work with stack
    Stack stack;
    cout<<"Is stack empty? "<<stack.isVoidStack()<<endl;;
    stack.putToStack(23);
    stack.putToStack(12);
    stack.putToStack(22);
    stack.putToStack(29);
    stack.putToStack(30);
    stack.putToStack(31);
    stack.putToStack(32);
    stack.putToStack(33);
    
    cout<<"Counter of stack members = "<<stack.counterOfStack<<endl;
    cout<<"-"<<stack.getFromStack()<<endl;
    cout<<"-"<<stack.getFromStack()<<endl;
    cout<<"-"<<stack.getFromStack()<<endl;
    cout<<"-"<<stack.getFromStack()<<endl;
    cout<<"-"<<stack.getFromStack()<<endl;
    cout<<"-"<<stack.getFromStack()<<endl;
    cout<<stack.counterOfStack<<endl;
    cout<<"-"<<stack.getFromStack()<<endl;
    
    //work with map
    Map map;
    map.putToMap("tanya", 27);
    map.putToMap("asha", 28);
    map.putToMap("qwerty", 12);
    
    cout<<map.getFromMap("tanya")<<endl;
    cout<<map.getFromMap("qwerty")<<endl;
    
    return 0;
}
