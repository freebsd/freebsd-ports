--- ffmpeg/libavcodec/mpegaudio_parser.c.orig	2012-03-04 19:20:05.000000000 +0100
+++ ffmpeg/libavcodec/mpegaudio_parser.c	2012-05-01 14:57:54.645626270 +0200
@@ -78,7 +78,7 @@
                     if (s->header_count > 1) {
                         avctx->sample_rate= sr;
                         avctx->channels   = channels;
-                        s1->duration      = frame_size;
+                        avctx->frame_size = frame_size;
                         avctx->bit_rate   = bit_rate;
                     }
                     break;
