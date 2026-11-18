--- drivers/video/bcm2835.c.orig	2026-10-05 21:35:33 UTC
+++ drivers/video/bcm2835.c
@@ -24,7 +24,7 @@ static int bcm2835_video_probe(struct udevice *dev)
 		return -EIO;
 
 	debug("bcm2835: Setting up display for %d x %d\n", w, h);
-	ret = bcm2835_set_video_params(&w, &h, 32, BCM2835_MBOX_PIXEL_ORDER_RGB,
+	ret = bcm2835_set_video_params(&w, &h, 32, BCM2835_MBOX_PIXEL_ORDER_BGR,
 				       BCM2835_MBOX_ALPHA_MODE_IGNORED,
 				       &fb_base, &fb_size, &pitch);
 	if (ret)
