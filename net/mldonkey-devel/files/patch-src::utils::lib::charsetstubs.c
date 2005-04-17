--- src/utils/lib/charsetstubs.c.orig	Sun Apr 17 04:11:30 2005
+++ src/utils/lib/charsetstubs.c	Sun Apr 17 04:14:49 2005
@@ -44,6 +44,10 @@
 #endif
 #include <iconv.h>
 
+#ifdef __FreeBSD__
+#include <locale.h>
+#endif
+
 #ifdef WIN32
 #define STRICT			/* Strict typing, please */
 #include <windows.h>
