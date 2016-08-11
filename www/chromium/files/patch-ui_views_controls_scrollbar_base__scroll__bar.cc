--- ui/views/controls/scrollbar/base_scroll_bar.cc.orig	2016-05-11 19:02:36 UTC
+++ ui/views/controls/scrollbar/base_scroll_bar.cc
@@ -24,7 +24,7 @@
 #include "ui/views/controls/scrollbar/base_scroll_bar_thumb.h"
 #include "ui/views/widget/widget.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/gfx/screen.h"
 #endif
 
