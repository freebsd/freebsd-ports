--- base/trace_event/memory_dump_manager.cc.orig	2026-02-16 10:45:29 UTC
+++ base/trace_event/memory_dump_manager.cc
@@ -84,7 +84,7 @@ const char* const MemoryDumpManager::kSystemAllocatorP
 #if defined(MALLOC_MEMORY_TRACING_SUPPORTED)
     MallocDumpProvider::kAllocatedObjects;
 #else
-    nullptr;
+    "";
 #endif
 
 // static
