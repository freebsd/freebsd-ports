--- chrome/common/url_constants.h.orig	2024-11-14 07:57:23 UTC
+++ chrome/common/url_constants.h
@@ -950,7 +950,7 @@ inline constexpr char kOutdatedPluginLearnMoreURL[] =
 inline constexpr char kPhoneHubPermissionLearnMoreURL[] =
     "https://support.google.com/chromebook?p=multidevice";
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // "Learn more" URL for the chrome apps deprecation dialog.
 inline constexpr char kChromeAppsDeprecationLearnMoreURL[] =
     "https://support.google.com/chrome?p=chrome_app_deprecation";
