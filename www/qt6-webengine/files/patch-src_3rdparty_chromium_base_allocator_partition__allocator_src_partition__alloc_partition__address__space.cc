--- src/3rdparty/chromium/base/allocator/partition_allocator/src/partition_alloc/partition_address_space.cc.orig	2024-02-23 21:04:38 UTC
+++ src/3rdparty/chromium/base/allocator/partition_allocator/src/partition_alloc/partition_address_space.cc
@@ -421,7 +421,7 @@ void PartitionAddressSpace::UninitThreadIsolatedPoolFo
 }
 #endif
 
-#if (BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)) && defined(ARCH_CPU_ARM64)
+#if (BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_ARM64)
 
 PageCharacteristics page_characteristics;
 
