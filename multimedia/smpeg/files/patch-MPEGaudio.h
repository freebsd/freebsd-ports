--- MPEGaudio.h.orig	2001-04-04 20:42:40 UTC
+++ MPEGaudio.h
@@ -148,6 +148,13 @@ class Mpegbitwindow (private)
   char buffer[2*WINDOWSIZE];
 };
 
+class MPEGaudio;
+	void Play_MPEGaudioSDL(void *udata, Uint8 *stream, int len);
+	int Play_MPEGaudio(MPEGaudio *audio, Uint8 *stream, int len);
+#ifdef THREADED_AUDIO
+	int Decode_MPEGaudio(void *udata);
+#endif
+
 /* The actual MPEG audio class */
 class MPEGaudio : public MPEGerror, public MPEGaudioaction {
 
