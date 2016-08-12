--- ui/views/style/platform_style.cc.orig	2016-07-22 00:07:12.000000000 -0400
+++ ui/views/style/platform_style.cc	2016-08-04 10:02:49.187133000 -0400
@@ -17,7 +17,7 @@
 #include "ui/views/controls/focusable_border.h"
 #include "ui/views/controls/scrollbar/native_scroll_bar.h"
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 #define DESKTOP_LINUX
 #endif
 
