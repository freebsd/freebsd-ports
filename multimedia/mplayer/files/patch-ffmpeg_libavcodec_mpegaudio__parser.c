--- ffmpeg/libavcodec/mpegaudio_parser.c.orig	2015-06-19 20:44:40 UTC
+++ ffmpeg/libavcodec/mpegaudio_parser.c
@@ -84,6 +84,7 @@ static int mpegaudio_parse(AVCodecParser
                         avctx->sample_rate= sr;
                         avctx->channels   = channels;
                         s1->duration      = frame_size;
+                        avctx->frame_size = frame_size;
                         avctx->codec_id   = codec_id;
                         if (s->no_bitrate || !avctx->bit_rate) {
                             s->no_bitrate = 1;
