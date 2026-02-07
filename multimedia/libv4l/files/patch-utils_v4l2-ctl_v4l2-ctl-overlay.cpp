diff --git utils/v4l2-ctl/v4l2-ctl-overlay.cpp utils/v4l2-ctl/v4l2-ctl-overlay.cpp
index 5493222dd..1f0a6f47f 100644
--- utils/v4l2-ctl/v4l2-ctl-overlay.cpp
+++ utils/v4l2-ctl/v4l2-ctl-overlay.cpp
@@ -1,10 +1,11 @@
 #include <array>
 #include <vector>
 
-#include <linux/fb.h>
-
 #include "v4l2-ctl.h"
 
+#ifndef __FreeBSD__
+#include <linux/fb.h>
+
 static unsigned int set_fbuf;
 static unsigned int set_overlay_fmt;
 static struct v4l2_format overlay_fmt;	/* set_format/get_format video overlay */
@@ -527,3 +528,24 @@ void overlay_list(cv4l_fd &fd)
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
