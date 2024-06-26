--- base/trace_event/memory_dump_manager.cc.orig	2024-06-25 12:08:48 UTC
+++ base/trace_event/memory_dump_manager.cc
@@ -87,7 +87,7 @@ const char* const MemoryDumpManager::kSystemAllocatorP
 #if defined(MALLOC_MEMORY_TRACING_SUPPORTED)
     MallocDumpProvider::kAllocatedObjects;
 #else
-    nullptr;
+    "";
 #endif
 
 // static
