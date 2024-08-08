--- chrome/common/url_constants.h.orig	2024-08-01 05:47:53 UTC
+++ chrome/common/url_constants.h
@@ -907,7 +907,7 @@ inline constexpr char kOutdatedPluginLearnMoreURL[] =
 inline constexpr char kPhoneHubPermissionLearnMoreURL[] =
     "https://support.google.com/chromebook?p=multidevice";
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // "Learn more" URL for the chrome apps deprecation dialog.
 inline constexpr char kChromeAppsDeprecationLearnMoreURL[] =
     "https://support.google.com/chrome?p=chrome_app_deprecation";
