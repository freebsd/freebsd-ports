--- chrome/browser/ui/views/frame/browser_non_client_frame_view_factory_views.cc.orig	2021-12-14 11:44:59 UTC
+++ chrome/browser/ui/views/frame/browser_non_client_frame_view_factory_views.cc
@@ -15,7 +15,7 @@
 #include "chrome/browser/ui/views/frame/glass_browser_frame_view.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/ui/views/frame/browser_frame_view_layout_linux.h"
 #include "chrome/browser/ui/views/frame/browser_frame_view_layout_linux_native.h"
 #include "chrome/browser/ui/views/frame/browser_frame_view_linux.h"
@@ -33,7 +33,7 @@ namespace {
 std::unique_ptr<OpaqueBrowserFrameView> CreateOpaqueBrowserFrameView(
     BrowserFrame* frame,
     BrowserView* browser_view) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   auto* linux_ui = views::LinuxUI::instance();
   auto* profile = browser_view->browser()->profile();
   auto* theme_service_factory = ThemeServiceFactory::GetForProfile(profile);
