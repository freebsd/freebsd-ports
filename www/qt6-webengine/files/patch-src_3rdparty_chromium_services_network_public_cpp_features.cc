--- src/3rdparty/chromium/services/network/public/cpp/features.cc.orig	2026-08-11 12:42:19 UTC
+++ src/3rdparty/chromium/services/network/public/cpp/features.cc
@@ -107,7 +107,7 @@ BASE_FEATURE(kSplitAuthCacheByNetworkIsolationKey,
 
 // Enable usage of hardcoded DoH upgrade mapping for use in automatic mode.
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kDnsOverHttpsUpgrade,
              "DnsOverHttpsUpgrade",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -382,7 +382,7 @@ BASE_FEATURE(kAvoidResourceRequestCopies,
 // Enables Document-Isolation-Policy (DIP).
 // https://github.com/WICG/document-isolation-policy
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kDocumentIsolationPolicy,
              "DocumentIsolationPolicy",
              base::FEATURE_ENABLED_BY_DEFAULT
