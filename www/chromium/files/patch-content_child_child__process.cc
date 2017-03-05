--- content/child/child_process.cc.orig	2017-02-02 02:02:53 UTC
+++ content/child/child_process.cc
@@ -103,7 +103,7 @@ void ChildProcess::ReleaseProcess() {
     main_thread_->OnProcessFinalRelease();
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 void ChildProcess::SetIOThreadPriority(
     base::ThreadPriority io_thread_priority) {
   main_thread_->SetThreadPriority(io_thread_.GetThreadId(), io_thread_priority);
