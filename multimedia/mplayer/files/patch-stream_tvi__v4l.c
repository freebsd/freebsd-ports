--- stream/tvi_v4l.c.orig	2013-03-17 22:47:17 UTC
+++ stream/tvi_v4l.c
@@ -65,6 +65,14 @@
 
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
 
 const tvi_info_t tvi_info_v4l = {
