--- src/video_out/libdha/sysdep/pci_freebsd.c.orig	Sun May 28 22:49:02 2006
+++ src/video_out/libdha/sysdep/pci_freebsd.c	Sun May 28 22:50:59 2006
@@ -8,7 +8,7 @@
 /* machine/console.h seems to be outdated by recent FreeBSD *
  * however pcvt_ioctl.h seems to exist for very long time   */
 /* #include <machine/console.h>*/
-#include <machine/pcvt_ioctl.h>
+#include <sys/kbio.h>
 #ifndef GCCUSESGAS
 #define GCCUSESGAS
 #endif
