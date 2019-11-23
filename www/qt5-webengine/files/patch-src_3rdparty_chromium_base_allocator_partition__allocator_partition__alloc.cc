--- src/3rdparty/chromium/base/allocator/partition_allocator/partition_alloc.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/base/allocator/partition_allocator/partition_alloc.cc
@@ -440,7 +440,7 @@ static size_t PartitionPurgePage(internal::PartitionPa
 #endif
       }
       // Terminate the freelist chain.
-      *entry_ptr = nullptr;
+      *entry_ptr = internal::PartitionFreelistEntry::Transform(nullptr);
       // The freelist head is stored unmasked.
       page->freelist_head =
           internal::PartitionFreelistEntry::Transform(page->freelist_head);
