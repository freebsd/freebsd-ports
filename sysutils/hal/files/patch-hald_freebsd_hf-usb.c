--- hald/freebsd/hf-usb.c.orig	2008-05-07 19:24:02.000000000 -0400
+++ hald/freebsd/hf-usb.c	2009-05-30 03:20:24.000000000 -0400
@@ -25,13 +25,20 @@
 #  include <config.h>
 #endif
 
+#include <sys/param.h>
 #include <string.h>
 #include <errno.h>
 #include <stdlib.h>
 #include <fcntl.h>
 #include <sys/ioctl.h>
 #include <unistd.h>
+#if __FreeBSD_version < 800092
+#if __FreeBSD_version >= 800064
+#include <legacy/dev/usb/usb.h>
+#else
 #include <dev/usb/usb.h>
+#endif
+#endif
 
 #include "../logger.h"
 #include "../osspec.h"
@@ -40,7 +47,13 @@
 #include "hf-devtree.h"
 #include "hf-util.h"
 
+#if __FreeBSD_version < 800092
 #define HF_USB_DEVICE			"/dev/usb"
+#if __FreeBSD_version < 800066
+#define HF_USB2_DEVICE			"/dev/usb "
+#else
+#define HF_USB2_DEVICE			"/dev/usbctl"
+#endif
 
 typedef struct
 {
@@ -227,51 +240,6 @@ hf_usb_get_full_config_descriptor (int f
   return NULL;
 }
 
-/*
- * Adapted from usb_compute_udi() in linux2/physdev.c and
- * usbclass_compute_udi() in linux2/classdev.c.
- */
-static void
-hf_usb_device_compute_udi (HalDevice *device)
-{
-  g_return_if_fail(HAL_IS_DEVICE(device));
-
-  if (hal_device_has_capability(device, "hiddev"))
-    hf_device_set_full_udi(device, "%s_hiddev",
-			   hal_device_property_get_string(device, "info.parent"));
-  else if (hal_device_has_capability(device, "video4linux"))
-    hf_device_set_full_udi(device, "%s_video4linux",
-		    	   hal_device_property_get_string(device, "info.parent"));
-  else if (hal_device_has_property(device, "usb.interface.number"))
-    hf_device_set_full_udi(device, "%s_if%i",
-			   hal_device_property_get_string(device, "info.parent"),
-			   hal_device_property_get_int(device, "usb.interface.number"));
-  else
-    hf_device_set_udi(device, "usb_device_%x_%x_%s",
-		      hal_device_property_get_int(device, "usb_device.vendor_id"),
-		      hal_device_property_get_int(device, "usb_device.product_id"),
-		      hal_device_has_property(device, "usb_device.serial")
-		      ? hal_device_property_get_string(device, "usb_device.serial")
-		      : "noserial");
-}
-
-static void
-hf_usb_add_webcam_properties (HalDevice *device)
-{
-  int unit;
-
-  g_return_if_fail(HAL_IS_DEVICE(device));
-
-  unit = hal_device_property_get_int(device, "freebsd.unit");
-  if (unit < 0)
-    unit = 0;
-
-  hal_device_property_set_string(device, "info.category", "video4linux");
-  hal_device_add_capability(device, "video4linux");
-  hf_device_property_set_string_printf(device, "video4linux.device", "/dev/video%i", unit);
-  hal_device_property_set_string(device, "info.product", "Video Device");
-}
-
 /* adapted from usbif_set_name() in linux2/physdev.c */
 static const char *
 hf_usb_get_interface_name (const usb_interface_descriptor_t *desc)
@@ -424,7 +392,7 @@ hf_usb_device_new (HalDevice *parent,
     hf_devtree_device_set_name(device, di->udi_devnames[0]);
 
   if ((devname = hf_usb_get_devname(di, "ukbd")))	/* USB keyboard */
-    hf_device_set_input(device, "keyboard", devname);
+    hf_device_set_input(device, "keyboard", NULL);
   else if ((devname = hf_usb_get_devname(di, "ums")))	/* USB mouse */
     hf_device_set_input(device, "mouse", devname);
   else if ((devname = hf_usb_get_devname(di, "uhid")))	/* UHID device */
@@ -575,6 +543,8 @@ hf_usb_probe_device (HalDevice *parent,
     {
       if (hal_device_has_capability(device, "hiddev"))
 	hf_runner_run_sync(device, 0, "hald-probe-hiddev", NULL);
+      if (hal_device_has_capability(device, "input.mouse"))
+        hf_runner_run_sync(device, 0, "hald-probe-mouse", NULL);
 
       hf_device_add(device);
     }
@@ -633,9 +603,18 @@ hf_usb_privileged_init (void)
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
@@ -885,3 +864,50 @@ HFDevdHandler hf_usb_devd_handler = {
   .add =	hf_usb_devd_add,
   .remove =	hf_usb_devd_remove
 };
+#endif
+
+/*
+ * Adapted from usb_compute_udi() in linux2/physdev.c and
+ * usbclass_compute_udi() in linux2/classdev.c.
+ */
+void
+hf_usb_device_compute_udi (HalDevice *device)
+{
+  g_return_if_fail(HAL_IS_DEVICE(device));
+
+  if (hal_device_has_capability(device, "hiddev"))
+    hf_device_set_full_udi(device, "%s_hiddev",
+			   hal_device_property_get_string(device, "info.parent"));
+  else if (hal_device_has_capability(device, "video4linux"))
+    hf_device_set_full_udi(device, "%s_video4linux",
+		    	   hal_device_property_get_string(device, "info.parent"));
+  else if (hal_device_has_property(device, "usb.interface.number"))
+    hf_device_set_full_udi(device, "%s_if%i",
+			   hal_device_property_get_string(device, "info.parent"),
+			   hal_device_property_get_int(device, "usb.interface.number"));
+  else
+    hf_device_set_udi(device, "usb_device_%x_%x_%s",
+		      hal_device_property_get_int(device, "usb_device.vendor_id"),
+		      hal_device_property_get_int(device, "usb_device.product_id"),
+		      (hal_device_has_property(device, "usb_device.serial") &&
+		       strcmp(hal_device_property_get_string(device, "usb_device.serial"), ""))
+		      ? hal_device_property_get_string(device, "usb_device.serial")
+		      : "noserial");
+}
+
+void
+hf_usb_add_webcam_properties (HalDevice *device)
+{
+  int unit;
+
+  g_return_if_fail(HAL_IS_DEVICE(device));
+
+  unit = hal_device_property_get_int(device, "freebsd.unit");
+  if (unit < 0)
+    unit = 0;
+
+  hal_device_property_set_string(device, "info.category", "video4linux");
+  hal_device_add_capability(device, "video4linux");
+  hf_device_property_set_string_printf(device, "video4linux.device", "/dev/video%i", unit);
+  hal_device_property_set_string(device, "info.product", "Video Device");
+}
