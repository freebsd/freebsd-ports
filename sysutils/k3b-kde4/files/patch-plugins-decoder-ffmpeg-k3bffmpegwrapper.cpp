--- plugins/decoder/ffmpeg/k3bffmpegwrapper.cpp.orig	2009-08-15 21:28:47.344449975 +0200
+++ plugins/decoder/ffmpeg/k3bffmpegwrapper.cpp	2009-08-15 21:30:16.985967181 +0200
@@ -31,6 +31,9 @@
 #define FFMPEG_BUILD_PRE_4629
 #endif
 
+#ifndef CODEC_ID_MP3LAME
+#define CODEC_ID_MP3LAME CODEC_ID_MP3
+#endif
 
 K3bFFMpegWrapper* K3bFFMpegWrapper::s_instance = 0;
 
@@ -290,7 +293,7 @@
 #ifdef FFMPEG_BUILD_PRE_4629
     int len = avcodec_decode_audio( &d->formatContext->streams[0]->codec,
 #else
-    int len = avcodec_decode_audio( d->formatContext->streams[0]->codec,
+    int len = avcodec_decode_audio2( d->formatContext->streams[0]->codec,
 #endif
 				    (short*)d->outputBuffer, &d->outputBufferSize,
 				    d->packetData, d->packetSize );
