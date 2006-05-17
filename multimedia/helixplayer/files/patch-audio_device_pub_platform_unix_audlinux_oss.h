--- ./audio/device/pub/platform/unix/audlinux_oss.h.orig	Wed Sep 24 22:35:32 2003
+++ ./audio/device/pub/platform/unix/audlinux_oss.h	Fri May 21 16:43:25 2004
@@ -46,7 +46,7 @@
 #elif defined _NETBSD
 #include "soundcard.h"
 #elif defined _FREEBSD || defined __alpha || defined __sparc__
-#include "machine/soundcard.h"
+#include <sys/soundcard.h>
 #else 
 #include "machine/soundcard.h"
 #endif
