--- chrome/browser/ui/views/frame/browser_frame_view_factory_views.cc.orig	2025-10-30 15:44:36 UTC
+++ chrome/browser/ui/views/frame/browser_frame_view_factory_views.cc
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
     BrowserWidget* widget,
     BrowserView* browser_view) {
