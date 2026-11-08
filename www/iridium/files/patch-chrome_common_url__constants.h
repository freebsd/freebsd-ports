--- chrome/common/url_constants.h.orig	2026-08-13 16:48:13 UTC
+++ chrome/common/url_constants.h
@@ -734,7 +734,7 @@ inline constexpr char kOutdatedPluginLearnMoreURL[] =
     "https://support.google.com/chrome?p=ib_outdated_plugin";
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // "Learn more" URL for the chrome apps deprecation dialog.
 inline constexpr char kChromeAppsDeprecationLearnMoreURL[] =
     "https://support.google.com/chrome?p=chrome_app_deprecation";
