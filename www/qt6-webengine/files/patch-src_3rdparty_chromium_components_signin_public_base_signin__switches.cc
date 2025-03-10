--- src/3rdparty/chromium/components/signin/public/base/signin_switches.cc.orig	2024-07-03 01:14:49 UTC
+++ src/3rdparty/chromium/components/signin/public/base/signin_switches.cc
@@ -102,7 +102,7 @@ BASE_FEATURE(kUnoDesktop, "UnoDesktop", base::FEATURE_
 BASE_FEATURE(kUnoDesktop, "UnoDesktop", base::FEATURE_DISABLED_BY_DEFAULT);
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kMinorModeRestrictionsForHistorySyncOptIn,
              "MinorModeRestrictionsForHistorySyncOptIn",
              base::FEATURE_DISABLED_BY_DEFAULT);
