--- metar.orig	Sun Sep 22 22:00:53 2002
+++ metar.c	Wed Jul 28 11:44:50 2004
@@ -36,6 +36,9 @@
 #include <string.h>
 #include <ctype.h>
 #include <math.h>
+#ifndef NAN
+#define NAN (0.0/0.0)
+#endif
 #include <sys/stat.h>
 #include <sys/wait.h>
