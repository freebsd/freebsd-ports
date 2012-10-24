--- stream/tvi_v4l2.c~	2012-05-10 23:45:22.000000000 -0500
+++ stream/tvi_v4l2.c	2012-05-11 00:08:34.930938536 -0500
@@ -52,7 +52,6 @@ known issues:
 #ifdef HAVE_SYS_VIDEOIO_H
 #include <sys/videoio.h>
 #else
-#include <linux/types.h>
 #include <linux/videodev2.h>
 #endif
 #include "mp_msg.h"
@@ -62,6 +61,14 @@ known issues:
 #include "tv.h"
 #include "audio_in.h"
 
+#include <libv4l2.h>
+#define open	v4l2_open
+#define close	v4l2_close
+#define dup	v4l2_dup
+#define ioctl	v4l2_ioctl
+#define mmap	v4l2_mmap
+#define munmap	v4l2_munmap
+
 #define info tvi_info_v4l2
 static tvi_handle_t *tvi_init_v4l2(tv_param_t* tv_param);
 /* information about this file */
