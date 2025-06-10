--- src/3rdparty/chromium/services/network/public/cpp/features.cc.orig	2025-02-21 12:29:33 UTC
+++ src/3rdparty/chromium/services/network/public/cpp/features.cc
@@ -125,7 +125,7 @@ BASE_FEATURE(kSplitAuthCacheByNetworkIsolationKey,
 
 // Enable usage of hardcoded DoH upgrade mapping for use in automatic mode.
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kDnsOverHttpsUpgrade,
              "DnsOverHttpsUpgrade",
              base::FEATURE_ENABLED_BY_DEFAULT);
