--- chrome/common/url_constants.h.orig	2026-08-13 07:41:05 UTC
+++ chrome/common/url_constants.h
@@ -734,7 +734,7 @@ inline constexpr char kOutdatedPluginLearnMoreURL[] =
     "https://support.9oo91e.qjz9zk/chrome?p=ib_outdated_plugin";
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // "Learn more" URL for the chrome apps deprecation dialog.
 inline constexpr char kChromeAppsDeprecationLearnMoreURL[] =
     "https://support.9oo91e.qjz9zk/chrome?p=chrome_app_deprecation";
