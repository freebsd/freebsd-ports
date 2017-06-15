--- content/child/child_process.cc.orig	2017-04-19 19:06:33 UTC
+++ content/child/child_process.cc
@@ -133,7 +133,7 @@ void ChildProcess::ReleaseProcess() {
     main_thread_->OnProcessFinalRelease();
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 void ChildProcess::SetIOThreadPriority(
     base::ThreadPriority io_thread_priority) {
   main_thread_->SetThreadPriority(io_thread_.GetThreadId(), io_thread_priority);
