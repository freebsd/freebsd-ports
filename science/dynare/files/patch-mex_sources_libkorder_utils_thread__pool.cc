-- FreeBSD compatibility: replace std::jthread and std::stop_token (C++20 features not yet
-- available in FreeBSD's libc++) with std::thread and std::atomic<bool> for thread stop
-- signalling.

--- mex/sources/libkorder/utils/thread_pool.cc.orig	2026-05-10 20:43:59 UTC
+++ mex/sources/libkorder/utils/thread_pool.cc
@@ -18,6 +18,7 @@
  */
 
 #include <algorithm>
+#include <atomic>
 #include <cassert>
 #include <condition_variable>
 #include <map>
@@ -45,7 +46,20 @@ std::mutex job_group_mut; // Shared by jobs in the job
 std::map<job*, status> job_group_status;
 std::mutex job_group_mut; // Shared by jobs in the job group
 
-std::vector<std::jthread> threads;
+std::atomic<bool> stop_requested{false};
+std::vector<std::thread> threads;
+// Cleanup guard: destroyed before 'threads', so it joins all threads before they are destructed
+struct Cleanup
+{
+  ~Cleanup()
+  {
+    stop_requested = true;
+    thread_cv.notify_all();
+    for (auto& t : threads)
+      if (t.joinable())
+        t.join();
+  }
+} cleanup_guard;
 } // End of unnamed namespace
 
 void
@@ -64,16 +78,19 @@ initialize(int thread_number)
   if (static_cast<int>(threads.size()) == thread_number)
     return;
   else
-    threads.clear();
+    {
+      // Stop existing threads before clearing the vector
+      stop_requested = true;
+      thread_cv.notify_all();
+      for (auto& t : threads)
+        if (t.joinable())
+          t.join();
+      threads.clear();
+      stop_requested = false;
+    }
 
   for (int i {0}; i < thread_number; i++)
-    /* Passing the stop_token by const reference is ok (and makes clang-tidy happier),
-       since the std::jthread constructor calls the lambda with the return argument of the
-       get_stop_token() method, which returns a stop_token by value; hence there is no lifetime
-       issue. See:
-       https://stackoverflow.com/questions/72990607/const-stdstop-token-or-just-stdstop-token-as-parameter-for-thread-funct
-     */
-    threads.emplace_back([](const std::stop_token& stoken) {
+    threads.emplace_back([]() {
       std::unique_lock lk {global_mut};
       job* selected_job;
       status* selected_job_status;
@@ -90,17 +107,20 @@ initialize(int thread_number)
         return false;
       };
 
-      while (!stoken.stop_requested())
-        if (thread_cv.wait(lk, stoken, pick_job))
-          {
-            lk.unlock();
-            selected_job->operator()(job_group_mut);
-            lk.lock();
+      while (!stop_requested)
+        {
+          thread_cv.wait(lk, [&] { return stop_requested.load() || pick_job(); });
+          if (!stop_requested)
+            {
+              lk.unlock();
+              selected_job->operator()(job_group_mut);
+              lk.lock();
 
-            *selected_job_status = status::done;
+              *selected_job_status = status::done;
 
-            director_cv.notify_one();
-          }
+              director_cv.notify_one();
+            }
+        }
     });
 }
 
