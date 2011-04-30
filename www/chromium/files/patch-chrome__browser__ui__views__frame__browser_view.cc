--- chrome/browser/ui/views/frame/browser_view.cc.orig	2011-04-15 11:01:45.000000000 +0300
+++ chrome/browser/ui/views/frame/browser_view.cc	2011-04-16 18:06:47.910070832 +0300
@@ -4,7 +4,7 @@
 
 #include "chrome/browser/ui/views/frame/browser_view.h"
 
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_GTK)
 #include <gtk/gtk.h>
 #endif
 
@@ -90,7 +90,7 @@
 #include "chrome/browser/jumplist_win.h"
 #include "ui/base/message_box_win.h"
 #include "ui/base/view_prop.h"
-#elif defined(OS_LINUX)
+#elif defined(TOOLKIT_GTK)
 #include "chrome/browser/ui/views/accelerator_table_gtk.h"
 #include "views/window/hit_test.h"
 #include "views/window/window_gtk.h"
@@ -1162,7 +1162,7 @@
   string16 message = l10n_util::GetStringUTF16(message_id);
   ui::MessageBox(GetNativeHandle(), message, title,
                  MB_OK | MB_ICONWARNING | MB_TOPMOST);
-#elif defined(OS_LINUX)
+#elif defined(TOOLKIT_GTK)
   std::string title = l10n_util::GetStringUTF8(IDS_PRODUCT_NAME);
   std::string message = l10n_util::GetStringUTF8(message_id);
   GtkWidget* dialog = gtk_message_dialog_new(GetNativeHandle(),
@@ -1256,7 +1256,7 @@
   views::FocusManager* focus_manager = GetFocusManager();
   DCHECK(focus_manager);
 
-#if defined(OS_LINUX) && !defined(TOUCH_UI)
+#if (defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(TOUCH_UI)
   // Views and WebKit use different tables for GdkEventKey -> views::KeyEvent
   // conversion. We need to use View's conversion table here to keep consistent
   // behavior with views::FocusManager::OnKeyEvent() method.
@@ -1303,7 +1303,7 @@
     return false;
 
   // Executing the command may cause |this| object to be destroyed.
-#if defined(OS_LINUX) && !defined(TOUCH_UI)
+#if (defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(TOUCH_UI)
   if (browser_->IsReservedCommandOrKey(id, event) &&
       !event.match_edit_command) {
 #else
@@ -1320,7 +1320,7 @@
 }
 
 void BrowserView::HandleKeyboardEvent(const NativeWebKeyboardEvent& event) {
-#if defined(OS_LINUX) && !defined(TOUCH_UI)
+#if (defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(TOUCH_UI)
   views::Window* window = GetWidget()->GetWindow();
   if (window && event.os_event && !event.skip_in_browser)
     static_cast<views::WindowGtk*>(window)->HandleKeyboardEvent(event.os_event);
@@ -2247,7 +2247,7 @@
 #endif  // No need to invoke SetFullscreen for linux as this code is executed
         // once we're already fullscreen on linux.
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   // Updating of commands for fullscreen mode is called from SetFullScreen on
   // Wndows (see just above), but for ChromeOS, this method (ProcessFullScreen)
   // is called after full screen has happened successfully (via GTK's
