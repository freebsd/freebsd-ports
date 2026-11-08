--- net/base/features.cc.orig	2026-08-13 16:48:13 UTC
+++ net/base/features.cc
@@ -41,7 +41,7 @@ BASE_FEATURE(kDeriveConnectionTypeFromCapabilities,
 
 BASE_FEATURE(kAsyncDns,
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -321,7 +321,7 @@ inline constexpr auto kMigrateSessionsOnNetworkChangeV
 BASE_FEATURE(kMigrateSessionsOnNetworkChangeV2,
              kMigrateSessionsOnNetworkChangeV2Default);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kAddressTrackerLinuxIsProxied, base::FEATURE_ENABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -433,7 +433,7 @@ BASE_FEATURE(kReportingApiEnableEnterpriseCookieIssues
              base::FEATURE_DISABLED_BY_DEFAULT);
 
 BASE_FEATURE(kSimdutfBase64Support,
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
