--- services/network/public/cpp/features.cc.orig	2024-08-01 05:47:53 UTC
+++ services/network/public/cpp/features.cc
@@ -120,7 +120,7 @@ BASE_FEATURE(kSplitAuthCacheByNetworkIsolationKey,
 BASE_FEATURE(kDnsOverHttpsUpgrade,
              "DnsOverHttpsUpgrade",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
