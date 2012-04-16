--- hald/freebsd/probing/probe-usb2-interface.c.orig	2009-08-24 08:42:29.000000000 -0400
+++ hald/freebsd/probing/probe-usb2-interface.c	2012-04-01 19:36:25.000000000 -0400
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
 
@@ -93,7 +93,10 @@ main(int argc, char **argv)
       curr_config = libusb20_dev_get_config_index(pdev);
       pcfg = libusb20_dev_alloc_config(pdev, curr_config);
       if (! pcfg)
-        continue;
+        {
+          libusb20_dev_close(pdev);
+          continue;
+        }
 
       pif = pcfg->interface + iface;
 
@@ -129,6 +132,7 @@ main(int argc, char **argv)
 	    }
 	}
 
+      libusb20_dev_close(pdev);
       free(pcfg);
     }
 
