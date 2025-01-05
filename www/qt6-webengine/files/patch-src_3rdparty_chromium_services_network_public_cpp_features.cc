--- src/3rdparty/chromium/services/network/public/cpp/features.cc.orig	2024-07-03 01:14:49 UTC
+++ src/3rdparty/chromium/services/network/public/cpp/features.cc
@@ -96,7 +96,7 @@ BASE_FEATURE(kSplitAuthCacheByNetworkIsolationKey,
 
 // Enable usage of hardcoded DoH upgrade mapping for use in automatic mode.
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kDnsOverHttpsUpgrade,
              "DnsOverHttpsUpgrade",
              base::FEATURE_ENABLED_BY_DEFAULT);
