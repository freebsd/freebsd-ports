--- src/lib/ewl_macros.h.orig	Mon Mar 28 22:32:27 2005
+++ src/lib/ewl_macros.h	Sun Sep 25 10:58:16 2005
@@ -58,10 +58,12 @@
  */
 #define ZERO(ptr, type, num) ptr = memset(ptr, 0, sizeof(type) * (num))
 
-#if HAVE___ATTRIBUTE__
-#define __UNUSED__ __attribute__((unused))
-#else
-#define __UNUSED__
+#ifndef MIN
+#define MIN(x, y) (((x) > (y)) ? (y) : (x))
+#endif
+
+#ifndef MAX
+#define MAX(x, y) (((x) > (y)) ? (x) : (y))
 #endif
 
 #endif				/* __EWL_MACROS_H__ */
