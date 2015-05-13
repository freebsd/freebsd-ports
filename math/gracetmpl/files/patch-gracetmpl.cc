--- gracetmpl.cpp.orig	2004-09-24 16:56:02.000000000 +0400
+++ gracetmpl.cpp
@@ -21,10 +21,12 @@
 #include <vector>
 #include <map>
 #include <iostream>
+#include <cstring>
+#include <cstdlib>
 
 extern "C" {
 #include <math.h>
-#include <values.h>
+#include <float.h>
 #include <ctype.h>
 #include <time.h>
 #include <sys/time.h>
@@ -981,7 +983,7 @@ string time2string (const string &format
   gettimeofday(&tv,0);
 
   size= (tm==0) ? 
-    strftime(buffer,999,format.c_str(),localtime(&tv.tv_sec)):
+    strftime(buffer,999,format.c_str(),localtime((const time_t *) &tv.tv_sec)):
     strftime(buffer,999,format.c_str(),tm);
   buffer[999]= 0;
   return string(buffer);
