--- src/base/trace_event/memory_dump_manager.cc.orig	2026-10-18 18:43:23 UTC
+++ src/base/trace_event/memory_dump_manager.cc
@@ -86,7 +86,7 @@ const char* const MemoryDumpManager::kSy
 #if defined(MALLOC_MEMORY_TRACING_SUPPORTED)
     MallocDumpProvider::kAllocatedObjects;
 #else
-    nullptr;
+    "";
 #endif
 
 // static
