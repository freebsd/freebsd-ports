--- base/allocator/partition_allocator/partition_alloc.cc.orig	2022-10-29 17:50:56 UTC
+++ base/allocator/partition_allocator/partition_alloc.cc
@@ -67,8 +67,13 @@ void PartitionAllocGlobalInit(OomFunction on_out_of_me
       "maximum direct mapped allocation");
 
   // Check that some of our zanier calculations worked out as expected.
+#if defined(__i386__) && defined(OS_FREEBSD)
+  static_assert(internal::kSmallestBucket >= internal::kAlignment,
+                "generic smallest bucket");
+#else
   static_assert(internal::kSmallestBucket == internal::kAlignment,
                 "generic smallest bucket");
+#endif
   static_assert(internal::kMaxBucketed == 983040, "generic max bucketed");
   STATIC_ASSERT_OR_PA_CHECK(
       internal::MaxSystemPagesPerRegularSlotSpan() <= 16,
