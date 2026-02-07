--- xmalloc.c.orig	Wed Aug 11 15:25:47 2004
+++ xmalloc.c	Wed Aug 11 15:26:35 2004
@@ -54,6 +54,8 @@
 # define EXIT_FAILURE 1
 #endif
 
+#include "system.h"
+
 /* Prototypes for functions defined here.  */
 #if defined (__STDC__) && __STDC__
 static VOID *fixup_null_alloc (size_t n);
@@ -67,12 +69,6 @@
 /* Exit value when the requested amount of memory is not available.
    The caller may set it to some other value.  */
 int xmalloc_exit_failure = EXIT_FAILURE;
-
-#if __STDC__ && (HAVE_VPRINTF || HAVE_DOPRNT)
-void error (int, int, const char *, ...);
-#else
-void error ();
-#endif
 
 static VOID *
 fixup_null_alloc (n)
