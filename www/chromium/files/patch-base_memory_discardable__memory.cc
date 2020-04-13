--- base/memory/discardable_memory.cc.orig	2020-02-07 10:23:12 UTC
+++ base/memory/discardable_memory.cc
@@ -23,7 +23,7 @@ const base::Feature kMadvFreeDiscardableMemory{
     "MadvFreeDiscardableMemory", base::FEATURE_DISABLED_BY_DEFAULT};
 #endif  // defined(OS_POSIX)
 
-#if defined(OS_ANDROID) || defined(OS_LINUX)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
 const base::Feature kDiscardableMemoryBackingTrial{
     "DiscardableMemoryBackingTrial", base::FEATURE_DISABLED_BY_DEFAULT};
 
@@ -41,13 +41,13 @@ const base::FeatureParam<DiscardableMemoryTrialGroup>
         DiscardableMemoryTrialGroup::kEmulatedSharedMemory,
         &kDiscardableMemoryBackingParamOptions};
 
-#endif  // defined(OS_ANDROID) || defined(OS_LINUX)
+#endif  // defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
 
 }  // namespace features
 
 namespace {
 
-#if defined(OS_ANDROID) || defined(OS_LINUX)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
 
 DiscardableMemoryBacking GetBackingForFieldTrial() {
   DiscardableMemoryTrialGroup trial_group =
@@ -61,11 +61,11 @@ DiscardableMemoryBacking GetBackingForFieldTrial() {
   }
   NOTREACHED();
 }
-#endif  // defined(OS_ANDROID) || defined(OS_LINUX)
+#endif  // defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
 
 }  // namespace
 
-#if defined(OS_ANDROID) || defined(OS_LINUX)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
 
 // Probe capabilities of this device to determine whether we should participate
 // in the discardable memory backing trial.
@@ -87,18 +87,18 @@ DiscardableMemoryTrialGroup GetDiscardableMemoryBackin
   DCHECK(DiscardableMemoryBackingFieldTrialIsEnabled());
   return features::kDiscardableMemoryBackingParam.Get();
 }
-#endif  // defined(OS_ANDROID) || defined(OS_LINUX)
+#endif  // defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
 
 DiscardableMemory::DiscardableMemory() = default;
 
 DiscardableMemory::~DiscardableMemory() = default;
 
 DiscardableMemoryBacking GetDiscardableMemoryBacking() {
-#if defined(OS_ANDROID) || defined(OS_LINUX)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
   if (DiscardableMemoryBackingFieldTrialIsEnabled()) {
     return GetBackingForFieldTrial();
   }
-#endif  // defined(OS_ANDROID) || defined(OS_LINUX)
+#endif  // defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_ANDROID)
   if (ashmem_device_is_supported())
