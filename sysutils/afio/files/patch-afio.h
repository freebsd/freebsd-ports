--- afio.h.orig	Sun Sep 20 04:04:54 1998
+++ afio.h	Wed Dec  9 01:33:32 1998
@@ -1,5 +1,9 @@
 /* afio.h  defines for afio. */
 
+#ifdef HAVE_PARAM_H
+#include <sys/param.h>
+#endif
+
 #ifdef	SYSTIME
 #include <sys/time.h>
 #else /* SYSTIME */
