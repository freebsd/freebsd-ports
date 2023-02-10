--- base/allocator/partition_allocator/partition_address_space.cc.orig	2023-02-08 09:03:45 UTC
+++ base/allocator/partition_allocator/partition_address_space.cc
@@ -440,7 +440,7 @@ void PartitionAddressSpace::UninitPkeyPoolForTesting()
 }
 #endif
 
-#if BUILDFLAG(IS_LINUX) && defined(ARCH_CPU_ARM64)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_ARM64)
 
 PageCharacteristics page_characteristics;
 
