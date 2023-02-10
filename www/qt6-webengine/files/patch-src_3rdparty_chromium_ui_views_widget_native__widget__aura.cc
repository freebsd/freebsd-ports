--- src/3rdparty/chromium/ui/views/widget/native_widget_aura.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/ui/views/widget/native_widget_aura.cc
@@ -69,7 +69,7 @@
 #endif
 
 #if BUILDFLAG(ENABLE_DESKTOP_AURA) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 #include "ui/views/widget/desktop_aura/desktop_window_tree_host_linux.h"
 #endif
 
@@ -1154,7 +1154,7 @@ namespace {
 
 namespace {
 #if BUILDFLAG(ENABLE_DESKTOP_AURA) && \
-    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 void CloseWindow(aura::Window* window) {
   if (window) {
     Widget* widget = Widget::GetWidgetForNativeView(window);
@@ -1185,7 +1185,7 @@ void Widget::CloseAllSecondaryWidgets() {
 #endif
 
 #if BUILDFLAG(ENABLE_DESKTOP_AURA) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
   DesktopWindowTreeHostLinux::CleanUpWindowList(CloseWindow);
 #endif
 }
