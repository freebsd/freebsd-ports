-- FreeBSD compatibility: replace std::jthread and std::stop_token (C++20 features not yet
-- available in FreeBSD's libc++ as of clang 19) with std::thread and std::atomic<bool> for
-- thread stop signalling in the dynare preprocessor's MEX parallel compilation worker pool.

--- preprocessor/src/ModelTree.hh.orig	2025-03-19 00:00:00 UTC
+++ preprocessor/src/ModelTree.hh	2025-03-19 00:00:00 UTC
@@ -22,6 +22,7 @@
 
 #include <array>
 #include <cassert>
+#include <atomic>
 #include <condition_variable>
 #include <deque>
 #include <filesystem>
@@ -441,8 +442,14 @@
   vector<int> endo2eq;
 
   // Stores workers used for compiling MEX files in parallel
-  static vector<jthread> mex_compilation_workers;
+  static vector<thread> mex_compilation_workers;
+  static atomic<bool> mex_compilation_stop_requested;
 
+public:
+  static void stopMEXCompilationWorkers();
+
+private:
+
   /* The following variables implement the thread synchronization mechanism for
      limiting the number of concurrent GCC processes and tracking dependencies
      between object files. */
