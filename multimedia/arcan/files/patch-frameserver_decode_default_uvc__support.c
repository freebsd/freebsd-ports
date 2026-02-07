--- frameserver/decode/default/uvc_support.c.orig	2025-12-26 22:39:35 UTC
+++ frameserver/decode/default/uvc_support.c
@@ -141,7 +141,7 @@ static void frame_ffmpeg(
 	if (!codec){
 		codec = avcodec_find_decoder(fmt);
 		if (!codec){
-			LOG("status=error:fatal:kind=missing:message=no %s support", fmtstr);
+			//LOG("status=error:fatal:kind=missing:message=no %s support", fmtstr);
 			arcan_shmif_last_words(cont, "ffmpeg no matching codec");
 			arcan_shmif_drop(cont);
 			exit(EXIT_FAILURE);
@@ -151,7 +151,7 @@ static void frame_ffmpeg(
 		frame = av_frame_alloc();
 		packet = av_packet_alloc();
 		if (avcodec_open2(decode, codec, NULL) < 0){
-			LOG("status=error:fatal:kind=codec_fail:message=codec failed open");
+			//LOG("status=error:fatal:kind=codec_fail:message=codec failed open");
 			arcan_shmif_drop(cont);
 			exit(EXIT_FAILURE);
 		}
@@ -167,7 +167,7 @@ static void frame_ffmpeg(
 		);
 
 		if (ret < 0){
-			LOG("status=error:fatal:kind=ebad:message=%s parser failed", fmtstr);
+			//LOG("status=error:fatal:kind=ebad:message=%s parser failed", fmtstr);
 			arcan_shmif_last_words(cont, "ffmpeg parser error");
 			arcan_shmif_drop(cont);
 			exit(EXIT_FAILURE);
@@ -206,7 +206,7 @@ decode_fail:
 	return;
 
 decode_fail:
-	LOG("status=error:fatal:kind=ebad:message=%s decoder failed", fmtstr);
+	//LOG("status=error:fatal:kind=ebad:message=%s decoder failed", fmtstr);
 	arcan_shmif_last_words(cont, "ffmpeg decoder error");
 	arcan_shmif_drop(cont);
 	exit(EXIT_FAILURE);
@@ -247,7 +247,7 @@ static void callback(uvc_frame_t* frame, void* tag)
 			arcan_shmif_substruct(cont, SHMIF_META_VENC).venc;
 		if (!venc){
 			h264_passthrough = false;
-			LOG("status=feature:h264_passthrough=false");
+			//LOG("status=feature:h264_passthrough=false");
 		}
 /* sanity-check fail, revert to normal */
 		else {
@@ -262,7 +262,7 @@ static void callback(uvc_frame_t* frame, void* tag)
 				venc->fourcc[3] = '4';
 
 				venc->framesize = frame->data_bytes;
-				LOG("status=frame:h264_passthrough=true:size=%zu", (size_t) frame->data_bytes);
+				//LOG("status=frame:h264_passthrough=true:size=%zu", (size_t) frame->data_bytes);
 				memcpy(cont->vidb, frame->data, venc->framesize);
 				arcan_shmif_signal(cont, SHMIF_SIGVID);
 				return;
@@ -294,7 +294,8 @@ static void callback(uvc_frame_t* frame, void* tag)
 	break;
 /* h264 and mjpeg should map into ffmpeg as well */
 	default:
-		LOG("unhandled frame format: %d\n", (int)frame->frame_format);
+		//LOG("unhandled frame format: %d\n", (int)frame->frame_format);
+		;;
 	break;
 	}
 }
