--- src/3rdparty/chromium/ui/views/widget/desktop_aura/desktop_window_tree_host_platform.cc.orig	2020-03-16 14:04:24 UTC
+++ src/3rdparty/chromium/ui/views/widget/desktop_aura/desktop_window_tree_host_platform.cc
@@ -732,7 +732,7 @@ void DesktopWindowTreeHostPlatform::AddAdditionalInitP
 // DesktopWindowTreeHost:
 
 // Linux subclasses this host and adds some Linux specific bits.
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
 // static
 DesktopWindowTreeHost* DesktopWindowTreeHost::Create(
     internal::NativeWidgetDelegate* native_widget_delegate,
