--- ./usbrh_main.c.orig	2008-03-24 23:23:26.000000000 +0900
+++ ./usbrh_main.c	2009-07-20 23:22:59.000000000 +0900
@@ -198,7 +198,7 @@
                 break;
             default:
                 usage();
-                exit(0);
+                return(0);
                 break;
         }
     }
@@ -209,7 +209,7 @@
 
     if(flag_l){
         listdevice(USBRH_VENDOR, USBRH_PRODUCT);
-        exit(0);
+        return(0);
     }
 
     if(flag_d)
@@ -217,7 +217,7 @@
 
     if((dev = searchdevice(USBRH_VENDOR, USBRH_PRODUCT, DeviceNum)) == (struct usb_device *)NULL){
         puts("USBRH not found");
-        exit(1);
+        return(1);
     } 
 
     if(flag_d){
@@ -226,26 +226,30 @@
     dh = usb_open(dev);
     if(dh == NULL){
         puts("usb_open error");
-        exit(2);
+        return(2);
     }
 
     if((rc = usb_set_configuration(dh, dev->config->bConfigurationValue))<0){
         puts("usb_set_configuration error");
         usb_close(dh);
-        exit(3);
+        return(3);
     }
 
     if((rc =usb_claim_interface(dh, dev->config->interface->altsetting->bInterfaceNumber))<0){
         //puts("usb_claim_interface error");
+#if 0
         if((rc = usb_detach_kernel_driver_np(dh, dev->config->interface->altsetting->bInterfaceNumber))<0){
             puts("usb_detach_kernel_driver_np error");
             usb_close(dh);
             exit(4);
         }else{
+#endif
+	{
+	
             if((rc =usb_claim_interface(dh, dev->config->interface->altsetting->bInterfaceNumber))<0){
                 puts("usb_claim_interface error");
                 usb_close(dh);
-                exit(4);
+                return(4);
             }
         }
     }
@@ -311,7 +315,7 @@
     if((rc = usb_release_interface(dh, dev->config->interface->altsetting->bInterfaceNumber))<0){
         puts("usb_release_interface error");
         usb_close(dh);
-        exit(5);
+        return(5);
     }
 
     usb_close(dh);
