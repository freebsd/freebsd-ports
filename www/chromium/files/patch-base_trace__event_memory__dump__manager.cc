--- base/trace_event/memory_dump_manager.cc.orig	2026-04-09 06:05:42 UTC
+++ base/trace_event/memory_dump_manager.cc
@@ -96,7 +96,7 @@ const char* const MemoryDumpManager::kSystemAllocatorP
 #if defined(MALLOC_MEMORY_TRACING_SUPPORTED)
     MallocDumpProvider::kAllocatedObjects;
 #else
-    nullptr;
+    "";
 #endif
 
 // static
