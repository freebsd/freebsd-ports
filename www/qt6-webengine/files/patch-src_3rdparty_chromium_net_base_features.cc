--- src/3rdparty/chromium/net/base/features.cc.orig	2023-12-12 22:08:45 UTC
+++ src/3rdparty/chromium/net/base/features.cc
@@ -181,7 +181,7 @@ BASE_FEATURE(kChromeRootStoreUsed,
 #if BUILDFLAG(CHROME_ROOT_STORE_OPTIONAL)
 BASE_FEATURE(kChromeRootStoreUsed,
              "ChromeRootStoreUsed",
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
