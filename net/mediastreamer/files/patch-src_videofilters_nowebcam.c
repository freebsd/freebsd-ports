videofilters/nowebcam.c:251:49: error: use of undeclared identifier 'FF_INPUT_BUFFER_PADDING_SIZE'
                jpgbuf=(uint8_t*)ms_malloc0(statbuf.st_size + FF_INPUT_BUFFER_PADDING_SIZE);
                                                              ^

--- src/videofilters/nowebcam.c.orig	2016-08-18 14:17:37 UTC
+++ src/videofilters/nowebcam.c
@@ -32,7 +32,7 @@ Foundation, Inc., 59 Temple Place - Suite 330, Boston,
 #ifndef NO_FFMPEG
 #include "ffmpeg-priv.h"
 #else
-#define FF_INPUT_BUFFER_PADDING_SIZE 32
+#define AV_INPUT_BUFFER_PADDING_SIZE 32
 #endif
 
 #if TARGET_OS_IPHONE
@@ -248,7 +248,7 @@ static mblk_t *_ms_load_jpeg_as_yuv(const char *jpgpat
 			ms_error("Cannot load %s",jpgpath);
 			return NULL;
 		}
-		jpgbuf=(uint8_t*)ms_malloc0(statbuf.st_size + FF_INPUT_BUFFER_PADDING_SIZE);
+		jpgbuf=(uint8_t*)ms_malloc0(statbuf.st_size + AV_INPUT_BUFFER_PADDING_SIZE);
 		if (jpgbuf==NULL)
 		{
 			close(fd);
