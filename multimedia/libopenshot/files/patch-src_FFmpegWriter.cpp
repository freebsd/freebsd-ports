--- src/FFmpegWriter.cpp.orig	2020-06-18 10:04:32 UTC
+++ src/FFmpegWriter.cpp
@@ -172,7 +172,7 @@ void FFmpegWriter::SetVideoOptions(bool has_video, std
 		AVCodec *new_codec;
 		// Check if the codec selected is a hardware accelerated codec
 #if HAVE_HW_ACCEL
-#if defined(__linux__)
+#if defined(__unix__)
 		if (strstr(codec.c_str(), "_vaapi") != NULL) {
 			new_codec = avcodec_find_encoder_by_name(codec.c_str());
 			hw_en_on = 1;
@@ -220,9 +220,9 @@ void FFmpegWriter::SetVideoOptions(bool has_video, std
 			hw_en_on = 0;
 			hw_en_supported = 0;
 		}
-	#else  // is FFmpeg 3 but not linux
+#else  // is FFmpeg 3 but not unix
 		new_codec = avcodec_find_encoder_by_name(codec.c_str());
-	#endif //__linux__
+#endif //__unix__
 #else // not ffmpeg 3
 		new_codec = avcodec_find_encoder_by_name(codec.c_str());
 #endif // HAVE_HW_ACCEL
@@ -554,6 +554,7 @@ void FFmpegWriter::SetOption(StreamType stream, std::s
 						else {
 							av_opt_set_int(c->priv_data, "crf", std::min(std::stoi(value),63), 0);
 						}
+						break;
 					case AV_CODEC_ID_HEVC :
 						c->bit_rate = 0;
 						if (strstr(info.vcodec.c_str(), "svt_hevc") != NULL) {
@@ -562,6 +563,8 @@ void FFmpegWriter::SetOption(StreamType stream, std::s
 							av_opt_set_int(c->priv_data, "forced-idr",1,0);
 						}
 						break;
+					default:
+						break;
 				}
 #endif
 		} else {
@@ -1447,7 +1450,7 @@ void FFmpegWriter::open_video(AVFormatContext *oc, AVS
 		adapter_num = openshot::Settings::Instance()->HW_EN_DEVICE_SET;
 		fprintf(stderr, "\n\nEncodiing Device Nr: %d\n", adapter_num);
 		if (adapter_num < 3 && adapter_num >=0) {
-#if defined(__linux__)
+#if defined(__unix__)
 				snprintf(adapter,sizeof(adapter),"/dev/dri/renderD%d", adapter_num+128);
 				// Maybe 127 is better because the first card would be 1?!
 				adapter_ptr = adapter;
@@ -1455,17 +1458,21 @@ void FFmpegWriter::open_video(AVFormatContext *oc, AVS
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
 				ZmqLogger::Instance()->AppendDebugMethod("Encode Device present using device", "adapter", adapter_num);
