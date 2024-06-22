--- ui/platform_window/platform_window_delegate.cc.orig	2024-06-22 08:49:42 UTC
+++ ui/platform_window/platform_window_delegate.cc
@@ -61,7 +61,7 @@ gfx::Insets PlatformWindowDelegate::CalculateInsetsInD
   return gfx::Insets();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void PlatformWindowDelegate::OnWindowTiledStateChanged(
     WindowTiledEdges new_tiled_edges) {}
 #endif
