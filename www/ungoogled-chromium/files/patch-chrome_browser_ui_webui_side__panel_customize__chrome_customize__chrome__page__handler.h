--- chrome/browser/ui/webui/side_panel/customize_chrome/customize_chrome_page_handler.h.orig	2025-10-21 16:57:35 UTC
+++ chrome/browser/ui/webui/side_panel/customize_chrome/customize_chrome_page_handler.h
@@ -208,7 +208,7 @@ class CustomizeChromePageHandler
   // value needs to be requeried by the page.
   GURL last_source_url_{GURL(chrome::kChromeUINewTabPageURL)};
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   PrefChangeRegistrar browser_pref_change_registrar_;
 #endif
   PrefChangeRegistrar pref_change_registrar_;
