--- xa_audio.h.orig	1999-03-21 22:36:25 UTC
+++ xa_audio.h
@@ -139,7 +139,11 @@ extern xaULONG xa_forkit;
 #define _FILE_DSP "/dev/dsp"
 #define _FILE_MIXER "/dev/mixer"
 #ifdef __FreeBSD__
+#if __FreeBSD__ > 3
+#include <sys/soundcard.h>
+#else
 #include <machine/soundcard.h>
+#endif
 #else
 #include <sys/soundcard.h>
 #endif
