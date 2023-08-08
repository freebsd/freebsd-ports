--- src/videofilters/ffmpegjpegwriter.c.orig	2023-07-28 18:41:49 UTC
+++ src/videofilters/ffmpegjpegwriter.c
@@ -213,6 +213,7 @@ static void jpg_process_frame_task(void *obj) {
 		freemsg(jpegm);
 	}
 
+end:
 	freemsg(m);
 }
 
