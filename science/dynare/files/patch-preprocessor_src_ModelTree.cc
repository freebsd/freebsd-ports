-- FreeBSD compatibility: replace std::jthread and std::stop_token (C++20 features not yet
-- available in FreeBSD's libc++ as of clang 19) with std::thread and std::atomic<bool> for
-- thread stop signalling in the dynare preprocessor's MEX parallel compilation worker pool.
-- Also adds a RAII MEXWorkersJoiner struct to safely join threads on program exit.

--- preprocessor/src/ModelTree.cc.orig	2025-03-19 00:00:00 UTC
+++ preprocessor/src/ModelTree.cc	2025-03-19 00:00:00 UTC
@@ -47,7 +47,18 @@
 vector<tuple<filesystem::path, set<filesystem::path>, string>> ModelTree::mex_compilation_queue;
 set<filesystem::path> ModelTree::mex_compilation_ongoing, ModelTree::mex_compilation_done,
     ModelTree::mex_compilation_failed;
-vector<jthread> ModelTree::mex_compilation_workers;
+/* NB: stop_requested must be listed *before* workers so it is destroyed *after*
+   workers are joined (reverse destruction order). Workers rely on stop_requested
+   being valid while they run. */
+atomic<bool> ModelTree::mex_compilation_stop_requested{false};
+vector<thread> ModelTree::mex_compilation_workers;
+/* Declared after workers so it is destroyed first; its destructor signals all
+   worker threads to stop and joins them before the vector destructor runs
+   (which would call std::terminate on still-joinable threads). */
+static const struct MEXWorkersJoiner
+{
+  ~MEXWorkersJoiner() { ModelTree::stopMEXCompilationWorkers(); }
+} mex_workers_joiner;
 
 void
 ModelTree::copyHelper(const ModelTree& m)
@@ -1961,13 +1972,7 @@
   cout << "Spawning " << numworkers << " threads for compiling MEX files." << '\n';
 
   for (int i {0}; i < numworkers; i++)
-    /* Passing the stop_token by const reference is ok (and makes clang-tidy happier),
-       since the std::jthread constructor calls the lambda with the return argument of the
-       get_stop_token() method, which returns a stop_token by value; hence there is no lifetime
-       issue. See:
-       https://stackoverflow.com/questions/72990607/const-stdstop-token-or-just-stdstop-token-as-parameter-for-thread-funct
-     */
-    mex_compilation_workers.emplace_back([](const stop_token& stoken) {
+    mex_compilation_workers.emplace_back([] {
       unique_lock lk {mex_compilation_mut};
       filesystem::path output;
       string cmd;
@@ -1989,23 +1994,27 @@
         return false;
       };
 
-      while (!stoken.stop_requested())
-        if (mex_compilation_cv.wait(lk, stoken, pick_job))
-          {
-            lk.unlock();
-            int r {system(cmd.c_str())};
-            lk.lock();
-            mex_compilation_ongoing.erase(output);
-            if (r)
-              mex_compilation_failed.insert(output);
-            else
-              mex_compilation_done.insert(output);
-            /* The object just compiled may be a prerequisite for several
-               other objects, so notify all waiting workers. Also needed to
-               notify the main thread when in
-               ModelTree::waitForMEXCompilationWorkers().*/
-            mex_compilation_cv.notify_all();
-          }
+      while (!mex_compilation_stop_requested)
+        {
+          mex_compilation_cv.wait(lk, [&pick_job] {
+            return mex_compilation_stop_requested.load() || pick_job();
+          });
+          if (mex_compilation_stop_requested)
+            break;
+          lk.unlock();
+          int r {system(cmd.c_str())};
+          lk.lock();
+          mex_compilation_ongoing.erase(output);
+          if (r)
+            mex_compilation_failed.insert(output);
+          else
+            mex_compilation_done.insert(output);
+          /* The object just compiled may be a prerequisite for several
+             other objects, so notify all waiting workers. Also needed to
+             notify the main thread when in
+             ModelTree::waitForMEXCompilationWorkers().*/
+          mex_compilation_cv.notify_all();
+        }
     });
 
   /* Set some environment variables needed for compilation on Windows/MATLAB
@@ -2062,12 +2071,22 @@
       for (const auto& p : mex_compilation_failed)
         cerr << p.string() << " ";
       cerr << '\n';
-      lk.unlock(); // So that threads can process their stoken
+      lk.unlock(); // Release lock so worker threads can exit
       exit(EXIT_FAILURE);
     }
 }
 
 void
+ModelTree::stopMEXCompilationWorkers()
+{
+  mex_compilation_stop_requested = true;
+  mex_compilation_cv.notify_all();
+  for (auto& w : mex_compilation_workers)
+    if (w.joinable())
+      w.join();
+}
+
+void
 ModelTree::computingPassBlock(const eval_context_t& eval_context, bool no_tmp_terms)
 {
   if (!heterogeneity_table.empty())
