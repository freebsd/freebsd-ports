--- MPEGaudio.h	Tue Mar 20 13:40:18 2007
+++ MPEGaudio.h	Tue Mar 20 13:43:04 2007
@@ -148,6 +148,13 @@
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
 
