
--- kstars/kstars/indi/fli/libfli-usb-sys-bsd.c.orig	2005-09-10 03:17:35.000000000 -0500
+++ kstars/kstars/indi/fli/libfli-usb-sys-bsd.c	2009-03-26 09:44:39.470081183 -0500
@@ -41,8 +41,13 @@
 
 */
 
+#include <sys/param.h>
 #include <sys/types.h>
+#if __FreeBSD_version > 800061
+#include <legacy/dev/usb/usb.h>
+#else
 #include <dev/usb/usb.h>
+#endif
 #include <sys/ioctl.h>
 
 #include <unistd.h>


