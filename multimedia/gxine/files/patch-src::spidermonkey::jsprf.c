--- src/spidermonkey/jsprf.c.orig	Fri Mar  7 02:14:11 2003
+++ src/spidermonkey/jsprf.c	Wed Sep 21 20:20:45 2005
@@ -57,7 +57,12 @@
 #define VARARGS_ASSIGN(foo, bar)	(foo) = (bar)
 #endif
 */
-#define VARARGS_ASSIGN(foo, bar) __va_copy(foo, bar)
+#include <osreldate.h>
+#if __FreeBSD_version >= 500000
+#define VARARGS_ASSIGN(foo, bar) va_copy(foo, bar)
+#else
+#define VARARGS_ASSIGN(foo, bar)	(foo) = (bar)
+#endif
 
 /*
 ** WARNING: This code may *NOT* call JS_LOG (because JS_LOG calls it)
