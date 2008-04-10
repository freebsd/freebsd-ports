--- nxesd/audio_oss.c.orig	Wed Aug 18 12:01:41 2004
+++ nxesd/audio_oss.c
@@ -11,11 +11,6 @@
 #endif
 
 
-/* FreeBSD uses a different identifier? what other BSDs? */
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
-#define SNDCTL_DSP_SETDUPLEX DSP_CAP_DUPLEX
-#endif
-
 #define ARCH_esd_audio_devices
 const char *esd_audio_devices()
 {
