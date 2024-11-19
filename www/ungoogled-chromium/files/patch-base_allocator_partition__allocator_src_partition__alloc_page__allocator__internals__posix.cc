--- base/allocator/partition_allocator/src/partition_alloc/page_allocator_internals_posix.cc.orig	2024-11-16 12:20:41 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/page_allocator_internals_posix.cc
@@ -38,7 +38,7 @@ uint32_t SecTaskGetCodeSignStatus(SecTaskRef task) API
 #endif  // PA_BUILDFLAG(IS_MAC)
 
 #if PA_BUILDFLAG(HAS_MEMORY_TAGGING) || \
-    (defined(__ARM_FEATURE_BTI_DEFAULT) && (__ARM_FEATURE_BTI_DEFAULT == 1))
+    (defined(__ARM_FEATURE_BTI_DEFAULT) && (__ARM_FEATURE_BTI_DEFAULT == 1) && !PA_BUILDFLAG(IS_BSD))
 struct __ifunc_arg_t;
 
 #include "partition_alloc/aarch64_support.h"
