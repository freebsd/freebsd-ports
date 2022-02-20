--- base/allocator/partition_allocator/partition_root.h.orig	2022-02-07 13:39:41 UTC
+++ base/allocator/partition_allocator/partition_root.h
@@ -1044,7 +1044,7 @@ ALWAYS_INLINE void PartitionRoot<thread_safe>::FreeNoH
   // essentially).
 #if BUILDFLAG(USE_PARTITION_ALLOC_AS_MALLOC) &&            \
     ((defined(OS_ANDROID) && !BUILDFLAG(IS_CHROMECAST)) || \
-     (defined(OS_LINUX) && defined(ARCH_CPU_64_BITS)))
+     ((defined(OS_LINUX) || defined(OS_BSD)) && defined(ARCH_CPU_64_BITS)))
   PA_CHECK(IsManagedByPartitionAlloc(reinterpret_cast<uintptr_t>(ptr)));
 #endif
 
