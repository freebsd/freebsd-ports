--- chrome/browser/web_applications/policy/web_app_policy_manager.cc.orig	2024-05-21 18:07:39 UTC
+++ chrome/browser/web_applications/policy/web_app_policy_manager.cc
@@ -101,7 +101,7 @@ namespace web_app {
 
 BASE_FEATURE(kDesktopPWAsForceUnregisterOSIntegration,
              "DesktopPWAsForceUnregisterOSIntegration",
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
