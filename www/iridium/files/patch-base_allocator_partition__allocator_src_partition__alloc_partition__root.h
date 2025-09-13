--- base/allocator/partition_allocator/src/partition_alloc/partition_root.h.orig	2025-09-11 13:19:19 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/partition_root.h
@@ -197,7 +197,7 @@ struct PartitionOptions {
   // system to configure PartitionAlloc.
   EnableToggle fewer_memory_regions =
 #if PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_ANDROID) || \
-    PA_BUILDFLAG(IS_CHROMEOS)
+    PA_BUILDFLAG(IS_CHROMEOS) || PA_BUILDFLAG(IS_BSD)
       kEnabled;
 #else
       kDisabled;
