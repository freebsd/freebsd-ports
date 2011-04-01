--- ./chrome/browser/ui/views/tabs/dragged_tab_view.cc.orig	2010-12-16 02:11:56.000000000 +0100
+++ ./chrome/browser/ui/views/tabs/dragged_tab_view.cc	2010-12-20 20:15:08.000000000 +0100
@@ -11,7 +11,7 @@
 
 #if defined(OS_WIN)
 #include "views/widget/widget_win.h"
-#elif defined(OS_LINUX)
+#elif defined(TOOLKIT_GTK)
 #include "views/widget/widget_gtk.h"
 #endif
 
