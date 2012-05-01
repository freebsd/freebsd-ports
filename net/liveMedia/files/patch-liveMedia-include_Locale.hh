--- ./liveMedia/include/Locale.hh.orig	2012-04-04 05:07:24.000000000 +0400
+++ ./liveMedia/include/Locale.hh	2012-04-13 20:40:10.000000000 +0400
@@ -32,11 +32,15 @@
 // (or their development environments) don't have "newlocale()".  If, however, your Windows system *does* have "newlocale()",
 // then you can override this by defining "XLOCALE_USED" before #including this file.
 
+#if defined(__FreeBSD__)
+#include <sys/param.h>
+#endif
+
 #ifdef XLOCALE_USED
 #undef LOCALE_NOT_USED
 #undef XLOCALE_NOT_USED
 #else
-#if defined(__WIN32__) || defined(_WIN32)
+#if defined(__WIN32__) || defined(_WIN32) || (__FreeBSD_version < 1000010)
 #define XLOCALE_NOT_USED 1
 #endif
 #endif
