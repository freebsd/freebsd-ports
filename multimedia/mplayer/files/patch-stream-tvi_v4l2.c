--- stream/tvi_v4l2.c	2007-10-07 23:49:26.000000000 +0400
+++ stream/tvi_v4l2.c	2010-01-27 13:25:47.000000000 +0300
@@ -38,7 +38,6 @@ known issues:
 #ifdef HAVE_SYS_SYSINFO_H
 #include <sys/sysinfo.h>
 #endif
-#include <linux/types.h>
 #include <linux/videodev2.h>
 #include "mp_msg.h"
 #include "libmpcodecs/img_format.h"
@@ -46,6 +46,14 @@ known issues:
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
