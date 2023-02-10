--- src/3rdparty/chromium/base/allocator/partition_allocator/partition_address_space.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/base/allocator/partition_allocator/partition_address_space.cc
@@ -184,7 +184,7 @@ void PartitionAddressSpace::UninitConfigurablePoolForT
   setup_.configurable_pool_ = 0;
 }
 
-#if BUILDFLAG(IS_LINUX) && defined(ARCH_CPU_ARM64)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_ARM64)
 
 PageCharacteristics page_characteristics;
 
