--- chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc.orig	2026-04-09 06:05:42 UTC
+++ chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc
@@ -114,17 +114,17 @@
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
 
@@ -265,7 +265,7 @@ void ChromeWebUIControllerFactory::GetFaviconForURL(
     const std::vector<int>& desired_sizes_in_pixel,
     favicon_base::FaviconResultsCallback callback) const {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (page_url.SchemeIs(webapps::kIsolatedAppScheme)) {
     ReadIsolatedWebAppFaviconsFromDisk(profile, page_url, std::move(callback));
     return;
@@ -405,7 +405,7 @@ base::RefCountedMemory* ChromeWebUIControllerFactory::
     return NewTabPageUI::GetFaviconResourceBytes(scale_factor);
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (page_url.host() == chrome::kChromeUIWhatsNewHost) {
     return WhatsNewUI::GetFaviconResourceBytes(scale_factor);
   }
@@ -444,7 +444,7 @@ base::RefCountedMemory* ChromeWebUIControllerFactory::
   }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (page_url.host() == chrome::kChromeUIContextualTasksHost) {
     return ContextualTasksUI::GetFaviconResourceBytes(scale_factor);
   }
