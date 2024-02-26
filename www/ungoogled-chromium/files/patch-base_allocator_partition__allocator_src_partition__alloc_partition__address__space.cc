--- base/allocator/partition_allocator/src/partition_alloc/partition_address_space.cc.orig	2024-02-25 20:22:18 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/partition_address_space.cc
@@ -421,7 +421,7 @@ void PartitionAddressSpace::UninitThreadIsolatedPoolFo
 }
 #endif
 
-#if (BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)) && defined(ARCH_CPU_ARM64)
+#if (BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_ARM64)
 
 PageCharacteristics page_characteristics;
 
