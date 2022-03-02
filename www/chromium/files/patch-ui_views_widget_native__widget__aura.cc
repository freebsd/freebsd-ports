--- ui/views/widget/native_widget_aura.cc.orig	2022-02-28 16:54:41 UTC
+++ ui/views/widget/native_widget_aura.cc
@@ -69,7 +69,7 @@
 #endif
 
 #if BUILDFLAG(ENABLE_DESKTOP_AURA) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 #include "ui/views/widget/desktop_aura/desktop_window_tree_host_linux.h"
 #endif
 
@@ -1151,7 +1151,7 @@ void NativeWidgetAura::SetInitialFocus(ui::WindowShowS
 
 namespace {
 #if BUILDFLAG(ENABLE_DESKTOP_AURA) && \
-    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 void CloseWindow(aura::Window* window) {
   if (window) {
     Widget* widget = Widget::GetWidgetForNativeView(window);
@@ -1182,7 +1182,7 @@ void Widget::CloseAllSecondaryWidgets() {
 #endif
 
 #if BUILDFLAG(ENABLE_DESKTOP_AURA) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
   DesktopWindowTreeHostLinux::CleanUpWindowList(CloseWindow);
 #endif
 }
