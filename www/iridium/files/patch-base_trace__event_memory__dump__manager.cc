--- base/trace_event/memory_dump_manager.cc.orig	2026-04-15 12:07:04 UTC
+++ base/trace_event/memory_dump_manager.cc
@@ -96,7 +96,7 @@ const char* const MemoryDumpManager::kSystemAllocatorP
 #if defined(MALLOC_MEMORY_TRACING_SUPPORTED)
     MallocDumpProvider::kAllocatedObjects;
 #else
-    nullptr;
+    "";
 #endif
 
 // static
