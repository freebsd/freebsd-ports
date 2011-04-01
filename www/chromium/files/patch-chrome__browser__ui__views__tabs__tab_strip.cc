--- ./chrome/browser/ui/views/tabs/tab_strip.cc.orig	2010-12-16 02:11:56.000000000 +0100
+++ ./chrome/browser/ui/views/tabs/tab_strip.cc	2010-12-20 20:15:08.000000000 +0100
@@ -30,7 +30,7 @@
 #if defined(OS_WIN)
 #include "app/win_util.h"
 #include "views/widget/widget_win.h"
-#elif defined(OS_LINUX)
+#elif defined(TOOLKIT_GTK)
 #include "views/widget/widget_gtk.h"
 #endif
 
