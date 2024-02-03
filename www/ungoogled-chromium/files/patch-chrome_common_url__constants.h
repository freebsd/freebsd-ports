--- chrome/common/url_constants.h.orig	2024-02-03 15:42:55 UTC
+++ chrome/common/url_constants.h
@@ -821,7 +821,7 @@ inline constexpr char kPhoneHubPermissionLearnMoreURL[
     "https://support.9oo91e.qjz9zk/chromebook?p=multidevice";
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 // "Learn more" URL for the chrome apps deprecation dialog.
 inline constexpr char kChromeAppsDeprecationLearnMoreURL[] =
     "https://support.9oo91e.qjz9zk/chrome?p=chrome_app_deprecation";
