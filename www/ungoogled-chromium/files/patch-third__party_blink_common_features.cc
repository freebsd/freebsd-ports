--- third_party/blink/common/features.cc.orig	2026-03-15 18:32:51 UTC
+++ third_party/blink/common/features.cc
@@ -619,7 +619,7 @@ BASE_FEATURE(kDevToolsImprovedNetworkError, base::FEAT
 
 BASE_FEATURE(kDirectCompositorThreadIpc,
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -1937,7 +1937,7 @@ BASE_FEATURE(kPrefetchFontLookupTables,
 // currently out of scope.
 BASE_FEATURE(kPreloadingEagerHoverHeuristics,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
