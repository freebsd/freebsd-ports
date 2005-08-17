--- ./sources/vector.c.orig	Thu Oct 10 12:01:35 1996
+++ ./sources/vector.c	Tue Aug 16 22:37:14 2005
@@ -5,12 +5,14 @@
  Part of the Kaskade distribution
 */
 
+#include <iostream>
+using namespace std;
 
 template<class T> Vector<T>:: ~Vector() { v+=l; delete[] v; }
 
 template<class T> void Vector<T>:: allocate (int l1, int h1)
-{		
-    l=l1; h=h1; 
+{
+    l=l1; h=h1;
     if (h < l) {
 	cout << "\n*** Class vector: wrong indices: l,h = "
 	<< l << " " << h << "\n";
@@ -23,7 +25,7 @@
 	cout.flush(); abort();
     }
     v -= l;
-}									 
+}
 
 template<class T> void Vector<T>:: resize(int newl, int newh)
 {
