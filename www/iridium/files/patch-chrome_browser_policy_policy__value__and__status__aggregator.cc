--- chrome/browser/policy/policy_value_and_status_aggregator.cc.orig	2026-11-17 21:17:00 UTC
+++ chrome/browser/policy/policy_value_and_status_aggregator.cc
@@ -62,7 +62,7 @@
 #include "chrome/browser/policy/value_provider/web_app_managed_configuration_value_provider.h"
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "components/policy/core/common/cloud/profile_cloud_policy_manager.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
