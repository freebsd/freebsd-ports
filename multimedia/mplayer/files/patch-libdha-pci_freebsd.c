--- libdha/sysdep/pci_freebsd.c.orig	Fri May 26 15:26:22 2006
+++ libdha/sysdep/pci_freebsd.c	Fri May 26 15:28:39 2006
@@ -5,10 +5,7 @@
 */
 #include <errno.h>
 #include <sys/file.h>
-/* machine/console.h seems to be outdated by recent FreeBSD *
- * however pcvt_ioctl.h seems to exist for very long time   */
-/* #include <machine/console.h>*/
-#include <machine/pcvt_ioctl.h>
+#include <sys/kbio.h>
 #ifndef GCCUSESGAS
 #define GCCUSESGAS
 #endif
