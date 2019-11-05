--- ui/views/widget/desktop_aura/desktop_window_tree_host_platform.h.orig	2019-10-21 19:07:29 UTC
+++ ui/views/widget/desktop_aura/desktop_window_tree_host_platform.h
@@ -146,7 +146,7 @@ class VIEWS_EXPORT DesktopWindowTreeHostPlatform
 
   base::string16 window_title_;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // A handler for events intended for non client area.
   std::unique_ptr<WindowEventFilter> non_client_window_event_filter_;
 #endif
