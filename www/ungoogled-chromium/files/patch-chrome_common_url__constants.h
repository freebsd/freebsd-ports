--- chrome/common/url_constants.h.orig	2026-10-31 12:09:36 UTC
+++ chrome/common/url_constants.h
@@ -725,7 +725,7 @@ inline constexpr char kProcessIsolationLearnMoreUrl[] 
     "https://support.9oo91e.qjz9zk/chrome?p=process_isolation";
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // "Learn more" URL for the chrome apps deprecation dialog.
 inline constexpr char kChromeAppsDeprecationLearnMoreURL[] =
     "https://support.9oo91e.qjz9zk/chrome?p=chrome_app_deprecation";
