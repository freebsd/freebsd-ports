--- base/allocator/partition_allocator/partition_address_space.cc.orig	2023-01-11 09:17:16 UTC
+++ base/allocator/partition_allocator/partition_address_space.cc
@@ -432,7 +432,7 @@ void PartitionAddressSpace::UninitPkeyPoolForTesting()
 }
 #endif
 
-#if BUILDFLAG(IS_LINUX) && defined(ARCH_CPU_ARM64)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_ARM64)
 
 PageCharacteristics page_characteristics;
 
