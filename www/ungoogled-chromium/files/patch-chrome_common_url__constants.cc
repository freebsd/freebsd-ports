--- chrome/common/url_constants.cc.orig	2023-05-05 12:12:41 UTC
+++ chrome/common/url_constants.cc
@@ -522,7 +522,7 @@ const char kPhoneHubPermissionLearnMoreURL[] =
     "https://support.9oo91e.qjz9zk/chromebook/?p=multidevice";
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 const char kChromeAppsDeprecationLearnMoreURL[] =
     "https://support.9oo91e.qjz9zk/chrome/?p=chrome_app_deprecation";
 #endif
