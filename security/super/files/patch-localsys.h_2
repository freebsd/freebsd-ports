--- localsys.h.orig	Fri Jun 18 09:22:22 2004
+++ localsys.h	Fri Sep  3 10:52:44 2004
@@ -295,4 +295,6 @@
 
+#ifndef __FreeBSD__	/* FBSD has a malloc.h that tells people to obey C89. */
 #ifdef HAVE_MALLOC_H
 #include <malloc.h>
+#endif
 #endif
