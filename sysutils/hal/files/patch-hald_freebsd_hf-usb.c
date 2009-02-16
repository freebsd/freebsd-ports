--- hald/freebsd/hf-usb.c.orig	2008-05-07 19:24:02.000000000 -0400
+++ hald/freebsd/hf-usb.c	2009-02-15 22:17:58.000000000 -0500
@@ -41,6 +41,7 @@
 #include "hf-util.h"
 
 #define HF_USB_DEVICE			"/dev/usb"
+#define HF_USB2_DEVICE			"/dev/usb "
 
 typedef struct
 {
@@ -575,6 +576,8 @@ hf_usb_probe_device (HalDevice *parent,
     {
       if (hal_device_has_capability(device, "hiddev"))
 	hf_runner_run_sync(device, 0, "hald-probe-hiddev", NULL);
+      if (hal_device_has_capability(device, "input.mouse"))
+        hf_runner_run_sync(device, 0, "hald-probe-mouse", NULL);
 
       hf_device_add(device);
     }
@@ -633,9 +636,18 @@ hf_usb_privileged_init (void)
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
