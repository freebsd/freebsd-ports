--- hald/freebsd/hf-usb.c.orig	2009-09-17 08:49:46.000000000 -0500
+++ hald/freebsd/hf-usb.c	2010-03-17 22:20:33.000000000 -0500
@@ -392,7 +392,7 @@
     hf_devtree_device_set_name(device, di->udi_devnames[0]);
 
   if ((devname = hf_usb_get_devname(di, "ukbd")))	/* USB keyboard */
-    hf_device_set_input(device, "keyboard", "keys", devname);
+    hf_device_set_input(device, "keyboard", "keys", NULL);
   else if ((devname = hf_usb_get_devname(di, "ums")))	/* USB mouse */
     hf_device_set_input(device, "mouse", NULL, devname);
   else if ((devname = hf_usb_get_devname(di, "uhid")))	/* UHID device */
@@ -908,6 +908,8 @@
 
   hal_device_property_set_string(device, "info.category", "video4linux");
   hal_device_add_capability(device, "video4linux");
+  hal_device_add_capability(device, "video4linux.video_capture");
   hf_device_property_set_string_printf(device, "video4linux.device", "/dev/video%i", unit);
   hal_device_property_set_string(device, "info.product", "Video Device");
+  hal_device_property_set_string(device, "video4linux.version", "1");
 }
