--- chrome/browser/ui/views/frame/browser_view.cc.orig	2011-01-26 10:30:50.000000000 +0100
+++ chrome/browser/ui/views/frame/browser_view.cc	2011-01-30 14:10:27.000000000 +0100
@@ -4,7 +4,7 @@
 
 #include "chrome/browser/ui/views/frame/browser_view.h"
 
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_GTK)
 #include <gtk/gtk.h>
 #endif
 
@@ -87,7 +87,7 @@
 #include "chrome/browser/aeropeek_manager.h"
 #include "chrome/browser/jumplist_win.h"
 #include "ui/base/view_prop.h"
-#elif defined(OS_LINUX)
+#elif defined(TOOLKIT_GTK)
 #include "chrome/browser/ui/views/accelerator_table_gtk.h"
 #include "views/window/hit_test.h"
 #include "views/window/window_gtk.h"
@@ -1130,7 +1130,7 @@
   string16 message = l10n_util::GetStringUTF16(message_id);
   app::win::MessageBox(GetNativeHandle(), message, title,
                        MB_OK | MB_ICONWARNING | MB_TOPMOST);
-#elif defined(OS_LINUX)
+#elif defined(TOOLKIT_GTK)
   std::string title = l10n_util::GetStringUTF8(IDS_PRODUCT_NAME);
   std::string message = l10n_util::GetStringUTF8(message_id);
   GtkWidget* dialog = gtk_message_dialog_new(GetNativeHandle(),
@@ -1224,7 +1224,7 @@
   views::FocusManager* focus_manager = GetFocusManager();
   DCHECK(focus_manager);
 
-#if defined(OS_LINUX) && !defined(TOUCH_UI)
+#if (defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(TOUCH_UI)
   // Views and WebKit use different tables for GdkEventKey -> views::KeyEvent
   // conversion. We need to use View's conversion table here to keep consistent
   // behavior with views::FocusManager::OnKeyEvent() method.
@@ -1271,7 +1271,7 @@
     return false;
 
   // Executing the command may cause |this| object to be destroyed.
-#if defined(OS_LINUX) && !defined(TOUCH_UI)
+#if (defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(TOUCH_UI)
   if (browser_->IsReservedCommand(id) && !event.match_edit_command) {
 #else
   if (browser_->IsReservedCommand(id)) {
@@ -1287,7 +1287,7 @@
 }
 
 void BrowserView::HandleKeyboardEvent(const NativeWebKeyboardEvent& event) {
-#if defined(OS_LINUX) && !defined(TOUCH_UI)
+#if (defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(TOUCH_UI)
   views::Window* window = GetWidget()->GetWindow();
   if (window && event.os_event && !event.skip_in_browser)
     static_cast<views::WindowGtk*>(window)->HandleKeyboardEvent(event.os_event);
@@ -2230,7 +2230,7 @@
 #endif  // No need to invoke SetFullscreen for linux as this code is executed
         // once we're already fullscreen on linux.
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   // Updating of commands for fullscreen mode is called from SetFullScreen on
   // Wndows (see just above), but for ChromeOS, this method (ProcessFullScreen)
   // is called after full screen has happened successfully (via GTK's
