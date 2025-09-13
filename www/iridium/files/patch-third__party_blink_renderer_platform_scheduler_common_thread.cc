--- third_party/blink/renderer/platform/scheduler/common/thread.cc.orig	2025-09-11 13:19:19 UTC
+++ third_party/blink/renderer/platform/scheduler/common/thread.cc
@@ -95,7 +95,7 @@ void Thread::CreateAndSetCompositorThread() {
           // the program's lifetime once assigned.
           base::Unretained(compositor_thread.get())));
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && !BUILDFLAG(IS_OPENBSD)
   compositor_thread->GetTaskRunner()->PostTaskAndReplyWithResult(
       FROM_HERE, base::BindOnce(&base::PlatformThread::CurrentId),
       base::BindOnce([](base::PlatformThreadId compositor_thread_id) {
