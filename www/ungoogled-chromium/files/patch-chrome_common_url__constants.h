--- chrome/common/url_constants.h.orig	2025-03-09 21:38:10 UTC
+++ chrome/common/url_constants.h
@@ -978,7 +978,7 @@ inline constexpr char kOutdatedPluginLearnMoreURL[] =
 inline constexpr char kPhoneHubPermissionLearnMoreURL[] =
     "https://support.9oo91e.qjz9zk/chromebook?p=multidevice";
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // "Learn more" URL for the chrome apps deprecation dialog.
 inline constexpr char kChromeAppsDeprecationLearnMoreURL[] =
     "https://support.9oo91e.qjz9zk/chrome?p=chrome_app_deprecation";
