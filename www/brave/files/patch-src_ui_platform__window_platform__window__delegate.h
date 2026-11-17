--- src/ui/platform_window/platform_window_delegate.h.orig	2026-10-18 18:43:23 UTC
+++ src/ui/platform_window/platform_window_delegate.h
@@ -146,7 +146,7 @@ class COMPONENT_EXPORT(PLATFORM_WINDOW)
   virtual void OnWindowStateChanged(PlatformWindowState old_state,
                                     PlatformWindowState new_state) = 0;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Notifies the delegate that the tiled state of the window edges has changed.
   virtual void OnWindowTiledStateChanged(WindowTiledEdges new_tiled_edges);
 #endif
