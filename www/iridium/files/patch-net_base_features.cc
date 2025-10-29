--- net/base/features.cc.orig	2025-10-28 14:29:43 UTC
+++ net/base/features.cc
@@ -29,7 +29,7 @@ BASE_FEATURE(CapReferrerToOriginOnCrossOrigin,
 
 BASE_FEATURE(AsyncDns,
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -594,7 +594,7 @@ BASE_FEATURE(ReportingApiEnableEnterpriseCookieIssues,
              base::FEATURE_DISABLED_BY_DEFAULT);
 
 BASE_FEATURE(SimdutfBase64Support,
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
