--- kernel/alloc.c.orig	Sun May 30 16:26:22 2004
+++ kernel/alloc.c	Sun May 30 16:27:34 2004
@@ -30,6 +30,8 @@
 #  endif
 #endif
 
+#include <stdlib.h>
+
 #if defined(HAVE_DECL_POSIX_MEMALIGN) && !HAVE_DECL_POSIX_MEMALIGN
 extern int posix_memalign(void **, size_t, size_t);
 #endif
@@ -122,9 +124,6 @@
 #    define real_free MPFree
 
 #  else
-     /* Add your machine here and send a patch to fftw@fftw.org 
-        or (e.g. for Windows) configure --with-our-malloc16 */
-#    error "Don't know how to malloc() aligned memory."
 #  endif
 
 #else /* !defined(MIN_ALIGMENT) */
