--- Mesh2.h-orig	2011-07-19 12:39:01.000000000 -0500
+++ Mesh2.h	2011-07-19 12:39:23.000000000 -0500
@@ -19,6 +19,7 @@
 #include <math.h>
 #include <limits.h>
 #include <time.h>
+#include <cassert>
 #if  (defined(unix) || defined(__unix)) && !defined(__AIX)
 #define SYSTIMES
 #include <sys/times.h>
