--- kstars/kstars/indi/fli/libfli-usb-sys-bsd.c.orig	2005-09-10 04:17:35.000000000 -0400
+++ kstars/kstars/indi/fli/libfli-usb-sys-bsd.c	2009-07-06 17:12:21.000000000 -0400
@@ -41,8 +41,15 @@
 
 */
 
+#include <sys/param.h>
 #include <sys/types.h>
+#if __FreeBSD_version >= 800069
+#include <libusb20.h>
+#include <dev/usb/usb_ioctl.h>
+#define	USB_SET_TIMEOUT	USB_SET_RX_TIMEOUT
+#else
 #include <dev/usb/usb.h>
+#endif
 #include <sys/ioctl.h>
 
 #include <unistd.h>
