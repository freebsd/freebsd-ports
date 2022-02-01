--- ui/views/widget/native_widget_aura.cc.orig	2021-12-14 11:45:40 UTC
+++ ui/views/widget/native_widget_aura.cc
@@ -69,7 +69,7 @@
 #endif
 
 #if BUILDFLAG(ENABLE_DESKTOP_AURA) && \
-    (defined(OS_LINUX) || defined(OS_CHROMEOS))
+    (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD))
 #include "ui/views/widget/desktop_aura/desktop_window_tree_host_linux.h"
 #endif
 
@@ -1141,7 +1141,7 @@ void NativeWidgetAura::SetInitialFocus(ui::WindowShowS
 
 namespace {
 #if BUILDFLAG(ENABLE_DESKTOP_AURA) && \
-    (defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS))
+    (defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD))
 void CloseWindow(aura::Window* window) {
   if (window) {
     Widget* widget = Widget::GetWidgetForNativeView(window);
@@ -1172,7 +1172,7 @@ void Widget::CloseAllSecondaryWidgets() {
 #endif
 
 #if BUILDFLAG(ENABLE_DESKTOP_AURA) && \
-    (defined(OS_LINUX) || defined(OS_CHROMEOS))
+    (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD))
   DesktopWindowTreeHostLinux::CleanUpWindowList(CloseWindow);
 #endif
 }
