--- forecast.orig	Sun Mar 23 01:04:40 2003
+++ forecast.c	Wed Jul 28 11:43:58 2004
@@ -36,6 +36,9 @@
 #include <string.h>
 #include <limits.h>
 #include <math.h>
+#ifndef NAN
+#define NAN (0.0/0.0)
+#endif
 #include <pcre.h>
 
 #include "forecast.h"
