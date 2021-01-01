--- base/allocator/partition_allocator/partition_alloc_unittest.cc.orig	2020-03-23 15:20:45 UTC
+++ base/allocator/partition_allocator/partition_alloc_unittest.cc
@@ -314,9 +314,13 @@ void FreeFullPage(PartitionPage* page) {
   }
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 bool CheckPageInCore(void* ptr, bool in_core) {
+#if defined(OS_BSD)
+  char ret = 0;
+#else
   unsigned char ret = 0;
+#endif
   EXPECT_EQ(0, mincore(ptr, kSystemPageSize, &ret));
   return in_core == (ret & 1);
 }
