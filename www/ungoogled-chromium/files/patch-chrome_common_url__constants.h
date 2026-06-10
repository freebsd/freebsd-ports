--- chrome/common/url_constants.h.orig	2026-06-05 14:13:43 UTC
+++ chrome/common/url_constants.h
@@ -728,7 +728,7 @@ inline constexpr char kOutdatedPluginLearnMoreURL[] =
     "https://support.9oo91e.qjz9zk/chrome?p=ib_outdated_plugin";
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // "Learn more" URL for the chrome apps deprecation dialog.
 inline constexpr char kChromeAppsDeprecationLearnMoreURL[] =
     "https://support.9oo91e.qjz9zk/chrome?p=chrome_app_deprecation";
