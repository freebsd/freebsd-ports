--- ./prnt/hpcups/ErnieFilter.cpp.orig	2010-02-25 02:04:09.000000000 +0300
+++ ./prnt/hpcups/ErnieFilter.cpp	2010-04-18 10:49:13.471529924 +0400
@@ -50,7 +50,7 @@
 #include "ErnieFilter.h"
 
 
-#if defined(__APPLE__) || defined(__linux)
+#if defined(__APPLE__) || defined(__linux) || (__FreeBSD__)
 #include <math.h>
 #endif
 
