--- ffmpeg/libavcodec/mpegaudio_parser.c.orig	2014-02-12 19:20:06.000000000 +0100
+++ ffmpeg/libavcodec/mpegaudio_parser.c	2014-04-19 14:39:15.514132783 +0200
@@ -83,6 +83,7 @@
                         avctx->sample_rate= sr;
                         avctx->channels   = channels;
                         s1->duration      = frame_size;
+                        avctx->frame_size = frame_size;
                         avctx->codec_id   = codec_id;
                         if (s->no_bitrate || !avctx->bit_rate) {
                             s->no_bitrate = 1;
