--- src/3rdparty/chromium/services/network/public/cpp/features.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/services/network/public/cpp/features.cc
@@ -123,7 +123,7 @@ BASE_FEATURE(kSplitAuthCacheByNetworkIsolationKey,
 
 // Enable usage of hardcoded DoH upgrade mapping for use in automatic mode.
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kDnsOverHttpsUpgrade,
              "DnsOverHttpsUpgrade",
              base::FEATURE_ENABLED_BY_DEFAULT);
