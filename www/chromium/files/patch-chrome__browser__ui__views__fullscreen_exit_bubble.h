--- chrome/browser/ui/views/fullscreen_exit_bubble.h.orig	2011-05-06 12:03:37.000000000 +0300
+++ chrome/browser/ui/views/fullscreen_exit_bubble.h	2011-06-04 00:35:54.816403061 +0300
@@ -16,7 +16,7 @@
 class SlideAnimation;
 }
 
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_GTK)
 namespace views {
 class WidgetGtk;
 }
