--- Tools/gsnd/portaudio/pa_unix_oss/pa_unix_oss.c.orig	Wed Oct  2 05:34:54 2002
+++ Tools/gsnd/portaudio/pa_unix_oss/pa_unix_oss.c	Sun Jan  5 05:33:48 2003
@@ -95,7 +95,9 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#ifndef __FreeBSD__
 #include <malloc.h>
+#endif
 #include <memory.h>
 #include <math.h>
 #include <sys/ioctl.h>
@@ -110,7 +112,11 @@
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
