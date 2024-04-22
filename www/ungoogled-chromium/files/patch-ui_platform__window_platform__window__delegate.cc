--- ui/platform_window/platform_window_delegate.cc.orig	2024-03-22 14:16:19 UTC
+++ ui/platform_window/platform_window_delegate.cc
@@ -48,7 +48,7 @@ PlatformWindowDelegate::PlatformWindowDelegate() = def
 
 PlatformWindowDelegate::~PlatformWindowDelegate() = default;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void PlatformWindowDelegate::OnWindowTiledStateChanged(
     WindowTiledEdges new_tiled_edges) {}
 #endif
