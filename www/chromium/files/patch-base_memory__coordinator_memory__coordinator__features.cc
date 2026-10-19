--- base/memory_coordinator/memory_coordinator_features.cc.orig	2026-10-18 13:29:39 UTC
+++ base/memory_coordinator/memory_coordinator_features.cc
@@ -9,7 +9,7 @@
 namespace base {
 
 BASE_FEATURE(kStatefulMemoryPressure,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
