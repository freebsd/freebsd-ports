--- src/FFmpegWriter.cpp.orig	2022-12-01 22:04:03 UTC
+++ src/FFmpegWriter.cpp
@@ -166,7 +166,7 @@ void FFmpegWriter::SetVideoOptions(bool has_video, std
 		const AVCodec *new_codec;
 		// Check if the codec selected is a hardware accelerated codec
 #if USE_HW_ACCEL
-#if defined(__linux__)
+#if defined(__unix__)
 		if (strstr(codec.c_str(), "_vaapi") != NULL) {
 			new_codec = avcodec_find_encoder_by_name(codec.c_str());
 			hw_en_on = 1;
@@ -216,7 +216,7 @@ void FFmpegWriter::SetVideoOptions(bool has_video, std
 		}
 #else  // unknown OS
 		new_codec = avcodec_find_encoder_by_name(codec.c_str());
-#endif //__linux__/_WIN32/__APPLE__
+#endif //__unix__/_WIN32/__APPLE__
 #else // USE_HW_ACCEL
 		new_codec = avcodec_find_encoder_by_name(codec.c_str());
 #endif // USE_HW_ACCEL
@@ -563,6 +563,7 @@ void FFmpegWriter::SetOption(StreamType stream, std::s
 						else {
 							av_opt_set_int(c->priv_data, "crf", std::min(std::stoi(value),63), 0);
 						}
+						break;
 					case AV_CODEC_ID_HEVC :
 						c->bit_rate = 0;
 						if (strstr(info.vcodec.c_str(), "svt_hevc") != NULL) {
@@ -571,6 +572,8 @@ void FFmpegWriter::SetOption(StreamType stream, std::s
 							av_opt_set_int(c->priv_data, "forced-idr",1,0);
 						}
 						break;
+					default:
+						break;
 				}
 #endif  // FFmpeg 4.0+
 		} else {
@@ -1459,21 +1462,25 @@ void FFmpegWriter::open_video(AVFormatContext *oc, AVS
 		adapter_num = openshot::Settings::Instance()->HW_EN_DEVICE_SET;
 		std::clog << "Encoding Device Nr: " << adapter_num << "\n";
 		if (adapter_num < 3 && adapter_num >=0) {
-#if defined(__linux__)
+#if defined(__unix__)
 				snprintf(adapter,sizeof(adapter),"/dev/dri/renderD%d", adapter_num+128);
 				// Maybe 127 is better because the first card would be 1?!
 				adapter_ptr = adapter;
 #elif defined(_WIN32) || defined(__APPLE__)
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
 #elif defined(_WIN32) || defined(__APPLE__)
+		if( adapter_ptr != NULL ) {
+#else
 		if( adapter_ptr != NULL ) {
 #endif
 			ZmqLogger::Instance()->AppendDebugMethod(
