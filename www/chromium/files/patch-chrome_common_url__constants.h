--- chrome/common/url_constants.h.orig	2026-10-18 13:29:39 UTC
+++ chrome/common/url_constants.h
@@ -725,7 +725,7 @@ inline constexpr char kProcessIsolationLearnMoreUrl[] 
     "https://support.google.com/chrome?p=process_isolation";
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // "Learn more" URL for the chrome apps deprecation dialog.
 inline constexpr char kChromeAppsDeprecationLearnMoreURL[] =
     "https://support.google.com/chrome?p=chrome_app_deprecation";
