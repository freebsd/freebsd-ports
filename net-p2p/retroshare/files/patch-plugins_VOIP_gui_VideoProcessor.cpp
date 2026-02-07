--- plugins/VOIP/gui/VideoProcessor.cpp.orig	2016-02-05 19:04:46 UTC
+++ plugins/VOIP/gui/VideoProcessor.cpp
@@ -3,7 +3,7 @@
 #ifdef __MACH__
 #include <malloc/malloc.h>
 #else
-#include <malloc.h>
+#include <stdlib.h>
 #endif
 
 #include <QByteArray>
@@ -737,7 +737,8 @@ bool FFmpegVideo::decodeData(const RsVOI
 	//Mac OS X appears to be 16-byte mem aligned.
 	unsigned char *tmp = (unsigned char*)malloc(s + AV_INPUT_BUFFER_PADDING_SIZE) ;
 #else //MAC
-	unsigned char *tmp = (unsigned char*)memalign(16, s + AV_INPUT_BUFFER_PADDING_SIZE) ;
+	unsigned char *tmp ;
+	int unused_error = posix_memalign((void **)tmp, 16, s + AV_INPUT_BUFFER_PADDING_SIZE) ;
 #endif //MAC
 #endif //MINGW
 	if (tmp == NULL) {
