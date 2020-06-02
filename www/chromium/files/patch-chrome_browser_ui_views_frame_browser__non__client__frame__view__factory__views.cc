--- chrome/browser/ui/views/frame/browser_non_client_frame_view_factory_views.cc.orig	2020-05-13 18:39:38 UTC
+++ chrome/browser/ui/views/frame/browser_non_client_frame_view_factory_views.cc
@@ -13,7 +13,7 @@
 #include "chrome/browser/ui/views/frame/glass_browser_frame_view.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 #include "chrome/browser/ui/views/frame/desktop_linux_browser_frame_view.h"
 #include "chrome/browser/ui/views/frame/desktop_linux_browser_frame_view_layout.h"
 #include "ui/views/linux_ui/linux_ui.h"
@@ -27,7 +27,7 @@ namespace {
 OpaqueBrowserFrameView* CreateOpaqueBrowserFrameView(
     BrowserFrame* frame,
     BrowserView* browser_view) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   auto* linux_ui = views::LinuxUI::instance();
   auto* profile = browser_view->browser()->profile();
   auto* theme_service_factory = ThemeServiceFactory::GetForProfile(profile);
