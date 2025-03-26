--- src/videofilters/ffmpegjpegwriter.c.orig	2025-03-19 09:21:16 UTC
+++ src/videofilters/ffmpegjpegwriter.c
@@ -211,6 +211,7 @@ static bool_t jpg_process_frame_task(void *obj) {
 		freemsg(jpegm);
 	}
 
+end:
 	freemsg(m);
 	return TRUE;
 }
