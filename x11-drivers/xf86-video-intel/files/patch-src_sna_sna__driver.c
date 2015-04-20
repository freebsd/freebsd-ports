--- src/sna/sna_driver.c.orig	2015-03-05 09:44:44 UTC
+++ src/sna/sna_driver.c
@@ -769,6 +769,7 @@ static Bool sna_late_close_screen(CLOSE_
 	DBG(("%s\n", __FUNCTION__));
 
 	sna_accel_close(sna);
+	sna_video_close(sna);
 
 	depths = screen->allowedDepths;
 	for (d = 0; d < screen->numDepths; d++)
