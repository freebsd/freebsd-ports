--- chrome/browser/ui/views/frame/browser_view.cc.orig	2011-05-06 12:03:37.000000000 +0300
+++ chrome/browser/ui/views/frame/browser_view.cc	2011-06-04 00:29:37.489403401 +0300
@@ -4,7 +4,7 @@
 
 #include "chrome/browser/ui/views/frame/browser_view.h"
 
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_GTK)
 #include <gtk/gtk.h>
 #endif
 
@@ -97,7 +97,7 @@
 #include "ui/base/message_box_win.h"
 #include "ui/base/view_prop.h"
 #include "views/window/window_win.h"
-#elif defined(OS_LINUX)
+#elif defined(TOOLKIT_GTK)
 #include "chrome/browser/ui/views/accelerator_table_gtk.h"
 #include "views/window/hit_test.h"
 #include "views/window/window_gtk.h"
@@ -1079,7 +1079,7 @@
   views::FocusManager* focus_manager = GetFocusManager();
   DCHECK(focus_manager);
 
-#if defined(OS_LINUX) && !defined(TOUCH_UI)
+#if (defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(TOUCH_UI)
   // Views and WebKit use different tables for GdkEventKey -> views::KeyEvent
   // conversion. We need to use View's conversion table here to keep consistent
   // behavior with views::FocusManager::OnKeyEvent() method.
@@ -1126,7 +1126,7 @@
     return false;
 
   // Executing the command may cause |this| object to be destroyed.
-#if defined(OS_LINUX) && !defined(TOUCH_UI)
+#if (defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(TOUCH_UI)
   if (browser_->IsReservedCommandOrKey(id, event) &&
       !event.match_edit_command) {
 #else
@@ -1143,7 +1143,7 @@
 }
 
 void BrowserView::HandleKeyboardEvent(const NativeWebKeyboardEvent& event) {
-#if defined(OS_LINUX) && !defined(TOUCH_UI)
+#if (defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(TOUCH_UI)
   views::Window* window = GetWidget()->GetWindow();
   if (window && event.os_event && !event.skip_in_browser) {
     views::KeyEvent views_event(reinterpret_cast<GdkEvent*>(event.os_event));
@@ -2135,7 +2135,7 @@
 #endif  // No need to invoke SetFullscreen for linux as this code is executed
         // once we're already fullscreen on linux.
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   // Updating of commands for fullscreen mode is called from SetFullScreen on
   // Wndows (see just above), but for ChromeOS, this method (ProcessFullScreen)
   // is called after full screen has happened successfully (via GTK's
