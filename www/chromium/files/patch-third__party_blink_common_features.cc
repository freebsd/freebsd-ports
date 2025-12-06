--- third_party/blink/common/features.cc.orig	2025-12-05 10:12:50 UTC
+++ third_party/blink/common/features.cc
@@ -588,7 +588,7 @@ BASE_FEATURE_PARAM(base::TimeDelta,
 BASE_FEATURE(kDevToolsImprovedNetworkError, base::FEATURE_DISABLED_BY_DEFAULT);
 
 BASE_FEATURE(kDirectCompositorThreadIpc,
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -1946,7 +1946,7 @@ BASE_FEATURE(kPrefetchFontLookupTables,
 // currently out of scope.
 BASE_FEATURE(kPreloadingEagerHoverHeuristics,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
