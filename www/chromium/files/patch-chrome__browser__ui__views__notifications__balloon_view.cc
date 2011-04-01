--- ./chrome/browser/ui/views/notifications/balloon_view.cc.orig	2010-12-16 02:11:56.000000000 +0100
+++ ./chrome/browser/ui/views/notifications/balloon_view.cc	2010-12-20 20:15:08.000000000 +0100
@@ -39,7 +39,7 @@
 #if defined(OS_WIN)
 #include "views/widget/widget_win.h"
 #endif
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_GTK)
 #include "views/widget/widget_gtk.h"
 #endif
 
