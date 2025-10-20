--- src/engine.cpp.orig	2025-10-02 19:33:23 UTC
+++ src/engine.cpp
@@ -35,6 +35,7 @@
 
 #include <tbb/parallel_for.h>
 #include <tbb/parallel_for_each.h>
+#include <tbb/parallel_invoke.h>
 #include <tbb/blocked_range.h>
 #include <tbb/task_arena.h>
 #include <inja/inja.hpp>
@@ -68,7 +69,7 @@ Engine::Engine()
     // Configure a TBB task arena to limit parallelism a little (use half the available CPU cores, or at least 6
     // threads) This avoids having too many parallel downloads on high-core-count machines, and also leaves some room
     // for additional parallelism of the used libraries, e.g. for image processing.
-    const auto numCPU = std::thread::hardware_concurrency();
+    std::int32_t const numCPU = std::thread::hardware_concurrency();
     const auto maxThreads = std::max(numCPU > 6 ? 6L : numCPU, std::lround(numCPU * 0.60));
     m_taskArena = std::make_unique<tbb::task_arena>(maxThreads);
 
