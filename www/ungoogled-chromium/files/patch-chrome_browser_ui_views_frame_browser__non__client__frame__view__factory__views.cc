--- chrome/browser/ui/views/frame/browser_non_client_frame_view_factory_views.cc.orig	2025-09-10 13:22:16 UTC
+++ chrome/browser/ui/views/frame/browser_non_client_frame_view_factory_views.cc
@@ -17,7 +17,7 @@
 #include "chrome/browser/ui/views/frame/browser_frame_view_win.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/views/frame/browser_frame_view_layout_linux.h"
 #include "chrome/browser/ui/views/frame/browser_frame_view_layout_linux_native.h"
 #include "chrome/browser/ui/views/frame/browser_frame_view_linux_native.h"
@@ -32,7 +32,7 @@ namespace chrome {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::unique_ptr<OpaqueBrowserFrameView> CreateOpaqueBrowserFrameViewLinux(
     BrowserFrame* frame,
     BrowserView* browser_view) {
