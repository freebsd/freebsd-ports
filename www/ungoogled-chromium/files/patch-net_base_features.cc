--- net/base/features.cc.orig	2025-09-10 13:22:16 UTC
+++ net/base/features.cc
@@ -34,7 +34,7 @@ BASE_FEATURE(kCapReferrerToOriginOnCrossOrigin,
 BASE_FEATURE(kAsyncDns,
              "AsyncDns",
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -713,7 +713,7 @@ BASE_FEATURE(kReportingApiEnableEnterpriseCookieIssues
 
 BASE_FEATURE(kSimdutfBase64Support,
              "SimdutfBase64Support",
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
