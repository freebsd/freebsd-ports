--- ui/platform_window/platform_window_delegate.cc.orig	2022-10-24 13:33:33 UTC
+++ ui/platform_window/platform_window_delegate.cc
@@ -15,7 +15,7 @@ PlatformWindowDelegate::PlatformWindowDelegate() = def
 
 PlatformWindowDelegate::~PlatformWindowDelegate() = default;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 void PlatformWindowDelegate::OnWindowTiledStateChanged(
     WindowTiledEdges new_tiled_edges) {}
 #endif
