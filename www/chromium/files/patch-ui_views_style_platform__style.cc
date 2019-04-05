--- ui/views/style/platform_style.cc.orig	2019-03-11 22:01:19 UTC
+++ ui/views/style/platform_style.cc
@@ -18,7 +18,7 @@
 
 #if defined(OS_CHROMEOS)
 #include "ui/views/controls/scrollbar/overlay_scroll_bar.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #define DESKTOP_LINUX
 #endif
 
