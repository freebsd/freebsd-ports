--- base/allocator/partition_allocator/partition_alloc_constants.h.orig	2020-10-22 20:49:28 UTC
+++ base/allocator/partition_allocator/partition_alloc_constants.h
@@ -150,8 +150,13 @@ static_assert(alignof(std::max_align_t) <= 16,
 //
 // In practice, this means 8 bytes alignment on 32 bit architectures, and 16
 // bytes on 64 bit ones.
+// On FreeBSD i386 alignof(std::max_align_t) is only 4.
+#if defined(__i386__) && defined(OS_FREEBSD)
+static const size_t kGenericMinBucketedOrder = 3;
+#else                                               
 static const size_t kGenericMinBucketedOrder =
     alignof(std::max_align_t) == 16 ? 5 : 4;  // 2^(order - 1), that is 16 or 8.
+#endif
 // The largest bucketed order is 1 << (20 - 1), storing [512 KiB, 1 MiB):
 static const size_t kGenericMaxBucketedOrder = 20;
 static const size_t kGenericNumBucketedOrders =
