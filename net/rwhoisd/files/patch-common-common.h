--- common/common.h.orig	Tue Oct 28 02:23:23 2003
+++ common/common.h	Tue Oct 28 02:23:33 2003
@@ -56,7 +56,7 @@
 # undef _VA_ALIGN
 # undef __va_stack_arg
 # endif
-#include <varargs.h>
+#include <stdarg.h>
 #endif /* HAVE_VPRINTF */
 
 /* this should probably be #ifdef USG */
