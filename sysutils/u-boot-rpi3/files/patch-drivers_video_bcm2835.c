--- drivers/video/bcm2835.c.orig	2018-03-13 12:02:19 UTC
+++ drivers/video/bcm2835.c
@@ -49,6 +49,7 @@ static int bcm2835_video_probe(struct udevice *dev)
 
 static const struct udevice_id bcm2835_video_ids[] = {
 	{ .compatible = "brcm,bcm2835-hdmi" },
+	{ .compatible = "brcm,bcm2708-fb" },
 	{ }
 };
 
