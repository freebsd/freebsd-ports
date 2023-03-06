--- src/3rdparty/chromium/base/allocator/partition_allocator/partition_alloc.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/base/allocator/partition_allocator/partition_alloc.cc
@@ -202,6 +202,9 @@ void PartitionAllocGlobalInit(OomFunction on_out_of_me
   // Check that some of our zanier calculations worked out as expected.
 #if ENABLE_TAG_FOR_MTE_CHECKED_PTR
   static_assert(kSmallestBucket >= kAlignment, "generic smallest bucket");
+#elif defined(__i386__) && defined(OS_FREEBSD)
+  // alignof(std::max_align_t) is only 4 on FreeBSD/i386
+  static_assert(kSmallestBucket >= kAlignment, "generic smallest bucket");
 #else
   static_assert(kSmallestBucket == kAlignment, "generic smallest bucket");
 #endif
