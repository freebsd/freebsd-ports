--- PLUGINS/src/dvbsddevice/dvbsdffdevice.c.orig
+++ PLUGINS/src/dvbsddevice/dvbsdffdevice.c
@@ -6,12 +6,16 @@
  * $Id: dvbsdffdevice.c 2.26 2010/01/30 10:05:23 kls Exp $
  */
 
+#include <stdint.h>
 #include "dvbsdffdevice.h"
 #include <errno.h>
 #include <limits.h>
 #include <linux/videodev2.h>
 #include <linux/dvb/audio.h>
 #include <linux/dvb/dmx.h>
+#ifdef __FreeBSD__
+typedef struct timespec __kernel_time_t;
+#endif
 #include <linux/dvb/video.h>
 #include <sys/ioctl.h>
 #include <sys/mman.h>
