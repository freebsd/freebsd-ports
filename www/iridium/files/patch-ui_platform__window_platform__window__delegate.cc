--- ui/platform_window/platform_window_delegate.cc.orig	2024-12-22 12:24:29 UTC
+++ ui/platform_window/platform_window_delegate.cc
@@ -66,7 +66,7 @@ gfx::Insets PlatformWindowDelegate::CalculateInsetsInD
   return gfx::Insets();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void PlatformWindowDelegate::OnWindowTiledStateChanged(
     WindowTiledEdges new_tiled_edges) {}
 #endif
