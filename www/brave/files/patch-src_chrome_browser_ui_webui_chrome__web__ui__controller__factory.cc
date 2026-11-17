--- src/chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc
@@ -117,17 +117,17 @@
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/webapps/isolated_web_apps/scheme.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/sandbox/sandbox_internals_ui.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/whats_new/whats_new_ui.h"
 #endif
 
@@ -268,7 +268,7 @@ void ChromeWebUIControllerFactory::GetFa
     const std::vector<int>& desired_sizes_in_pixel,
     favicon_base::FaviconResultsCallback callback) const {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (page_url.SchemeIs(webapps::kIsolatedAppScheme)) {
     ReadIsolatedWebAppFaviconsFromDisk(profile, page_url, std::move(callback));
     return;
@@ -445,7 +445,7 @@ ChromeWebUIControllerFactory::GetFavicon
     return NewTabPageUI::GetFaviconResourceBytes(scale_factor);
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (page_url.host() == chrome::kChromeUIWhatsNewHost) {
     return WhatsNewUI::GetFaviconResourceBytes(scale_factor);
   }
@@ -465,7 +465,7 @@ ChromeWebUIControllerFactory::GetFavicon
   }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (page_url.host() == chrome::kChromeUIContextualTasksHost) {
     return ContextualTasksUI::GetFaviconResourceBytes(scale_factor);
   }
