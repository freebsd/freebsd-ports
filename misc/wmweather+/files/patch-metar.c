--- metar.c.orig	Fri May 14 04:55:39 2004
+++ metar.c	Fri Nov  5 19:54:07 2004
@@ -36,6 +36,12 @@
 #include <string.h>
 #include <ctype.h>
 #include <math.h>
+
+#include <sys/param.h>
+#if (__FreeBSD_version < 500000)
+#define NAN (0.0/0.0)
+#endif
+
 #include <sys/stat.h>
 #include <sys/wait.h>
 
