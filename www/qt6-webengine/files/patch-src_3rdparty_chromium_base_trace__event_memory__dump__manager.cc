--- src/3rdparty/chromium/base/trace_event/memory_dump_manager.cc.orig	2024-09-30 07:45:04 UTC
+++ src/3rdparty/chromium/base/trace_event/memory_dump_manager.cc
@@ -83,7 +83,7 @@ const char* const MemoryDumpManager::kSystemAllocatorP
 #if defined(MALLOC_MEMORY_TRACING_SUPPORTED)
     MallocDumpProvider::kAllocatedObjects;
 #else
-    nullptr;
+    "";
 #endif
 
 // static
