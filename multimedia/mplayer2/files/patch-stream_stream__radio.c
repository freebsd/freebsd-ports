--- stream/stream_radio.c.orig	2015-08-26 13:37:17 UTC
+++ stream/stream_radio.c
@@ -40,17 +40,12 @@
 #ifdef IOCTL_BT848_H_NAME
 #include IOCTL_BT848_H_NAME
 #endif
-
-#else /* CONFIG_RADIO_BSDBT848 */
-
-#include <linux/types.h>
+#endif
 
 #ifdef CONFIG_RADIO_V4L2
 #include <linux/videodev2.h>
 #endif
 
-#endif // !IOCTL_BT848_H_NAME
-
 
 #include "stream.h"
 #include "libmpdemux/demuxer.h"
