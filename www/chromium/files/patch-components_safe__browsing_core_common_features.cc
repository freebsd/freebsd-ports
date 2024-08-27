--- components/safe_browsing/core/common/features.cc.orig	2024-08-26 12:06:38 UTC
+++ components/safe_browsing/core/common/features.cc
@@ -186,7 +186,7 @@ BASE_FEATURE(kGooglePlayProtectInApkTelemetry,
 BASE_FEATURE(kHashPrefixRealTimeLookups,
              "SafeBrowsingHashPrefixRealTimeLookups",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -267,7 +267,7 @@ constexpr base::FeatureParam<int> kReferrerChainEventM
 BASE_FEATURE(kSafeBrowsingAsyncRealTimeCheck,
              "SafeBrowsingAsyncRealTimeCheck",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
