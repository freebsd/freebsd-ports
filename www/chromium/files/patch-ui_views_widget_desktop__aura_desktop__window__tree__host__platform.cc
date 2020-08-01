--- ui/views/widget/desktop_aura/desktop_window_tree_host_platform.cc.orig	2020-07-07 21:58:19 UTC
+++ ui/views/widget/desktop_aura/desktop_window_tree_host_platform.cc
@@ -787,7 +787,7 @@ void DesktopWindowTreeHostPlatform::AddAdditionalInitP
 // DesktopWindowTreeHost:
 
 // Linux subclasses this host and adds some Linux specific bits.
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
 // static
 DesktopWindowTreeHost* DesktopWindowTreeHost::Create(
     internal::NativeWidgetDelegate* native_widget_delegate,
