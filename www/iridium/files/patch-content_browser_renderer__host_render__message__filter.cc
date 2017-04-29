--- content/browser/renderer_host/render_message_filter.cc.orig	2017-04-19 19:06:33 UTC
+++ content/browser/renderer_host/render_message_filter.cc
@@ -89,7 +89,7 @@
 #include "ui/accelerated_widget_mac/window_resize_helper_mac.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/linux_util.h"
 #include "base/threading/platform_thread.h"
 #endif
