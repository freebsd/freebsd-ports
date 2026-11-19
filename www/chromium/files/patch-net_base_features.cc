--- net/base/features.cc.orig	2026-11-19 12:25:27 UTC
+++ net/base/features.cc
@@ -39,7 +39,7 @@ BASE_FEATURE(kDeriveConnectionTypeFromCapabilities,
 
 BASE_FEATURE(kAsyncDns,
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -552,7 +552,7 @@ BASE_FEATURE(kReportingApiEnableEnterpriseCookieIssues
              base::FEATURE_DISABLED_BY_DEFAULT);
 
 BASE_FEATURE(kSimdutfBase64Support,
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -909,7 +909,7 @@ BASE_FEATURE_PARAM(size_t,
 
 BASE_FEATURE(kQuicUseReadMultiple,
 #if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-     BUILDFLAG(IS_ANDROID)) &&                        \
+     BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)) &&   \
     !BUILDFLAG(CRONET_BUILD)
              // Only Linux, ChromeOS, and Android implement batched recvmmsg()
              // in UDPSocketPosix::ReadMultiple(). Cronet is still running its
