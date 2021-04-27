--- ui/views/widget/native_widget_aura.cc.orig	2021-04-14 18:41:39 UTC
+++ ui/views/widget/native_widget_aura.cc
@@ -68,7 +68,7 @@
 #endif
 
 #if BUILDFLAG(ENABLE_DESKTOP_AURA) && \
-    (defined(OS_LINUX) || defined(OS_CHROMEOS))
+    (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD))
 #include "ui/views/linux_ui/linux_ui.h"
 #include "ui/views/widget/desktop_aura/desktop_window_tree_host_linux.h"
 #endif
@@ -1122,7 +1122,7 @@ void NativeWidgetAura::SetInitialFocus(ui::WindowShowS
 
 namespace {
 #if BUILDFLAG(ENABLE_DESKTOP_AURA) && \
-    (defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS))
+    (defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD))
 void CloseWindow(aura::Window* window) {
   if (window) {
     Widget* widget = Widget::GetWidgetForNativeView(window);
@@ -1153,14 +1153,14 @@ void Widget::CloseAllSecondaryWidgets() {
 #endif
 
 #if BUILDFLAG(ENABLE_DESKTOP_AURA) && \
-    (defined(OS_LINUX) || defined(OS_CHROMEOS))
+    (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD))
   DesktopWindowTreeHostLinux::CleanUpWindowList(CloseWindow);
 #endif
 }
 
 const ui::NativeTheme* Widget::GetNativeTheme() const {
 #if BUILDFLAG(ENABLE_DESKTOP_AURA) && \
-    (defined(OS_LINUX) || defined(OS_CHROMEOS))
+    (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD))
   const LinuxUI* linux_ui = LinuxUI::instance();
   if (linux_ui) {
     ui::NativeTheme* native_theme =
