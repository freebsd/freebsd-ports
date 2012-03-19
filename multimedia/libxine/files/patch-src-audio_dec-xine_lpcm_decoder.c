--- src/audio_dec/xine_lpcm_decoder.c.orig
+++ src/audio_dec/xine_lpcm_decoder.c
@@ -30,6 +30,9 @@
 #endif
 /* avoid compiler warnings */
 #define _BSD_SOURCE 1
+#ifdef __FreeBSD__
+#define __BSD_VISIBLE 1
+#endif
 
 #ifdef HAVE_CONFIG_H
 #include "config.h"
