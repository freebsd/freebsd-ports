--- terms.c.orig	2026-03-05 15:10:44 UTC
+++ terms.c
@@ -28,7 +28,7 @@
 #include <gpm.h>
 #endif				/* USE_GPM */
 #ifdef USE_SYSMOUSE
-static int is_xterm = 0;
+static int is_xterm = 1;
 #include <osreldate.h>
 #if (__FreeBSD_version >= 400017) || (__FreeBSD_kernel_version >= 400017)
 #include <sys/consio.h>
