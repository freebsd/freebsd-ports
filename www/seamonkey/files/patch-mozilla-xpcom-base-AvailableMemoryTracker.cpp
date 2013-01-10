--- mozilla/xpcom/base/AvailableMemoryTracker.cpp~
+++ mozilla/xpcom/base/AvailableMemoryTracker.cpp
@@ -499,6 +499,6 @@ nsJemallocFreeDirtyPagesRunnable::Run()
   MOZ_ASSERT(NS_IsMainThread());
 
 #if defined(MOZ_JEMALLOC)
-  mallctl("arenas.purge", nullptr, 0, nullptr, 0);
+//  mallctl("arenas.purge", nullptr, 0, nullptr, 0);
 #elif defined(MOZ_MEMORY)
   jemalloc_free_dirty_pages();
