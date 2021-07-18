--- base/memory/discardable_memory_internal.h.orig	2021-04-14 18:40:48 UTC
+++ base/memory/discardable_memory_internal.h
@@ -10,7 +10,7 @@
 #include "base/metrics/field_trial_params.h"
 #include "build/build_config.h"
 
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 namespace base {
 
@@ -47,6 +47,6 @@ GetDiscardableMemoryBackingFieldTrialGroup();
 
 }  // namespace base
 
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 
 #endif  //  BASE_MEMORY_DISCARDABLE_MEMORY_INTERNAL_H_
