--- pwc-v4l.c.orig	2006-06-07 22:15:52.000000000 +0200
+++ pwc-v4l.c	2009-05-27 20:22:49.137318240 +0200
@@ -67,7 +67,7 @@
 		{
 			struct video_capability *caps = arg;
 
-			strncpy(caps->name, pdev->name, sizeof(caps->name) - 1);
+			strncpy(caps->name, device_get_desc(pdev->sc_dev), sizeof(caps->name) - 1);
 			caps->name[sizeof(caps->name) - 1] = '\0';
 			caps->type = VID_TYPE_CAPTURE;
 			caps->channels = 1;
