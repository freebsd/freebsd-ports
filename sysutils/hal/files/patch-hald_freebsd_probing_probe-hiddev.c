--- hald/freebsd/probing/probe-hiddev.c.orig	2008-05-07 19:24:08.000000000 -0400
+++ hald/freebsd/probing/probe-hiddev.c	2009-02-24 00:42:06.000000000 -0500
@@ -25,12 +25,21 @@
 #  include <config.h>
 #endif
 
+#include <sys/param.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <fcntl.h>
+#ifndef HAVE_LIBUSB20
 #include <sys/ioctl.h>
 #include <dev/usb/usb.h>
 #include <dev/usb/usbhid.h>
+#else
+#if __FreeBSD_version >= 800064
+#include <dev/usb/usbhid.h>
+#else
+#include <dev/usb2/include/usb2_hid.h>
+#endif
+#endif
 #include <usbhid.h>
 
 #include "../libprobe/hfp.h"
@@ -65,7 +74,12 @@ main (int argc, char **argv)
   /* give a meaningful process title for ps(1) */
   setproctitle("%s", device_file);
 
+#ifdef HAVE_LIBUSB20
+  report_id = hid_get_report_id(fd);
+  if (report_id == -1)
+#else
   if (ioctl(fd, USB_GET_REPORT_ID, &report_id) < 0)
+#endif
     goto end;
 
   hid_init(NULL);
