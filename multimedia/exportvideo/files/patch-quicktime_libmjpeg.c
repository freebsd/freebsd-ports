--- quicktime/libmjpeg.c.orig	Mon Feb 12 22:35:41 2001
+++ quicktime/libmjpeg.c	Mon Nov  1 19:40:00 2004
@@ -569,6 +569,7 @@
 	jpeg_finish_decompress(&engine->jpeg_decompress);
 //printf("decompress_field 5\n");
 finish:
+	;
 }
 
 void mjpeg_decompress_loop(mjpeg_compressor *engine)
