--- base/trace_event/memory_dump_manager.cc.orig	2024-10-01 07:26:23 UTC
+++ base/trace_event/memory_dump_manager.cc
@@ -83,7 +83,7 @@ const char* const MemoryDumpManager::kSystemAllocatorP
 #if defined(MALLOC_MEMORY_TRACING_SUPPORTED)
     MallocDumpProvider::kAllocatedObjects;
 #else
-    nullptr;
+    "";
 #endif
 
 // static
