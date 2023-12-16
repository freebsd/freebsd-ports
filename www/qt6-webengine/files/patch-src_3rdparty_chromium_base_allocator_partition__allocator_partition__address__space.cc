--- src/3rdparty/chromium/base/allocator/partition_allocator/partition_address_space.cc.orig	2023-04-05 11:05:06 UTC
+++ src/3rdparty/chromium/base/allocator/partition_allocator/partition_address_space.cc
@@ -417,7 +417,7 @@ void PartitionAddressSpace::UninitPkeyPoolForTesting()
 }
 #endif
 
-#if BUILDFLAG(IS_LINUX) && defined(ARCH_CPU_ARM64)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_ARM64)
 
 PageCharacteristics page_characteristics;
 
