--- base/allocator/partition_allocator/partition_alloc.cc.orig	2021-01-18 21:28:44 UTC
+++ base/allocator/partition_allocator/partition_alloc.cc
@@ -65,6 +65,9 @@ void PartitionAllocGlobalInit(OomFunction on_out_of_me
   // Check that some of our zanier calculations worked out as expected.
 #if ENABLE_TAG_FOR_MTE_CHECKED_PTR
   static_assert(kSmallestBucket >= kAlignment, "generic smallest bucket");
+#elif defined(__i386__) && defined(OS_FREEBSD)
+  // alignof(std::max_align_t) is only 4 on FreeBSD/i386
+  static_assert(kSmallestBucket >= kAlignment, "generic smallest bucket");
 #else
   static_assert(kSmallestBucket == kAlignment, "generic smallest bucket");
 #endif
