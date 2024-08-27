--- services/network/public/cpp/features.cc.orig	2024-08-26 12:06:38 UTC
+++ services/network/public/cpp/features.cc
@@ -127,7 +127,7 @@ BASE_FEATURE(kSplitAuthCacheByNetworkIsolationKey,
 BASE_FEATURE(kDnsOverHttpsUpgrade,
              "DnsOverHttpsUpgrade",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
