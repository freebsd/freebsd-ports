--- net/base/features.cc.orig	2025-11-01 06:40:37 UTC
+++ net/base/features.cc
@@ -31,7 +31,7 @@ BASE_FEATURE(kCapReferrerToOriginOnCrossOrigin,
 
 BASE_FEATURE(kAsyncDns,
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -523,7 +523,7 @@ BASE_FEATURE(kDisableBlackholeOnNoNewNetwork,
              "DisableBlackHoleOnNoNewNetwork",
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kAddressTrackerLinuxIsProxied, base::FEATURE_ENABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -618,7 +618,7 @@ BASE_FEATURE(kReportingApiEnableEnterpriseCookieIssues
              base::FEATURE_DISABLED_BY_DEFAULT);
 
 BASE_FEATURE(kSimdutfBase64Support,
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -682,7 +682,7 @@ BASE_FEATURE(kHttpCacheMappedFileFlushWin, base::FEATU
 #endif
 
 BASE_FEATURE(kHttpCacheNoVarySearch,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
