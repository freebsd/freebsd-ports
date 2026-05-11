-- FreeBSD compatibility: replace std::jthread and std::stop_token (C++20 features not yet
-- available in FreeBSD's libc++ as of clang 19) with std::thread and std::atomic<bool> for
-- thread stop signalling in the dynare preprocessor's MEX parallel compilation worker pool.
-- Also adds a RAII MEXWorkersJoiner struct to safely join threads on program exit.

--- preprocessor/src/DynareMain.cc.orig	2025-03-19 00:00:00 UTC
+++ preprocessor/src/DynareMain.cc	2025-03-19 00:00:00 UTC
@@ -511,7 +511,7 @@
     }
 
   if (mod_file->use_dll)
-    ModelTree::initializeMEXCompilationWorkers(max(jthread::hardware_concurrency(), 1U), dynareroot,
+    ModelTree::initializeMEXCompilationWorkers(max(thread::hardware_concurrency(), 1U), dynareroot,
                                                mexext);
 
   if (json == JsonOutputPointType::parsing)
