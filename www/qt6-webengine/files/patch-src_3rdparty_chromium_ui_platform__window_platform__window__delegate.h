--- src/3rdparty/chromium/ui/platform_window/platform_window_delegate.h.orig	2023-04-05 11:05:06 UTC
+++ src/3rdparty/chromium/ui/platform_window/platform_window_delegate.h
@@ -130,7 +130,7 @@ class COMPONENT_EXPORT(PLATFORM_WINDOW) PlatformWindow
   virtual void OnWindowStateChanged(PlatformWindowState old_state,
                                     PlatformWindowState new_state) = 0;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   // Notifies the delegate that the tiled state of the window edges has changed.
   virtual void OnWindowTiledStateChanged(WindowTiledEdges new_tiled_edges);
 #endif
