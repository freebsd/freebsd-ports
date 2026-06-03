--- services/network/public/cpp/features.cc.orig	2026-05-07 17:02:56 UTC
+++ services/network/public/cpp/features.cc
@@ -95,7 +95,7 @@ BASE_FEATURE(kSplitAuthCacheByNetworkIsolationKey,
 // Enable usage of hardcoded DoH upgrade mapping for use in automatic mode.
 BASE_FEATURE(kDnsOverHttpsUpgrade,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
