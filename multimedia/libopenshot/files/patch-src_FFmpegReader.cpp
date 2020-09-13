--- src/FFmpegReader.cpp.orig	2020-09-11 02:37:02 UTC
+++ src/FFmpegReader.cpp
@@ -165,7 +165,7 @@ static enum AVPixelFormat get_hw_dec_format(AVCodecCon
 
 	for (p = pix_fmts; *p != AV_PIX_FMT_NONE; p++) {
 		switch (*p) {
-#if defined(__linux__)
+#if defined(__unix__)
 			// Linux pix formats
 			case AV_PIX_FMT_VAAPI:
 				hw_de_av_pix_fmt_global = AV_PIX_FMT_VAAPI;
@@ -321,7 +321,7 @@ void FFmpegReader::Open() {
 					pCodecCtx->get_format = get_hw_dec_format;
 
 					if (adapter_num < 3 && adapter_num >=0) {
-#if defined(__linux__)
+#if defined(__unix__)
 						snprintf(adapter,sizeof(adapter),"/dev/dri/renderD%d", adapter_num+128);
 						adapter_ptr = adapter;
 						i_decoder_hw = openshot::Settings::Instance()->HARDWARE_DECODER;
@@ -384,11 +384,13 @@ void FFmpegReader::Open() {
 					}
 
 					// Check if it is there and writable
-#if defined(__linux__)
+#if defined(__unix__)
 					if( adapter_ptr != NULL && access( adapter_ptr, W_OK ) == 0 ) {
 #elif defined(_WIN32)
 					if( adapter_ptr != NULL ) {
 #elif defined(__APPLE__)
+					if( adapter_ptr != NULL ) {
+#else
 					if( adapter_ptr != NULL ) {
 #endif
 						ZmqLogger::Instance()->AppendDebugMethod("Decode Device present using device");
