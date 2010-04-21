--- stream/tvi_v4l.c	2007-10-07 23:49:26.000000000 +0400
+++ stream/tvi_v4l.c	2010-01-27 13:42:17.781746063 +0300
@@ -48,6 +48,14 @@
 
 #include "audio_in.h"
 
+#include <libv4l1.h>
+#define open	v4l1_open
+#define close	v4l1_close
+#define dup	v4l1_dup
+#define ioctl	v4l1_ioctl
+#define mmap	v4l1_mmap
+#define munmap	v4l1_munmap
+
 static tvi_handle_t *tvi_init_v4l(tv_param_t* tv_param);
 
 tvi_info_t tvi_info_v4l = {
