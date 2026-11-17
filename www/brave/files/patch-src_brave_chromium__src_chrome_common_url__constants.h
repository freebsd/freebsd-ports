--- src/brave/chromium_src/chrome/common/url_constants.h.orig	2026-10-18 18:43:23 UTC
+++ src/brave/chromium_src/chrome/common/url_constants.h
@@ -688,7 +688,7 @@ inline constexpr char kOutdatedPluginLea
     "360018163151-How-do-I-manage-Flash-audio-video-";
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
 // "Learn more" URL for the chrome apps deprecation dialog.
 inline constexpr char kChromeAppsDeprecationLearnMoreURL[] =
     "https://support.google.com/chrome/?p=chrome_app_deprecation";
