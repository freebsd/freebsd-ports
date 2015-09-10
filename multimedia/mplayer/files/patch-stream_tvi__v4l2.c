--- stream/tvi_v4l2.c.orig	2014-06-10 16:39:04 UTC
+++ stream/tvi_v4l2.c
@@ -53,7 +53,6 @@ known issues:
 #ifdef HAVE_SYS_VIDEOIO_H
 #include <sys/videoio.h>
 #else
-#include <linux/types.h>
 #include <linux/videodev2.h>
 #endif
 #include "mp_msg.h"
@@ -68,6 +67,14 @@ known issues:
 #define V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC 0x2000
 #endif
 
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
