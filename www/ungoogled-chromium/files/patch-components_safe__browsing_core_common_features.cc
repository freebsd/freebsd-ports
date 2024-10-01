--- components/safe_browsing/core/common/features.cc.orig	2024-10-01 07:26:23 UTC
+++ components/safe_browsing/core/common/features.cc
@@ -240,7 +240,7 @@ BASE_FEATURE(kRippleForEnhancedProtection,
 BASE_FEATURE(kSafeBrowsingAsyncRealTimeCheck,
              "SafeBrowsingAsyncRealTimeCheck",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
