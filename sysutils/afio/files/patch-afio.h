--- afio.h.orig	2018-11-30 14:25:04 UTC
+++ afio.h
@@ -1,5 +1,9 @@
 /* afio.h  defines for afio. */
 
+#ifdef HAVE_PARAM_H
+#include <sys/param.h>
+#endif
+
 #ifdef	SYSTIME
 #include <sys/time.h>
 #else /* SYSTIME */
