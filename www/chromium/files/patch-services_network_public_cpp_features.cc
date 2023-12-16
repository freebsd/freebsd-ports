--- services/network/public/cpp/features.cc.orig	2023-12-10 06:10:27 UTC
+++ services/network/public/cpp/features.cc
@@ -98,7 +98,7 @@ BASE_FEATURE(kSplitAuthCacheByNetworkIsolationKey,
 BASE_FEATURE(kDnsOverHttpsUpgrade,
              "DnsOverHttpsUpgrade",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
