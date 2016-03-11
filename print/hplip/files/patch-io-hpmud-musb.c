--- io/hpmud/musb.c.orig	2015-06-13 19:38:23 UTC
+++ io/hpmud/musb.c
@@ -138,10 +138,16 @@ static int get_string_descriptor(libusb_
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
