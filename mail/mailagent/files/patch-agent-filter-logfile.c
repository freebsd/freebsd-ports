--- ./agent/filter/logfile.c.orig	2008-08-19 17:44:07.000000000 +0900
+++ ./agent/filter/logfile.c	2014-08-14 01:59:33.539704490 +0900
@@ -58,6 +58,12 @@
 #endif
 #endif	/* I_STDLIB */
 
+#ifdef I_STRING
+#include <string.h>
+#else
+#include <strings.h>
+#endif
+
 #ifdef I_TIME
 # include <time.h>
 #endif
