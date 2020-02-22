--- src/hid_openbsd.c.orig	2019-11-28 11:38:08 UTC
+++ src/hid_openbsd.c
@@ -8,6 +8,7 @@
 
 #include <sys/ioctl.h>
 #include <dev/usb/usb.h>
+#include <dev/usb/usb_ioctl.h>
 #include <dev/usb/usbhid.h>
 
 #include <errno.h>
@@ -20,7 +21,7 @@
 #include "fido.h"
 
 #define MAX_UHID	64
-#define MAX_REPORT_LEN	(sizeof(((struct usb_ctl_report *)(NULL))->ucr_data))
+#define MAX_REPORT_LEN	(sizeof(((struct usb_gen_descriptor *)(NULL))->ugd_data))
 
 struct hid_openbsd {
 	int fd;
