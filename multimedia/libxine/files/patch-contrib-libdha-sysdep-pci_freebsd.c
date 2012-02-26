--- contrib/libdha/sysdep/pci_freebsd.c.orig
+++ contrib/libdha/sysdep/pci_freebsd.c
@@ -8,7 +8,7 @@
 /* machine/console.h seems to be outdated by recent FreeBSD *
  * however pcvt_ioctl.h seems to exist for very long time   */
 /* #include <machine/console.h>*/
-#include <machine/pcvt_ioctl.h>
+#include <sys/kbio.h>
 #ifndef GCCUSESGAS
 #define GCCUSESGAS
 #endif
