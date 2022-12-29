--- src/FFmpegReader.cpp.orig	2022-12-01 22:04:03 UTC
+++ src/FFmpegReader.cpp
@@ -130,7 +130,7 @@ static enum AVPixelFormat get_hw_dec_format(AVCodecCon
 
 	for (p = pix_fmts; *p != AV_PIX_FMT_NONE; p++) {
 		switch (*p) {
-#if defined(__linux__)
+#if defined(__unix__)
 			// Linux pix formats
 			case AV_PIX_FMT_VAAPI:
 				hw_de_av_pix_fmt_global = AV_PIX_FMT_VAAPI;
@@ -300,7 +300,7 @@ void FFmpegReader::Open() {
 					pCodecCtx->get_format = get_hw_dec_format;
 
 					if (adapter_num < 3 && adapter_num >=0) {
-#if defined(__linux__)
+#if defined(__unix__)
 						snprintf(adapter,sizeof(adapter),"/dev/dri/renderD%d", adapter_num+128);
 						adapter_ptr = adapter;
 						i_decoder_hw = openshot::Settings::Instance()->HARDWARE_DECODER;
@@ -363,11 +363,13 @@ void FFmpegReader::Open() {
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
