--- net/base/features.cc.orig	2023-11-22 14:00:11 UTC
+++ net/base/features.cc
@@ -169,7 +169,7 @@ BASE_FEATURE(kSameSiteDefaultChecksMethodRigorously,
 #if BUILDFLAG(CHROME_ROOT_STORE_OPTIONAL)
 BASE_FEATURE(kChromeRootStoreUsed,
              "ChromeRootStoreUsed",
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
