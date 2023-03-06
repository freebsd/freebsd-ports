--- src/3rdparty/chromium/ui/views/widget/desktop_aura/desktop_window_tree_host_platform.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/ui/views/widget/desktop_aura/desktop_window_tree_host_platform.cc
@@ -794,7 +794,7 @@ void DesktopWindowTreeHostPlatform::AddAdditionalInitP
 // DesktopWindowTreeHost:
 
 // Linux subclasses this host and adds some Linux specific bits.
-#if !defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_BSD)
 // static
 DesktopWindowTreeHost* DesktopWindowTreeHost::Create(
     internal::NativeWidgetDelegate* native_widget_delegate,
