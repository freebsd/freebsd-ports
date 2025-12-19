--- src/3rdparty/chromium/base/allocator/partition_allocator/src/partition_alloc/page_allocator_internals_posix.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/base/allocator/partition_allocator/src/partition_alloc/page_allocator_internals_posix.cc
@@ -39,7 +39,7 @@ uint32_t SecTaskGetCodeSignStatus(SecTaskRef task) API
 
 #if PA_BUILDFLAG(HAS_MEMORY_TAGGING) ||                                        \
     (defined(__ARM_FEATURE_BTI_DEFAULT) && (__ARM_FEATURE_BTI_DEFAULT == 1) && \
-     __has_include(<sys/ifunc.h>))
+     __has_include(<sys/ifunc.h>) && !PA_BUILDFLAG(IS_BSD))
 struct __ifunc_arg_t;
 
 #include "partition_alloc/aarch64_support.h"
