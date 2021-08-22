--- ui/views/widget/desktop_aura/desktop_window_tree_host_platform.cc.orig	2021-07-19 18:45:44 UTC
+++ ui/views/widget/desktop_aura/desktop_window_tree_host_platform.cc
@@ -883,7 +883,7 @@ display::Display DesktopWindowTreeHostPlatform::GetDis
 // DesktopWindowTreeHost:
 
 // Linux subclasses this host and adds some Linux specific bits.
-#if !defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_BSD)
 // static
 DesktopWindowTreeHost* DesktopWindowTreeHost::Create(
     internal::NativeWidgetDelegate* native_widget_delegate,
