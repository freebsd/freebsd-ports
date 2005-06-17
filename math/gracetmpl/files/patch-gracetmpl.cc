--- gracetmpl.cpp.bak	Fri Sep 24 21:56:02 2004
+++ gracetmpl.cpp	Sat Jun 18 00:18:52 2005
@@ -24,7 +24,7 @@
 
 extern "C" {
 #include <math.h>
-#include <values.h>
+#include <float.h>
 #include <ctype.h>
 #include <time.h>
 #include <sys/time.h>
@@ -981,7 +981,7 @@
   gettimeofday(&tv,0);
 
   size= (tm==0) ? 
-    strftime(buffer,999,format.c_str(),localtime(&tv.tv_sec)):
+    strftime(buffer,999,format.c_str(),localtime((const time_t *) &tv.tv_sec)):
     strftime(buffer,999,format.c_str(),tm);
   buffer[999]= 0;
   return string(buffer);
