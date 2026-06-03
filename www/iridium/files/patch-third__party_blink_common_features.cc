--- third_party/blink/common/features.cc.orig	2026-05-11 13:57:04 UTC
+++ third_party/blink/common/features.cc
@@ -649,7 +649,7 @@ BASE_FEATURE(kDevToolsWebMCPSupport, base::FEATURE_DIS
 
 BASE_FEATURE(kDirectCompositorThreadIpc,
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -1990,7 +1990,7 @@ BASE_FEATURE(kPrefetchFontLookupTables,
 // currently out of scope.
 BASE_FEATURE(kPreloadingEagerHoverHeuristics,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
