--- ./components/gatherer/standard/pstext/libs/include/str.h.orig	Fri Aug  1 14:17:54 2003
+++ ./components/gatherer/standard/pstext/libs/include/str.h	Fri Aug  1 14:19:40 2003
@@ -12,8 +12,11 @@
  * str.h,v 1.1.1.1 1994/04/26 19:08:08 hardy Exp
  */
 
+#ifdef __STRICT_ANSI__
+#include <stdarg.h>
+#else
 #include <varargs.h>
-
+#endif
 
 #ifdef __ARGS
 #undef __ARGS
