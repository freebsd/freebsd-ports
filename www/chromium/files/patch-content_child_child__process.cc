--- content/child/child_process.cc.orig	2017-06-05 19:03:07 UTC
+++ content/child/child_process.cc
@@ -129,7 +129,7 @@ void ChildProcess::ReleaseProcess() {
     main_thread_->OnProcessFinalRelease();
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 void ChildProcess::SetIOThreadPriority(
     base::ThreadPriority io_thread_priority) {
   main_thread_->SetThreadPriority(io_thread_.GetThreadId(), io_thread_priority);
