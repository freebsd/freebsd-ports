--- ui/views/widget/native_widget_aura.cc.orig	2020-07-07 21:58:19 UTC
+++ ui/views/widget/native_widget_aura.cc
@@ -64,7 +64,7 @@
 #include "ui/views/widget/desktop_aura/desktop_window_tree_host_win.h"
 #endif
 
-#if BUILDFLAG(ENABLE_DESKTOP_AURA) && defined(OS_LINUX)
+#if BUILDFLAG(ENABLE_DESKTOP_AURA) && (defined(OS_LINUX) || defined(OS_BSD))
 #include "ui/views/linux_ui/linux_ui.h"
 #include "ui/views/widget/desktop_aura/desktop_window_tree_host_linux.h"
 #endif
@@ -1072,7 +1072,7 @@ void NativeWidgetAura::SetInitialFocus(ui::WindowShowS
 // Widget, public:
 
 namespace {
-#if BUILDFLAG(ENABLE_DESKTOP_AURA) && (defined(OS_WIN) || defined(OS_LINUX))
+#if BUILDFLAG(ENABLE_DESKTOP_AURA) && (defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD))
 void CloseWindow(aura::Window* window) {
   if (window) {
     Widget* widget = Widget::GetWidgetForNativeView(window);
@@ -1102,13 +1102,13 @@ void Widget::CloseAllSecondaryWidgets() {
   EnumThreadWindows(GetCurrentThreadId(), WindowCallbackProc, 0);
 #endif
 
-#if BUILDFLAG(ENABLE_DESKTOP_AURA) && defined(OS_LINUX)
+#if BUILDFLAG(ENABLE_DESKTOP_AURA) && (defined(OS_LINUX) || defined(OS_BSD))
   DesktopWindowTreeHostLinux::CleanUpWindowList(CloseWindow);
 #endif
 }
 
 const ui::NativeTheme* Widget::GetNativeTheme() const {
-#if BUILDFLAG(ENABLE_DESKTOP_AURA) && defined(OS_LINUX)
+#if BUILDFLAG(ENABLE_DESKTOP_AURA) && (defined(OS_LINUX) || defined(OS_BSD))
   const LinuxUI* linux_ui = LinuxUI::instance();
   if (linux_ui) {
     ui::NativeTheme* native_theme =
