--- base/allocator/allocator_extension.cc	2013-07-03 23:39:54.000000000 -0400
+++ base/allocator/allocator_extension.cc	2013-07-19 00:39:26.000000000 -0400
@@ -35,20 +35,20 @@
 void SetGetAllocatorWasteSizeFunction(
     thunks::GetAllocatorWasteSizeFunction get_allocator_waste_size_function) {
   DCHECK_EQ(thunks::GetGetAllocatorWasteSizeFunction(),
-            reinterpret_cast<thunks::GetAllocatorWasteSizeFunction>(NULL));
+            static_cast<thunks::GetAllocatorWasteSizeFunction>(0));
   thunks::SetGetAllocatorWasteSizeFunction(get_allocator_waste_size_function);
 }
 
 void SetGetStatsFunction(thunks::GetStatsFunction get_stats_function) {
   DCHECK_EQ(thunks::GetGetStatsFunction(),
-            reinterpret_cast<thunks::GetStatsFunction>(NULL));
+            static_cast<thunks::GetStatsFunction>(0));
   thunks::SetGetStatsFunction(get_stats_function);
 }
 
 void SetReleaseFreeMemoryFunction(
     thunks::ReleaseFreeMemoryFunction release_free_memory_function) {
   DCHECK_EQ(thunks::GetReleaseFreeMemoryFunction(),
-            reinterpret_cast<thunks::ReleaseFreeMemoryFunction>(NULL));
+            static_cast<thunks::ReleaseFreeMemoryFunction>(0));
   thunks::SetReleaseFreeMemoryFunction(release_free_memory_function);
 }
 
