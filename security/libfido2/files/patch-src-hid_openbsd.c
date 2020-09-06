--- src/hid_openbsd.c.orig	2020-09-01 07:17:43 UTC
+++ src/hid_openbsd.c
@@ -8,6 +8,7 @@
 
 #include <sys/ioctl.h>
 #include <dev/usb/usb.h>
+#include <dev/usb/usb_ioctl.h>
 
 #include <errno.h>
 #include <fcntl.h>
