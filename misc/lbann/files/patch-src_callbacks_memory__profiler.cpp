--- src/callbacks/memory_profiler.cpp.orig	2023-11-08 01:08:28 UTC
+++ src/callbacks/memory_profiler.cpp
@@ -158,7 +158,7 @@ struct MemUsage
   size_t total_mem;
 
   MemUsage(const std::string& r, size_t m) : report(r), total_mem(m) {}
-  bool operator<(const MemUsage& other) { return total_mem < other.total_mem; }
+  bool operator<(const MemUsage& other) const { return total_mem < other.total_mem; }
 };
 } // namespace
 
