--- forecast.c.orig	Sun Mar 23 01:04:40 2003
+++ forecast.c	Fri Nov  5 19:53:51 2004
@@ -36,6 +36,12 @@
 #include <string.h>
 #include <limits.h>
 #include <math.h>
+
+#include <sys/param.h>
+#if (__FreeBSD_version < 500000)
+#define NAN (0.0/0.0)
+#endif
+
 #include <pcre.h>
 
 #include "forecast.h"
