--- src/3rdparty/chromium/base/allocator/partition_allocator/partition_page.h.orig	2023-04-05 11:05:06 UTC
+++ src/3rdparty/chromium/base/allocator/partition_allocator/partition_page.h
@@ -143,7 +143,7 @@ struct SlotSpanMetadata {
   // PartitionPageSize() is 4 times the OS page size.
   static constexpr size_t kMaxSlotsPerSlotSpan =
       4 * (1 << 14) / kSmallestBucket;
-#elif BUILDFLAG(IS_LINUX) && defined(ARCH_CPU_ARM64)
+#elif (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_ARM64)
   // System page size can be 4, 16, or 64 kiB on Linux on arm64. 64 kiB is
   // currently (kMaxSlotsPerSlotSpanBits == 13) not supported by the code,
   // so we use the 16 kiB maximum (64 kiB will crash).
