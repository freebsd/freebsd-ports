--- hald/freebsd/probing/probe-usb2-interface.c.orig	2010-01-23 22:01:20.000000000 -0500
+++ hald/freebsd/probing/probe-usb2-interface.c	2010-01-23 22:01:49.000000000 -0500
@@ -58,11 +58,11 @@ main(int argc, char **argv)
   if (pbe == NULL)
     goto end;
 
-  busstr = getenv("HAL_PROP_USB_DEVICE_BUS_NUMBER");
+  busstr = getenv("HAL_PROP_USB_BUS_NUMBER");
   if (! busstr)
     goto end;
 
-  addrstr = getenv("HAL_PROP_USB_DEVICE_PORT_NUMBER");
+  addrstr = getenv("HAL_PROP_USB_PORT_NUMBER");
   if (! addrstr)
     goto end;
 
