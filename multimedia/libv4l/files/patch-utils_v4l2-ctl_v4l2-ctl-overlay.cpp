--- utils/v4l2-ctl/v4l2-ctl-overlay.cpp.orig	2020-05-21 11:22:05 UTC
+++ utils/v4l2-ctl/v4l2-ctl-overlay.cpp
@@ -14,11 +14,13 @@
 #include <dirent.h>
 #include <math.h>
 
-#include <linux/fb.h>
 #include <vector>
 
 #include "v4l2-ctl.h"
 
+#ifndef __FreeBSD__
+#include <linux/fb.h>
+
 static unsigned int set_fbuf;
 static unsigned int set_overlay_fmt;
 static struct v4l2_format overlay_fmt;	/* set_format/get_format video overlay */
@@ -546,3 +548,24 @@ void overlay_list(cv4l_fd &fd)
 	if (options[OptFindFb])
 		find_fb(fd.g_fd());
 }
+#else
+void overlay_usage(void)
+{
+}
+
+void overlay_cmd(int ch, char *optarg)
+{
+}
+
+void overlay_set(cv4l_fd &_fd)
+{
+}
+
+void overlay_get(cv4l_fd &_fd)
+{
+}
+
+void overlay_list(cv4l_fd &fd)
+{
+}
+#endif
