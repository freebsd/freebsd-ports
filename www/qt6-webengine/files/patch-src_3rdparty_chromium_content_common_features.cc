--- src/3rdparty/chromium/content/common/features.cc.orig	2025-02-21 12:29:33 UTC
+++ src/3rdparty/chromium/content/common/features.cc
@@ -145,7 +145,7 @@ BASE_FEATURE(kEnableBackForwardCacheForOngoingSubframe
              base::FEATURE_ENABLED_BY_DEFAULT);
 
 // Enables error reporting for JS errors inside DevTools frontend host
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kEnableDevToolsJsErrorReporting,
              "EnableDevToolsJsErrorReporting",
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -301,7 +301,7 @@ BASE_FEATURE(kGroupNIKByJoiningOrigin,
 // process and having browser process handle adjusting thread properties (nice
 // value, c-group, latency sensitivity...) for children which have sandbox
 // restrictions.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kHandleChildThreadTypeChangesInBrowser,
              "HandleChildThreadTypeChangesInBrowser",
              base::FEATURE_ENABLED_BY_DEFAULT);
