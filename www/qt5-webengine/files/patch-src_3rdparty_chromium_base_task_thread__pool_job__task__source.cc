--- src/3rdparty/chromium/base/task/thread_pool/job_task_source.cc.orig	2023-11-09 11:32:20 UTC
+++ src/3rdparty/chromium/base/task/thread_pool/job_task_source.cc
@@ -29,8 +29,9 @@ static_assert(
 constexpr size_t kMaxWorkersPerJob = 32;
 static_assert(
     kMaxWorkersPerJob <=
-        std::numeric_limits<std::result_of<
-            decltype (&JobDelegate::GetTaskId)(JobDelegate)>::type>::max(),
+        std::numeric_limits<
+            std::invoke_result<decltype(&JobDelegate::GetTaskId),
+                               JobDelegate>::type>::max(),
     "AcquireTaskId return type isn't big enough to fit kMaxWorkersPerJob");
 
 }  // namespace
