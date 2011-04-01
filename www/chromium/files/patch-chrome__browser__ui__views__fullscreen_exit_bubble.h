--- ./chrome/browser/ui/views/fullscreen_exit_bubble.h.orig	2010-12-16 02:11:56.000000000 +0100
+++ ./chrome/browser/ui/views/fullscreen_exit_bubble.h	2010-12-20 20:15:08.000000000 +0100
@@ -12,7 +12,7 @@
 #include "chrome/browser/command_updater.h"
 #include "views/controls/link.h"
 
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_GTK)
 namespace views {
 class WidgetGtk;
 }
@@ -76,7 +76,7 @@
   // The popup itself, which is a slightly modified WidgetWin.  We need to use
   // a WidgetWin (and thus an HWND) to make the popup float over other HWNDs.
   FullscreenExitPopup* popup_;
-#elif defined(OS_LINUX)
+#elif defined(TOOLKIT_GTK)
   views::WidgetGtk* popup_;
 #endif
 
