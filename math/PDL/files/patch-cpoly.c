--- Basic/Math/cpoly.c.orig	Wed Sep 25 01:05:04 2002
+++ Basic/Math/cpoly.c	Wed Sep 25 01:13:38 2002
@@ -9,7 +9,6 @@
 #include <stdlib.h>
 #include <math.h>
 #if !defined(WIN32) && !defined(_WIN32) && !defined(__APPLE__)
-#include <values.h>
 #endif
 #include <float.h>
 /* #define DEBUGMAIN */   /* Set up debugging main, etc. */
@@ -750,8 +749,8 @@
 #if !defined(WIN32) && !defined(_WIN32) && !defined(__APPLE__)
   base = 2;
   eta = DBL_EPSILON;
-  smalno = MINDOUBLE;
-  infin = MAXDOUBLE;
+  smalno = DBL_MIN;
+  infin = DBL_MAX;
 #else
   base = 2;
   eta = DBL_EPSILON;
