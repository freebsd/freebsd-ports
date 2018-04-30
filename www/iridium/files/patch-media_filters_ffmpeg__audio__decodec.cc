--- media/filters/ffmpeg_audio_decoder.cc.orig	2018-04-28 14:12:22.084504000 +0200
+++ media/filters/ffmpeg_audio_decoder.cc	2018-04-28 14:14:19.735316000 +0200
@@ -53,7 +53,7 @@
 // AVCodecContext.opaque to get the object reference in order to call
 // GetAudioBuffer() to do the actual allocation.
 static int GetAudioBuffer(struct AVCodecContext* s, AVFrame* frame, int flags) {
-  DCHECK(s->codec->capabilities & CODEC_CAP_DR1);
+  DCHECK(s->codec->capabilities & AV_CODEC_CAP_DR1);
   DCHECK_EQ(s->codec_type, AVMEDIA_TYPE_AUDIO);
 
   // Since this routine is called by FFmpeg when a buffer is required for audio
