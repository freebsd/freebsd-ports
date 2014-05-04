--- netmap/misc.c.orig	Sun Dec 15 14:54:26 2002
+++ netmap/misc.c	Sun Dec 15 14:54:26 2002
@@ -1,4 +1,4 @@
-#include <strstream>
+#include <sstream>
 #include <string>
 
 #include "misc.h"
@@ -17,7 +17,7 @@
 
 string int_to_str(int i) 
 {
-    strstream ost;
+    stringstream ost;
 
     ost << i << char(0);
 
@@ -55,7 +55,7 @@
 	return false;
     
     bool had_point = false;
-    int beyond_point = 0;
+    unsigned int beyond_point = 0;
 
     int int_first = 0;
     for(unsigned i = 0; i < str.length(); i++) {
