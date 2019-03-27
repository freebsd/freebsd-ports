--- src/3rdparty/chromium/ui/views/style/platform_style.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/ui/views/style/platform_style.cc
@@ -19,7 +19,7 @@
 
 #if defined(OS_CHROMEOS)
 #include "ui/views/controls/scrollbar/overlay_scroll_bar.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #define DESKTOP_LINUX
 #endif
 
