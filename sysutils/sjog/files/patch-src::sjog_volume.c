--- src/sjog_volume.c.orig	Sun Aug 12 23:17:33 2001
+++ src/sjog_volume.c	Sat Aug 17 20:38:56 2002
@@ -1,5 +1,9 @@
 #include <sys/ioctl.h>
+#ifdef __FreeBSD__
+#include <sys/soundcard.h>
+#else
 #include <linux/soundcard.h>
+#endif
 
 #include "sjog.h"
 #include "sjog_volume.h"
