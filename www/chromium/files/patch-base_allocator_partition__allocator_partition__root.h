--- base/allocator/partition_allocator/partition_root.h.orig	2022-02-28 16:54:41 UTC
+++ base/allocator/partition_allocator/partition_root.h
@@ -1019,7 +1019,7 @@ ALWAYS_INLINE void PartitionRoot<thread_safe>::FreeNoH
   // essentially).
 #if BUILDFLAG(USE_PARTITION_ALLOC_AS_MALLOC) &&              \
     ((BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_CHROMECAST)) || \
-     (BUILDFLAG(IS_LINUX) && defined(ARCH_CPU_64_BITS)))
+     ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_64_BITS)))
   PA_CHECK(IsManagedByPartitionAlloc(address));
 #endif
 
