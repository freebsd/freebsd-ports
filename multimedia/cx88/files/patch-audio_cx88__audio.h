--- audio/cx88_audio.h.orig	2022-07-26 16:13:09 UTC
+++ audio/cx88_audio.h
@@ -127,9 +127,15 @@ extern driver_t cx88_pcm_driver;
 
 extern driver_t cx88_pcm_driver;
 
+#if __FreeBSD_version >= 1400058
 #define CX88_PCM_DRIVER_MODULE(host) \
+   DRIVER_MODULE(cx88pcm, host, cx88_pcm_driver, NULL, NULL); \
+   MODULE_DEPEND(host, sound, SOUND_MINVER, SOUND_PREFVER, SOUND_MAXVER);
+#else
+#define CX88_PCM_DRIVER_MODULE(host) \
    DRIVER_MODULE(cx88pcm, host, cx88_pcm_driver, pcm_devclass, NULL, NULL); \
    MODULE_DEPEND(host, sound, SOUND_MINVER, SOUND_PREFVER, SOUND_MAXVER);
+#endif
 
 int cx88_audio_setup(
    cx88_audio_softc *sc,
