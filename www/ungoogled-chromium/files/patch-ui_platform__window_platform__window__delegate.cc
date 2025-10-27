--- ui/platform_window/platform_window_delegate.cc.orig	2025-10-21 16:57:35 UTC
+++ ui/platform_window/platform_window_delegate.cc
@@ -58,7 +58,7 @@ gfx::Insets PlatformWindowDelegate::CalculateInsetsInD
   return gfx::Insets();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void PlatformWindowDelegate::OnWindowTiledStateChanged(
     WindowTiledEdges new_tiled_edges) {}
 #endif
