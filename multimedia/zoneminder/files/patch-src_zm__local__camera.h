--- src/zm_local_camera.h.orig 2016-06-07 07:18:44 UTC
+++ src/zm_local_camera.h
@@ -36,6 +36,11 @@
 #include <linux/videodev2.h>
 #endif // HAVE_LINUX_VIDEODEV2_H

+// Required on systems with v4l1 but without v4l2 headers
+#ifndef VIDEO_MAX_FRAME
+#define VIDEO_MAX_FRAME	32
+#endif
+
 #include "zm_ffmpeg.h"

 //
