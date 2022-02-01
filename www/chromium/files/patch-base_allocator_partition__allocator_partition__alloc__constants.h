--- base/allocator/partition_allocator/partition_alloc_constants.h.orig	2022-01-21 12:58:23 UTC
+++ base/allocator/partition_allocator/partition_alloc_constants.h
@@ -349,7 +349,7 @@ constexpr size_t kBitsPerSizeT = sizeof(void*) * CHAR_
 // PartitionPurgeDecommitEmptySlotSpans flag will eagerly decommit all entries
 // in the ring buffer, so with periodic purge enabled, this typically happens
 // every few seconds.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // Set to a higher value on Linux, to assess impact on performance bots. This
 // roughly halves the number of syscalls done during a speedometer 2.0 run on
 // this platform.
