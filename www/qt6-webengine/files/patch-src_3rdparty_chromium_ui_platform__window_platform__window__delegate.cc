--- src/3rdparty/chromium/ui/platform_window/platform_window_delegate.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/ui/platform_window/platform_window_delegate.cc
@@ -57,7 +57,7 @@ gfx::Insets PlatformWindowDelegate::CalculateInsetsInD
   return gfx::Insets();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void PlatformWindowDelegate::OnWindowTiledStateChanged(
     WindowTiledEdges new_tiled_edges) {}
 #endif
