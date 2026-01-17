--- chrome/browser/web_applications/policy/web_app_policy_manager.cc.orig	2026-01-16 13:40:34 UTC
+++ chrome/browser/web_applications/policy/web_app_policy_manager.cc
@@ -136,7 +136,7 @@ GetPreinstalledWebAppsMappingForTesting() {
 namespace web_app {
 
 BASE_FEATURE(kDesktopPWAsForceUnregisterOSIntegration,
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
