--- netmap/misc.h.orig	Sun Dec 15 14:54:26 2002
+++ netmap/misc.h	Sun Dec 15 14:54:26 2002
@@ -6,6 +6,7 @@
 #include <iostream>
 
 #include <list>
+using namespace std;
 
 
 string indent(unsigned);
@@ -21,7 +22,7 @@
 template <class T>
 bool contains(list<T>& l, const T& t) 
 {
-    for(list<T>::iterator li = l.begin(); li != l.end(); li++)
+    for(typename list<T>::iterator li = l.begin(); li != l.end(); li++)
 	if((*li) == t)
 	    return true;
     return false;
@@ -31,7 +32,7 @@
 list<T> intersect(list<T>& l1, list<T>& l2) 
 {
     list<T> result;
-    for(list<T>::iterator li = l1.begin(); li != l1.end(); li++)
+    for(typename list<T>::iterator li = l1.begin(); li != l1.end(); li++)
 	if(contains(l2, *li))
 	    result.push_back(*li);
 
