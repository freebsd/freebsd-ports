--- audio_oss.c.orig	Sun Sep  7 22:30:57 2003
+++ audio_oss.c	Sun Sep  7 22:31:10 2003
@@ -15,7 +15,7 @@
 #ifndef __FreeBSD__
 #include <linux/soundcard.h>
 #else
-#include <machine/soundcard.h>
+#include <sys/soundcard.h>
 #define SNDCTL_DSP_CHANNELS SNDCTL_DSP_STEREO
 #endif
 
