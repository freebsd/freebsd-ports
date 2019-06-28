--- src/FFmpegWriter.cpp.orig	2019-05-08 19:16:50 UTC
+++ src/FFmpegWriter.cpp
@@ -166,7 +166,7 @@ void FFmpegWriter::SetVideoOptions(bool has_video, str
 		AVCodec *new_codec;
 		// Check if the codec selected is a hardware accelerated codec
 #if IS_FFMPEG_3_2
-		#if defined(__linux__)
+#if defined(__unix__)
 		if ( (strcmp(codec.c_str(),"h264_vaapi") == 0)) {
 			new_codec = avcodec_find_encoder_by_name(codec.c_str());
 			hw_en_on = 1;
@@ -225,7 +225,7 @@ void FFmpegWriter::SetVideoOptions(bool has_video, str
 		}
 #else  // is FFmpeg 3 but not linux
 		new_codec = avcodec_find_encoder_by_name(codec.c_str());
-#endif //__linux__
+#endif //__unix__
 #else // not ffmpeg 3
 		new_codec = avcodec_find_encoder_by_name(codec.c_str());
 #endif //IS_FFMPEG_3_2
@@ -888,7 +888,7 @@ void FFmpegWriter::close_video(AVFormatContext *oc, AV
 	AV_FREE_CONTEXT(video_codec);
 	video_codec = NULL;
 #if IS_FFMPEG_3_2
-	//  #if defined(__linux__)
+	//  #if defined(__unix__)
 		if (hw_en_on && hw_en_supported) {
 			if (hw_device_ctx) {
 				av_buffer_unref(&hw_device_ctx);
@@ -1290,7 +1290,7 @@ void FFmpegWriter::open_video(AVFormatContext *oc, AVS
 		adapter_num = openshot::Settings::Instance()->HW_EN_DEVICE_SET;
 		fprintf(stderr, "\n\nEncodiing Device Nr: %d\n", adapter_num);
 		if (adapter_num < 3 && adapter_num >=0) {
-#if defined(__linux__)
+#if defined(__unix__)
 				snprintf(adapter,sizeof(adapter),"/dev/dri/renderD%d", adapter_num+128);
 				// Maybe 127 is better because the first card would be 1?!
 				adapter_ptr = adapter;
@@ -1298,17 +1298,21 @@ void FFmpegWriter::open_video(AVFormatContext *oc, AVS
 				adapter_ptr = NULL;
 #elif defined(__APPLE__)
 				adapter_ptr = NULL;
+#else
+				adapter_ptr = NULL;
 #endif
 			}
 			else {
 				adapter_ptr = NULL; // Just to be sure
 			}
 // Check if it is there and writable
-#if defined(__linux__)
+#if defined(__unix__)
 		if( adapter_ptr != NULL && access( adapter_ptr, W_OK ) == 0 ) {
 #elif defined(_WIN32)
 		if( adapter_ptr != NULL ) {
 #elif defined(__APPLE__)
+		if( adapter_ptr != NULL ) {
+#else
 		if( adapter_ptr != NULL ) {
 #endif
 				ZmqLogger::Instance()->AppendDebugMethod("Encode Device present using device", "", -1, "", -1, "", -1, "", -1, "", -1, "", -1);
