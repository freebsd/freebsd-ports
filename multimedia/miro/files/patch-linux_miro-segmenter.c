--- linux/miro-segmenter.c.orig	2013-04-05 16:02:42 UTC
+++ linux/miro-segmenter.c
@@ -25,6 +25,10 @@
 #include <sys/types.h>
 #include <sys/socket.h>
 
+#ifdef __FreeBSD__
+#include <netinet/in.h>
+#endif
+
 #include <arpa/inet.h>
 
 #include <errno.h>
@@ -74,7 +78,11 @@ static AVStream *add_output_stream(AVFor
             output_codec_context->sample_rate = input_codec_context->sample_rate;
             output_codec_context->channels = input_codec_context->channels;
             output_codec_context->frame_size = input_codec_context->frame_size;
+#if LIBAVCODEC_VERSION_INT < AV_VERSION_INT(54, 25, 0)
             if ((input_codec_context->block_align == 1 && input_codec_context->codec_id == CODEC_ID_MP3) || input_codec_context->codec_id == CODEC_ID_AC3) {
+#else
+            if ((input_codec_context->block_align == 1 && input_codec_context->codec_id == AV_CODEC_ID_MP3) || input_codec_context->codec_id == AV_CODEC_ID_AC3) {
+#endif
                 output_codec_context->block_align = 0;
             }
             else {
@@ -92,7 +100,11 @@ static AVStream *add_output_stream(AVFormatContext *ou
             output_codec_context->has_b_frames = input_codec_context->has_b_frames;
 
             if (output_format_context->oformat->flags & AVFMT_GLOBALHEADER) {
+#if LIBAVCODEC_VERSION_MAJOR > 57
+                output_codec_context->flags |= AV_CODEC_FLAG_GLOBAL_HEADER;
+#else
                 output_codec_context->flags |= CODEC_FLAG_GLOBAL_HEADER;
+#endif
             }
             break;
     default:
@@ -259,10 +271,18 @@ int main(int argc, char **argv)
 #else
         if (packet.stream_index == video_index && (packet.flags & PKT_FLAG_KEY)) {
 #endif
+#if LIBAVFORMAT_VERSION_INT >= AV_VERSION_INT(55,40,100)
+            segment_time = (double)av_stream_get_end_pts(video_st) * video_st->time_base.num / video_st->time_base.den;
+#else
             segment_time = (double)video_st->pts.val * video_st->time_base.num / video_st->time_base.den;
+#endif
         }
         else if (video_index < 0) {
+#if LIBAVFORMAT_VERSION_INT >= AV_VERSION_INT(55,40,100)
+            segment_time = (double)av_stream_get_end_pts(audio_st) * audio_st->time_base.num / audio_st->time_base.den;
+#else
             segment_time = (double)audio_st->pts.val * audio_st->time_base.num / audio_st->time_base.den;
+#endif
         }
         else {
             segment_time = prev_segment_time;
