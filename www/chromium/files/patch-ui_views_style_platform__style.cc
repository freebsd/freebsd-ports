--- ui/views/style/platform_style.cc.orig	2017-03-09 20:04:49 UTC
+++ ui/views/style/platform_style.cc
@@ -19,7 +19,7 @@
 
 #if defined(OS_CHROMEOS)
 #include "ui/views/controls/scrollbar/overlay_scroll_bar.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #define DESKTOP_LINUX
 #endif
 
