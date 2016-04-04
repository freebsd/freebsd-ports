--- io/hpmud/musb.c.orig	2016-02-08 09:42:51 UTC
+++ io/hpmud/musb.c
@@ -139,10 +139,16 @@ static int get_string_descriptor(libusb_
                 0x409,
                 tbuf, sizeof(tbuf), LIBUSB_CONTROL_REQ_TIMEOUT);
 
-        if (ret==0)
+        if (ret==0
+#ifdef __FreeBSD__
+          || ret == -EIO
+#endif
+        )
         {
-            /* This retry is necessary for lj1000 and lj1005. des 12/12/07 */
-            BUG("get_string_descriptor zero result, retrying...");
+            /* This retry is necessary for lj1000 and lj1005. des 12/12/07
+               Also HP Photosmart 42xx seems to suffer transient errors with serial id */
+            BUG("get_string_descriptor error result %d, retrying in 2 secs...", ret);
+            sleep(2);
             continue;
         }
         break;
@@ -385,7 +391,7 @@ static int detach(libusb_device_handle *
 {
     int ret ;
     /* If any kernel module has claimed this interface, detach it. */
-    ret = libusb_kernel_driver_active (hd, interface);
+    ret = 0;
     DBG("Active kernel driver on interface=%d ret=%d\n", interface, ret);
     if (ret == 1)
     {
