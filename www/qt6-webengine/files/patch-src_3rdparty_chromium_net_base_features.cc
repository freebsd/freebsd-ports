--- src/3rdparty/chromium/net/base/features.cc.orig	2026-02-26 14:39:03 UTC
+++ src/3rdparty/chromium/net/base/features.cc
@@ -34,7 +34,7 @@ BASE_FEATURE(kChromeStaticPinning,
              base::FEATURE_ENABLED_BY_DEFAULT);
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kAsyncDns,
              "AsyncDns",
              base::FEATURE_ENABLED_BY_DEFAULT
@@ -720,7 +720,7 @@ BASE_FEATURE(kReportingApiEnableEnterpriseCookieIssues
              "ReportingApiEnableEnterpriseCookieIssues",
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kSimdutfBase64Support,
              "SimdutfBase64Support",
              base::FEATURE_ENABLED_BY_DEFAULT
