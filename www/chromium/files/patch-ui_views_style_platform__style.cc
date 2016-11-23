--- ui/views/style/platform_style.cc.orig	2016-08-03 22:02:41.000000000 +0300
+++ ui/views/style/platform_style.cc	2016-09-26 05:44:41.103708000 +0300
@@ -17,7 +17,7 @@
 #include "ui/views/controls/focusable_border.h"
 #include "ui/views/controls/scrollbar/native_scroll_bar.h"
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 #define DESKTOP_LINUX
 #endif
 
