--- plugins/output_http/httpd.c.orig	2021-02-20 17:47:40 UTC
+++ plugins/output_http/httpd.c
@@ -37,18 +37,17 @@
 #include <errno.h>
 #include <limits.h>
 
-#include <linux/version.h>
 #include <linux/types.h>          /* for videodev2.h */
 #include <linux/videodev2.h>
 
+#include <netinet/in.h>
+
 #include "../../mjpg_streamer.h"
 #include "../../utils.h"
 
 #include "httpd.h"
 
-#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,32)
 #define V4L2_CTRL_TYPE_STRING_SUPPORTED
-#endif
 
 #include "../output_file/output_file.h"
 
