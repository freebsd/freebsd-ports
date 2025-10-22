--- base/allocator/partition_allocator/src/partition_alloc/partition_root.h.orig	2025-10-21 16:57:35 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/partition_root.h
@@ -202,7 +202,7 @@ struct PartitionOptions {
   // system to configure PartitionAlloc.
   EnableToggle fewer_memory_regions =
 #if PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_ANDROID) || \
-    PA_BUILDFLAG(IS_CHROMEOS)
+    PA_BUILDFLAG(IS_CHROMEOS) || PA_BUILDFLAG(IS_BSD)
       kEnabled;
 #else
       kDisabled;
