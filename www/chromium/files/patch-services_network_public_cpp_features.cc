--- services/network/public/cpp/features.cc.orig	2025-12-05 10:12:50 UTC
+++ services/network/public/cpp/features.cc
@@ -93,7 +93,7 @@ BASE_FEATURE(kSplitAuthCacheByNetworkIsolationKey,
 // Enable usage of hardcoded DoH upgrade mapping for use in automatic mode.
 BASE_FEATURE(kDnsOverHttpsUpgrade,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -361,7 +361,7 @@ BASE_FEATURE(kAvoidResourceRequestCopies, base::FEATUR
 // https://github.com/WICG/document-isolation-policy
 BASE_FEATURE(kDocumentIsolationPolicy,
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
