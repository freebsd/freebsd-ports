--- ui/views/widget/desktop_aura/desktop_window_tree_host_platform.cc.orig	2019-10-21 19:07:29 UTC
+++ ui/views/widget/desktop_aura/desktop_window_tree_host_platform.cc
@@ -137,7 +137,7 @@ void DesktopWindowTreeHostPlatform::OnNativeWidgetCrea
                                            Widget::InitParams::TYPE_WINDOW &&
                                        !params.remove_standard_frame);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Setup a non_client_window_event_filter, which handles resize/move, double
   // click and other events.
   DCHECK(!non_client_window_event_filter_);
@@ -668,7 +668,7 @@ void DesktopWindowTreeHostPlatform::Relayout() {
 }
 
 void DesktopWindowTreeHostPlatform::RemoveNonClientEventFilter() {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (!non_client_window_event_filter_)
     return;
 
