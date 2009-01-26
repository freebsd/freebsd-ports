--- hald/freebsd/hf-usb.c.orig	2009-01-25 16:34:49.000000000 -0500
+++ hald/freebsd/hf-usb.c	2009-01-25 16:36:42.000000000 -0500
@@ -575,6 +575,8 @@ hf_usb_probe_device (HalDevice *parent,
     {
       if (hal_device_has_capability(device, "hiddev"))
 	hf_runner_run_sync(device, 0, "hald-probe-hiddev", NULL);
+      if (hal_device_has_capability(device, "input.mouse"))
+        hf_runner_run_sync(device, 0, "hald-probe-mouse", NULL);
 
       hf_device_add(device);
     }
