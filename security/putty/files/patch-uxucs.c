--- uxucs.c.orig	Sat Apr 26 16:22:42 2003
+++ uxucs.c	Fri Feb 13 15:27:13 2004
@@ -12,6 +12,16 @@
 #include "terminal.h"
 #include "misc.h"
 
+#ifdef FREEBSD_MB_SUPPORT
+size_t  mbrtowc __P((wchar_t * __restrict, const char * __restrict, size_t,
+            mbstate_t * __restrict));
+size_t  wcrtomb __P((char * __restrict, wchar_t, mbstate_t * __restrict));
+
+#include "mbrtowc.c"
+#include "wcrtomb.c"
+
+#endif
+
 /*
  * Unix Unicode-handling routines.
  */
