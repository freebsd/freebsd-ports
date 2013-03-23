--- ffmpeg/libavcodec/mpegaudio_parser.c.orig	2013-03-05 19:20:04.000000000 +0100
+++ ffmpeg/libavcodec/mpegaudio_parser.c	2013-03-08 18:28:59.428478324 +0100
@@ -81,6 +81,7 @@
                         avctx->sample_rate= sr;
                         avctx->channels   = channels;
                         s1->duration      = frame_size;
+                        avctx->frame_size = frame_size;
                         if (s->no_bitrate || !avctx->bit_rate) {
                             s->no_bitrate = 1;
                             avctx->bit_rate += (bit_rate - avctx->bit_rate) / s->header_count;
