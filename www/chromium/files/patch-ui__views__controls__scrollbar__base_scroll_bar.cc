--- ui/views/controls/scrollbar/base_scroll_bar.cc.orig	2015-04-14 18:19:00.000000000 -0400
+++ ui/views/controls/scrollbar/base_scroll_bar.cc	2015-04-28 08:04:31.469712000 -0400
@@ -24,7 +24,7 @@
 #include "ui/views/controls/scrollbar/base_scroll_bar_thumb.h"
 #include "ui/views/widget/widget.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/gfx/screen.h"
 #endif
 
