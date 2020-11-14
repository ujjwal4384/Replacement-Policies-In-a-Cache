#include <iostream>
#include <fstream>
#include<string>
#include<vector>
#include<bits/stdc++.h>
#include <sstream>
#include <algorithm>

using namespace std;

// for FIFO
void fifo(const string &inputFilename,int cacheSize)
{

  ifstream infile{inputFilename};
  ofstream outfile;
  string outputFileName = "19112089_FIFO_"+inputFilename.substr(0,inputFilename.size()-4)+"_"+to_string(cacheSize)+".out";
  outfile.open(outputFileName);
  string s;

  vector <string> g;
  vector <string> cache;
  vector <string> typemiss;
  int compulsory=0;
  int conflictory=0;
  int capacity=0;
  int i=0;
     outfile<<"TOTAL_ACCESSES = "<<i<<endl;
     outfile<<"TOTAL_MISSES = "<<compulsory+capacity<<endl;
     outfile<<"COMPULSORY_MISSES = "<<compulsory<<endl;
     outfile<<"CAPACITY_MISSES = "<<capacity<<"                                                                                                      "<<endl;


 if(infile.is_open())
 {
   while(!infile.eof())
   {

       if(infile>>s)
       {
           g.push_back(s);
           i=i+1;
       }
       else {break;}
   }
 }


      int len=g.size();
      int input=0;
      int clen=0;
    vector<string>::iterator it;

    while(input<len)
    {
        bool found=false;
        for(clen=0;clen<cache.size();clen++)
        {
            if(g[input]==cache[clen])
            {
             found=true   ;
            }
        }
       if(found==false)
        {  outfile<<"MISS"<<endl;

         it = find (typemiss.begin(), typemiss.end(), g[input]);
         if(it!=typemiss.end()){capacity++;}
         else{compulsory++;}
         if(cache.size()<cacheSize)
            {
            cache.push_back(g[input]);
            }
        else
            {
           cache.erase(cache.begin());
           cache.push_back(g[input]);
            }
        }
     if(found)
            {
            outfile<<"HIT"<<endl;
            }

     typemiss.push_back(g[input]);

   input++;
   }

     outfile.seekp(0);
     outfile<<"TOTAL_ACCESSES = "<<i<<endl;
     outfile<<"TOTAL_MISSES = "<<compulsory+capacity<<endl;
     outfile<<"COMPULSORY_MISSES = "<<compulsory<<endl;
     outfile<<"CAPACITY_MISSES = "<<capacity<<endl;


      outfile.close();
      infile.close();

}


// For LRU

void lru(const string &inputFilename,int cacheSize){
    ifstream infile{inputFilename};
    ofstream outfile;
    string outputFileName = "19112089_LRU_"+inputFilename.substr(0,inputFilename.size()-4)+"_"+to_string(cacheSize)+".out";
    outfile.open(outputFileName);
     string s;

  vector <string> g;
  vector <string> cache;
  vector <string> typemiss;

  int compulsory=0;
  int conflictory=0;
  int capacity=0;
  int i=0;
      outfile<<"TOTAL_ACCESSES = "<<i<<endl;
     outfile<<"TOTAL_MISSES = "<<compulsory+capacity<<endl;
     outfile<<"COMPULSORY_MISSES = "<<compulsory<<endl;
     outfile<<"CAPACITY_MISSES = "<<capacity<<"                                                                                                        "<<endl;


 if(infile.is_open())
 {
   while(!infile.eof())
   {

       if(infile>>s)
       {
           g.push_back(s);
           i=i+1;
       }
       else {break;}
   }
 }

      int ord;string temp="Initializing this string with length of enough storage";
      int len=g.size();
      int input=0;
      int clen=0;
    vector<string>::iterator it;

    while(input<len)
    {
        bool found=false;
        for(clen=0;clen<cache.size();clen++)
        {
            if(g[input]==cache[clen])
            {
            found=true;

              temp=cache[clen];

                for(ord=clen+1;ord<cache.size();ord++)
                {
                 cache[ord-1]=cache[ord];
                }
                     cache.erase(cache.end());
                     cache.push_back(temp); outfile<<"HIT"<<endl;break;
            }

        }

         if(found==false)
        {
         outfile<<"MISS"<<endl;
         it = find (typemiss.begin(), typemiss.end(), g[input]);
         if(it!=typemiss.end()){capacity++;}
         else{compulsory++;}
            if(cache.size()<cacheSize)
            {
            cache.push_back(g[input]);
            }
        else
            {
           cache.erase(cache.begin());
           cache.push_back(g[input]);
            }
        }
     typemiss.push_back(g[input]);

   input++;
   }

     outfile.seekp(0);


     outfile<<"TOTAL_ACCESSES = "<<i<<endl;
     outfile<<"TOTAL_MISSES = "<<compulsory+capacity<<endl;
     outfile<<"COMPULSORY_MISSES = "<<compulsory<<endl;
     outfile<<"CAPACITY_MISSES = "<<capacity<<endl;


      outfile.close();
      infile.close();
}


// For Optimal

void optimal(const string &inputFilename,int cacheSize)
{
    ifstream infile{inputFilename};
    ofstream outfile;
    string outputFileName = "19112089_OPTIMAL_"+inputFilename.substr(0,inputFilename.size()-4)+"_"+to_string(cacheSize)+".out";
    outfile.open(outputFileName);
    string s;
    vector <string> g;
  vector <string> cache;
  vector <string> typemiss;

  int compulsory=0;
  int conflictory=0;
  int capacity=0;
   int i=0;
     outfile<<"TOTAL_ACCESSES = "<<i<<endl;
     outfile<<"TOTAL_MISSES = "<<compulsory+capacity<<endl;
     outfile<<"COMPULSORY_MISSES = "<<compulsory<<endl;
     outfile<<"CAPACITY_MISSES = "<<capacity<<"                                                                                                         "<<endl;


 if(infile.is_open())
 {
   while(!infile.eof())
   {

       if(infile>>s)
       {
           g.push_back(s);
           i=i+1;
       }
       else {break;}
   }
 }

      int len=g.size();
      int input=0;
      int clen=0;
      int k;

      vector <int> times(len,0);
    vector<string>::iterator it;

    while(input<len)
    {
        bool found=false;
        for(clen=0;clen<cache.size();clen++)
        {
            if(g[input]==cache[clen])
            {
             found=true   ;
            }
        }
       if(found==false)
        {  outfile<<"MISS"<<endl;

         it = find (typemiss.begin(), typemiss.end(), g[input]);
         if(it!=typemiss.end()){capacity++;}
         else{compulsory++;}
         if(cache.size()<cacheSize)
            {
            cache.push_back(g[input]);
            }
        else
            {
             int max = INT_MIN;int maxIndex =input;
                    for( k=0;k<cacheSize;k++){
                        vector<string> ::iterator it=g.begin();
                        advance(it,input+1);
                        it = find(it,g.end(),cache[k]);
                        if((it-next(g.begin(),input))>max){
                            max = it-next(g.begin(),input);
                            maxIndex = k;
                        }
                    }
                    cache[maxIndex] = g[input];
            }
        }
     if(found)
            {
            outfile<<"HIT"<<endl;
            }

     typemiss.push_back(g[input]);

   input++;
   }

     outfile.seekp(0);

     outfile<<"TOTAL_ACCESSES = "<<i<<endl;
     outfile<<"TOTAL_MISSES = "<<compulsory+capacity<<endl;
     outfile<<"COMPULSORY_MISSES = "<<compulsory<<endl;
     outfile<<"CAPACITY_MISSES = "<<capacity<<endl;

      outfile.close();
      infile.close();

}



int main(int argc,char *argv[])

{
    string type = argv[1];

    string inputFilename = argv[2];

    string ujjwalNumberOfCacheEntries = argv[3];

    int NumberOfCacheEntries;

    stringstream str(ujjwalNumberOfCacheEntries);


    str>>NumberOfCacheEntries;
        cout<<"no. of cache entries "<<NumberOfCacheEntries<<endl;


    if(type == "FIFO")
        {
        fifo(inputFilename,NumberOfCacheEntries);
        }
    if(type == "LRU")
        {
        lru(inputFilename,NumberOfCacheEntries);
        }
    if(type == "OPTIMAL")
        {
        optimal(inputFilename,NumberOfCacheEntries);
        }
    cout<<inputFilename<<" "<<NumberOfCacheEntries<<endl;
    return 0;
}

