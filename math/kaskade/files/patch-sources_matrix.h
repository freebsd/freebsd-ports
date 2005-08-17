--- ./sources/matrix.h.orig	Fri Dec 10 15:20:13 1999
+++ ./sources/matrix.h	Tue Aug 16 22:41:02 2005
@@ -13,21 +13,22 @@
 //-------------------------------------------------------------------------
 
 #include <stdio.h>
-#include <iostream.h>
+#include <iostream>
+using namespace std;
 
 
 template<class T>
- 
-class Matrix							 
-{									 
-  public:								 
 
-    T**  row;						 
-    int  rl, rh, cl, ch;					 
-									 
-    Matrix (int rl1, int rh1, int cl1, int ch1)			 
+class Matrix
+{
+  public:
+
+    T**  row;
+    int  rl, rh, cl, ch;
+
+    Matrix (int rl1, int rh1, int cl1, int ch1)
 			      { allocate (rl1,rh1,cl1,ch1); }
-    Matrix (int nr1, int nc1) { allocate (1,  nr1, 1, nc1); }	
+    Matrix (int nr1, int nc1) { allocate (1,  nr1, 1, nc1); }
     ~Matrix();
 
 
