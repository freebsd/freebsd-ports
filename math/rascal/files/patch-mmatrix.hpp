--- modules/mmatrix.hpp.orig	Mon Aug 16 19:17:01 2004
+++ modules/mmatrix.hpp	Mon Aug 16 19:27:48 2004
@@ -33,14 +33,14 @@
    public:
       mmatrix(int aN,int aM) : N(aN),M(aM) 
       { 
-         a=new (T *)[N];
+         a=new T *[N];
          int i;
          for(i=0;i<N;i++)
             a[i]=new T[M];
       }
       mmatrix(int aN,int aM,const T & x,const T & y) : N(aN),M(aM) 
       { 
-         a=new (T *)[N];
+         a=new T *[N];
          int i;
          for(i=0;i<N;i++)
             a[i]=new T[M];
@@ -51,14 +51,14 @@
       }
       mmatrix(const T & b) : N(1),M(1)
       {
-         a=new (T *)[1];
+         a=new T *[1];
          a[0]=new T[1];
          a[0][0]=b;
       }
       mmatrix(const mmatrix<T> &b) : N(b.N),M(b.M)
       { 
          int i,j; 
-         a=new (T *)[N];   
+         a=new T *[N];   
          for(i=0;i<N;i++) 
          {
             a[i]=new T[M];
@@ -77,7 +77,7 @@
          {
             for(i=0;i<N;i++) delete [] a[i]; delete [] a;  // what if self-assigment ?!??
             N=b.N;M=b.M;
-            a=new (T *)[N];
+            a=new T *[N];
             for(i=0;i<N;i++)
                a[i]=new T[M];
          }
