--- chrome/common/url_constants.h.orig	2025-09-10 13:22:16 UTC
+++ chrome/common/url_constants.h
@@ -993,7 +993,7 @@ inline constexpr char kOutdatedPluginLearnMoreURL[] =
 inline constexpr char kPhoneHubPermissionLearnMoreURL[] =
     "https://support.9oo91e.qjz9zk/chromebook?p=multidevice";
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // "Learn more" URL for the chrome apps deprecation dialog.
 inline constexpr char kChromeAppsDeprecationLearnMoreURL[] =
     "https://support.9oo91e.qjz9zk/chrome?p=chrome_app_deprecation";
