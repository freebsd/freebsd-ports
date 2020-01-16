--- ui/views/widget/native_widget_aura.cc.orig	2019-12-17 20:00:27 UTC
+++ ui/views/widget/native_widget_aura.cc
@@ -59,7 +59,7 @@
 #include "ui/views/widget/desktop_aura/desktop_window_tree_host_win.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 #include "ui/views/linux_ui/linux_ui.h"
 #include "ui/views/widget/desktop_aura/desktop_window_tree_host_x11.h"
 #endif
@@ -1065,7 +1065,7 @@ void NativeWidgetAura::SetInitialFocus(ui::WindowShowS
 // Widget, public:
 
 namespace {
-#if defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 void CloseWindow(aura::Window* window) {
   if (window) {
     Widget* widget = Widget::GetWidgetForNativeView(window);
@@ -1095,13 +1095,13 @@ void Widget::CloseAllSecondaryWidgets() {
   EnumThreadWindows(GetCurrentThreadId(), WindowCallbackProc, 0);
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   DesktopWindowTreeHostLinux::CleanUpWindowList(CloseWindow);
 #endif
 }
 
 const ui::NativeTheme* Widget::GetNativeTheme() const {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   const LinuxUI* linux_ui = LinuxUI::instance();
   if (linux_ui) {
     ui::NativeTheme* native_theme =
