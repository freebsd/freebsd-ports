--- chrome/browser/ui/views/frame/browser_non_client_frame_view_factory_views.cc.orig	2022-09-24 10:57:32 UTC
+++ chrome/browser/ui/views/frame/browser_non_client_frame_view_factory_views.cc
@@ -16,7 +16,7 @@
 #include "chrome/browser/ui/views/frame/glass_browser_frame_view.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/views/frame/browser_frame_view_layout_linux.h"
 #include "chrome/browser/ui/views/frame/browser_frame_view_layout_linux_native.h"
 #include "chrome/browser/ui/views/frame/browser_frame_view_linux.h"
@@ -34,7 +34,7 @@ namespace {
 std::unique_ptr<OpaqueBrowserFrameView> CreateOpaqueBrowserFrameView(
     BrowserFrame* frame,
     BrowserView* browser_view) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto* linux_ui = ui::LinuxUi::instance();
   auto* profile = browser_view->browser()->profile();
   auto* theme_service_factory = ThemeServiceFactory::GetForProfile(profile);
@@ -74,7 +74,7 @@ std::unique_ptr<BrowserNonClientFrameView> CreateBrows
     BrowserFrame* frame,
     BrowserView* browser_view) {
 // TODO(https://crbug.com/1346734): Enable it on all platforms.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (browser_view->browser()->is_type_picture_in_picture()) {
     return std::make_unique<PictureInPictureBrowserFrameView>(frame,
                                                               browser_view);
