--- base/trace_event/memory_dump_manager.cc.orig	2025-12-10 15:04:57 UTC
+++ base/trace_event/memory_dump_manager.cc
@@ -79,7 +79,7 @@ const char* const MemoryDumpManager::kSystemAllocatorP
 #if defined(MALLOC_MEMORY_TRACING_SUPPORTED)
     MallocDumpProvider::kAllocatedObjects;
 #else
-    nullptr;
+    "";
 #endif
 
 // static
