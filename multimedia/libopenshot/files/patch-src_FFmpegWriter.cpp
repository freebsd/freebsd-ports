--- src/FFmpegWriter.cpp.orig	2025-12-16 05:34:48 UTC
+++ src/FFmpegWriter.cpp
@@ -167,7 +167,7 @@ void FFmpegWriter::SetVideoOptions(bool has_video, std
 		const AVCodec *new_codec;
 		// Check if the codec selected is a hardware accelerated codec
 #if USE_HW_ACCEL
-#if defined(__linux__)
+#if defined(__unix__)
 		if (strstr(codec.c_str(), "_vaapi") != NULL) {
 			new_codec = avcodec_find_encoder_by_name(codec.c_str());
 			hw_en_on = 1;
@@ -217,7 +217,7 @@ void FFmpegWriter::SetVideoOptions(bool has_video, std
 		}
 #else  // unknown OS
 		new_codec = avcodec_find_encoder_by_name(codec.c_str());
-#endif //__linux__/_WIN32/__APPLE__
+#endif //__unix__/_WIN32/__APPLE__
 #else // USE_HW_ACCEL
 		new_codec = avcodec_find_encoder_by_name(codec.c_str());
 #endif // USE_HW_ACCEL
@@ -558,6 +558,7 @@ void FFmpegWriter::SetOption(StreamType stream, std::s
 						else {
 							av_opt_set_int(c->priv_data, "crf", std::min(std::stoi(value),63), 0);
 						}
+						break;
 					case AV_CODEC_ID_HEVC :
 						c->bit_rate = 0;
 						if (strstr(info.vcodec.c_str(), "svt_hevc") != NULL) {
@@ -566,6 +567,8 @@ void FFmpegWriter::SetOption(StreamType stream, std::s
 							av_opt_set_int(c->priv_data, "forced-idr",1,0);
 						}
 						break;
+					default:
+						break;
 				}
 #endif  // FFmpeg 4.0+
 		} else {
@@ -1423,22 +1426,26 @@ void FFmpegWriter::open_video(AVFormatContext *oc, AVS
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
 		if( adapter_ptr != NULL ) {
+#else
+		if( adapter_ptr != NULL ) {
 #endif
 			ZmqLogger::Instance()->AppendDebugMethod(
 				"Encode Device present using device",
@@ -1500,7 +1507,7 @@ void FFmpegWriter::open_video(AVFormatContext *oc, AVS
 		switch (video_codec_ctx->codec_id) {
 			case AV_CODEC_ID_H264:
 				video_codec_ctx->max_b_frames = 0;  // At least this GPU doesn't support b-frames
-				video_codec_ctx->profile = FF_PROFILE_H264_BASELINE | FF_PROFILE_H264_CONSTRAINED;
+				video_codec_ctx->profile = AV_PROFILE_H264_BASELINE | AV_PROFILE_H264_CONSTRAINED;
 				av_opt_set(video_codec_ctx->priv_data, "preset", "slow", 0);
 				av_opt_set(video_codec_ctx->priv_data, "tune", "zerolatency", 0);
 				av_opt_set(video_codec_ctx->priv_data, "vprofile", "baseline", AV_OPT_SEARCH_CHILDREN);
@@ -2390,6 +2397,12 @@ void FFmpegWriter::AddSphericalMetadata(const std::str
 	map->pitch = static_cast<int32_t>(pitch_deg * (1 << 16));
 	map->roll  = static_cast<int32_t>(roll_deg  * (1 << 16));
 
+# if LIBAVFORMAT_VERSION_MAJOR >= 62
+	av_packet_side_data_add(
+		&video_st->codecpar->coded_side_data, &video_st->codecpar->nb_coded_side_data,
+		AV_PKT_DATA_SPHERICAL, reinterpret_cast<uint8_t*>(map), sd_size, 0);
+# else
 	av_stream_add_side_data(video_st, AV_PKT_DATA_SPHERICAL, reinterpret_cast<uint8_t*>(map), sd_size);
+# endif
 #endif
 }
