--- src/3rdparty/chromium/base/memory/discardable_memory_internal.h.orig	2020-11-07 01:22:36 UTC
+++ src/3rdparty/chromium/base/memory/discardable_memory_internal.h
@@ -10,7 +10,7 @@
 #include "base/metrics/field_trial_params.h"
 #include "build/build_config.h"
 
-#if defined(OS_ANDROID) || defined(OS_LINUX)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
 
 namespace base {
 
@@ -47,6 +47,6 @@ GetDiscardableMemoryBackingFieldTrialGroup();
 
 }  // namespace base
 
-#endif  // defined(OS_LINUX) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 
 #endif  //  BASE_MEMORY_DISCARDABLE_MEMORY_INTERNAL_H_
