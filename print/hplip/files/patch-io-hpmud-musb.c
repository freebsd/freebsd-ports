--- ./io/hpmud/musb.c.orig	2012-11-20 09:55:09.000000000 +0000
+++ ./io/hpmud/musb.c	2012-12-07 21:32:31.615696389 +0000
@@ -135,10 +135,16 @@
 				0x409,
 				tbuf, sizeof(tbuf), LIBUSB_CONTROL_REQ_TIMEOUT);
 
-		if (ret==0)
+		if (ret==0
+#ifdef __FreeBSD__
+			|| ret == -EIO
+#endif
+		)
 		{
-			/* This retry is necessary for lj1000 and lj1005. des 12/12/07 */
-			BUG("get_string_descriptor zero result, retrying...");
+			/* This retry is necessary for lj1000 and lj1005. des 12/12/07
+			Also HP Photosmart 42xx seems to suffer transient errors with serial id */
+			BUG("get_string_descriptor error result %d, retrying in 2 secs...", ret);
+			sleep(2);
 			continue;
 		}
 		break;
