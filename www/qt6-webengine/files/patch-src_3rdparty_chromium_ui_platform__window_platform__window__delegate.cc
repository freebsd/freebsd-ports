--- src/3rdparty/chromium/ui/platform_window/platform_window_delegate.cc.orig	2024-02-23 21:04:38 UTC
+++ src/3rdparty/chromium/ui/platform_window/platform_window_delegate.cc
@@ -42,7 +42,7 @@ PlatformWindowDelegate::PlatformWindowDelegate() = def
 
 PlatformWindowDelegate::~PlatformWindowDelegate() = default;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void PlatformWindowDelegate::OnWindowTiledStateChanged(
     WindowTiledEdges new_tiled_edges) {}
 #endif
