--- hald/freebsd/hf-usb.c.orig	2008-05-08 01:24:02.000000000 +0200
+++ hald/freebsd/hf-usb.c	2009-03-02 04:23:32.000000000 +0100
@@ -25,13 +25,18 @@
 #  include <config.h>
 #endif
 
+#include <sys/param.h>
 #include <string.h>
 #include <errno.h>
 #include <stdlib.h>
 #include <fcntl.h>
 #include <sys/ioctl.h>
 #include <unistd.h>
+#if __FreeBSD_version >= 800064
+#include <legacy/dev/usb/usb.h>
+#else
 #include <dev/usb/usb.h>
+#endif
 
 #include "../logger.h"
 #include "../osspec.h"
@@ -41,6 +46,11 @@
 #include "hf-util.h"
 
 #define HF_USB_DEVICE			"/dev/usb"
+#if __FreeBSD_version < 800066
+#define HF_USB2_DEVICE			"/dev/usb "
+#else
+#define HF_USB2_DEVICE			"/dev/usbctl"
+#endif
 
 typedef struct
 {
@@ -231,7 +241,7 @@
  * Adapted from usb_compute_udi() in linux2/physdev.c and
  * usbclass_compute_udi() in linux2/classdev.c.
  */
-static void
+void
 hf_usb_device_compute_udi (HalDevice *device)
 {
   g_return_if_fail(HAL_IS_DEVICE(device));
@@ -250,12 +260,13 @@
     hf_device_set_udi(device, "usb_device_%x_%x_%s",
 		      hal_device_property_get_int(device, "usb_device.vendor_id"),
 		      hal_device_property_get_int(device, "usb_device.product_id"),
-		      hal_device_has_property(device, "usb_device.serial")
+		      (hal_device_has_property(device, "usb_device.serial") &&
+		       strcmp(hal_device_property_get_string(device, "usb_device.serial"), ""))
 		      ? hal_device_property_get_string(device, "usb_device.serial")
 		      : "noserial");
 }
 
-static void
+void
 hf_usb_add_webcam_properties (HalDevice *device)
 {
   int unit;
@@ -424,7 +435,7 @@
     hf_devtree_device_set_name(device, di->udi_devnames[0]);
 
   if ((devname = hf_usb_get_devname(di, "ukbd")))	/* USB keyboard */
-    hf_device_set_input(device, "keyboard", devname);
+    hf_device_set_input(device, "keyboard", NULL);
   else if ((devname = hf_usb_get_devname(di, "ums")))	/* USB mouse */
     hf_device_set_input(device, "mouse", devname);
   else if ((devname = hf_usb_get_devname(di, "uhid")))	/* UHID device */
@@ -575,6 +586,8 @@
     {
       if (hal_device_has_capability(device, "hiddev"))
 	hf_runner_run_sync(device, 0, "hald-probe-hiddev", NULL);
+      if (hal_device_has_capability(device, "input.mouse"))
+        hf_runner_run_sync(device, 0, "hald-probe-mouse", NULL);
 
       hf_device_add(device);
     }
@@ -633,9 +646,18 @@
 {
   int i;
 
+  if (g_file_test(HF_USB2_DEVICE, G_FILE_TEST_EXISTS))
+    {
+      hf_usb_fd = -1;
+      return;
+    }
+
   hf_usb_fd = open(HF_USB_DEVICE, O_RDONLY);
   if (hf_usb_fd < 0)
-    HAL_INFO(("unable to open %s: %s", HF_USB_DEVICE, g_strerror(errno)));
+    {
+      HAL_INFO(("unable to open %s: %s", HF_USB_DEVICE, g_strerror(errno)));
+      return;
+    }
 
   for (i = 0; i < 16; i++)
     {
