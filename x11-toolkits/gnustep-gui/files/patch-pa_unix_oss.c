--- Tools/gsnd/portaudio/pa_unix_oss/pa_unix_oss.c.orig	Wed Oct  2 05:34:54 2002
+++ Tools/gsnd/portaudio/pa_unix_oss/pa_unix_oss.c	Mon Dec  2 09:21:34 2002
@@ -110,7 +110,11 @@
 #ifdef __linux__
 #include <linux/soundcard.h>
 #else
+#ifdef __FreeBSD__
+#include <sys/soundcard.h>
+#else
 #include <machine/soundcard.h> /* JH20010905 */
+#endif
 #endif
 
 #include "portaudio.h"
