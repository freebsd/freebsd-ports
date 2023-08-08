--- src/3rdparty/chromium/ui/platform_window/platform_window_delegate.cc.orig	2023-03-28 19:45:02 UTC
+++ src/3rdparty/chromium/ui/platform_window/platform_window_delegate.cc
@@ -16,7 +16,7 @@ PlatformWindowDelegate::~PlatformWindowDelegate() = de
 
 PlatformWindowDelegate::~PlatformWindowDelegate() = default;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 void PlatformWindowDelegate::OnWindowTiledStateChanged(
     WindowTiledEdges new_tiled_edges) {}
 #endif
