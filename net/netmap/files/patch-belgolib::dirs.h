--- belgolib/dirs.h.orig	Sun Dec 15 14:54:27 2002
+++ belgolib/dirs.h	Sun Dec 15 14:54:27 2002
@@ -3,6 +3,7 @@
 //   - Consider using vector instead of list<T*>'s 
 
 #include <list>
+using namespace std;
 
 #ifndef __make_dep__
 #include <string>
@@ -91,7 +92,7 @@
 {
     list<T*> result=ld1;
 
-    for(list<T*>::const_iterator i = ld2.begin(); i != ld2.end(); i++)
+    for(typename list<T*>::const_iterator i = ld2.begin(); i != ld2.end(); i++)
 	result.push_back(*i);
 
     return result;
