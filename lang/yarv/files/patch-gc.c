--- ./gc.c.orig	Thu Apr 13 05:18:48 2006
+++ ./gc.c	Thu Oct 19 13:56:46 2006
@@ -34,6 +34,10 @@
 #include <windows.h>
 #endif
 
+#ifdef __ia64__
+#include <ucontext.h>
+#endif
+
 int rb_io_fptr_finalize(struct OpenFile*);
 
 #if !defined(setjmp) && defined(HAVE__SETJMP)
