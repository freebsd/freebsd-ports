--- libs/tubo.c.orig	Sat Oct  8 11:33:42 2005
+++ libs/tubo.c	Sat Oct  8 11:34:37 2005
@@ -296,9 +296,12 @@
     printf("tubowait...\n");
 #endif
 #ifdef	__FreeBSD__
+#include <osreldate.h>
+#if __FreeBSD_version < 503000
     /* This apparently does the bug workaround for wait failure
      * on FreeBSD 5.1: */
     if (kill(PID,SIGCONT) == 0) return TRUE;
+#endif
 #endif
 #ifdef HYPER_DEBUG
     printf("tubowait...dead...\n");
