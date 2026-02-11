--- src/engine.cpp.orig	2026-02-10 19:57:51 UTC
+++ src/engine.cpp
@@ -69,7 +69,7 @@ Engine::Engine()
     // Configure a TBB task arena to limit parallelism a little (use half the available CPU cores, or at least 6
     // threads) This avoids having too many parallel downloads on high-core-count machines, and also leaves some room
     // for additional parallelism of the used libraries, e.g. for image processing.
-    const auto numCPU = std::thread::hardware_concurrency();
+    const std::int32_t numCPU = std::thread::hardware_concurrency();
     const auto maxThreads = std::max((long)numCPU > 6 ? 6L : numCPU, std::lround(numCPU * 0.60));
     m_taskArena = std::make_unique<tbb::task_arena>(maxThreads);
 
