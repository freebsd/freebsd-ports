--- src/3rdparty/chromium/ui/platform_window/platform_window_delegate.cc.orig	2023-04-05 11:05:06 UTC
+++ src/3rdparty/chromium/ui/platform_window/platform_window_delegate.cc
@@ -29,7 +29,7 @@ PlatformWindowDelegate::PlatformWindowDelegate() = def
 
 PlatformWindowDelegate::~PlatformWindowDelegate() = default;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 void PlatformWindowDelegate::OnWindowTiledStateChanged(
     WindowTiledEdges new_tiled_edges) {}
 #endif
