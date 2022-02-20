--- ui/views/widget/desktop_aura/desktop_window_tree_host_platform.cc.orig	2022-02-07 13:39:41 UTC
+++ ui/views/widget/desktop_aura/desktop_window_tree_host_platform.cc
@@ -910,7 +910,7 @@ display::Display DesktopWindowTreeHostPlatform::GetDis
 // DesktopWindowTreeHost:
 
 // Linux subclasses this host and adds some Linux specific bits.
-#if !defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_BSD)
 // static
 DesktopWindowTreeHost* DesktopWindowTreeHost::Create(
     internal::NativeWidgetDelegate* native_widget_delegate,
