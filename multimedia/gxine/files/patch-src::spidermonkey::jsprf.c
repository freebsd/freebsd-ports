--- src/spidermonkey/jsprf.c.orig	Sat Apr 19 02:11:15 2003
+++ src/spidermonkey/jsprf.c	Sat Apr 19 02:12:27 2003
@@ -57,7 +57,7 @@
 #define VARARGS_ASSIGN(foo, bar)	(foo) = (bar)
 #endif
 */
-#define VARARGS_ASSIGN(foo, bar) __va_copy(foo, bar)
+#define VARARGS_ASSIGN(foo, bar)        (foo) = (bar)
 
 /*
 ** WARNING: This code may *NOT* call JS_LOG (because JS_LOG calls it)
