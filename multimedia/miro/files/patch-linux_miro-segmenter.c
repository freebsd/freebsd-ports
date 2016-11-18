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
