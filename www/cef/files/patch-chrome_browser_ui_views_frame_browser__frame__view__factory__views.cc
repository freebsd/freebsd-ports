--- chrome/browser/ui/views/frame/browser_frame_view_factory_views.cc.orig	2026-08-31 10:59:09 UTC
+++ chrome/browser/ui/views/frame/browser_frame_view_factory_views.cc
@@ -16,7 +16,7 @@
 #include "chrome/browser/ui/views/frame/picture_in_picture_browser_frame_view.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/views/frame/browser_frame_view_layout_linux.h"
 #include "chrome/browser/ui/views/frame/browser_frame_view_layout_linux_native.h"
 #include "chrome/browser/ui/views/frame/browser_frame_view_linux.h"
@@ -31,7 +31,7 @@ namespace chrome {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::unique_ptr<OpaqueBrowserFrameView> CreateOpaqueBrowserFrameViewLinux(
     BrowserWidget* widget,
     BrowserView* browser_view) {
