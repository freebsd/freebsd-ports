--- io/hpmud/musb.c.orig	2008-01-23 01:27:15.000000000 +0100
+++ io/hpmud/musb.c	2009-03-25 17:01:30.000000000 +0100
@@ -123,8 +123,10 @@
                0x409, tbuf, sizeof(tbuf), LIBUSB_CONTROL_REQ_TIMEOUT);
       if (ret==0)
       {
-         /* This retry is necessary for lj1000 and lj1005. des 12/12/07 */
-         BUG("get_string_descriptor zero result, retrying...");
+	 /* This retry is necessary for lj1000 and lj1005. des 12/12/07
+         Also HP Photosmart 42xx seems to suffer transient errors with serial id */
+         BUG("get_string_descriptor error result %d, retrying in 2 secs...", ret);
+         sleep(2);
          continue;
       }
       break;
