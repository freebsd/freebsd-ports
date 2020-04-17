--- lib/libv4lconvert/rgbyuv.c.orig	2020-04-09 16:29:54 UTC
+++ lib/libv4lconvert/rgbyuv.c
@@ -893,7 +893,7 @@ void v4lconvert_nv12_to_yuv420(const unsigned char *sr
 	}
 
 	for (i = 0; i < height; i++)
-		for (j = 0; i < width; j++) {
+		for (j = 0; j < width; j++) {
 			*ydst++ = *ysrc++;
 			if (((i % 2) == 0) && ((j % 2) == 0)) {
 				*udst++ = *uvsrc++;
