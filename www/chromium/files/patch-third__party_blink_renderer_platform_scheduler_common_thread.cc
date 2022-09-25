--- third_party/blink/renderer/platform/scheduler/common/thread.cc.orig	2022-09-24 10:57:32 UTC
+++ third_party/blink/renderer/platform/scheduler/common/thread.cc
@@ -86,7 +86,7 @@ void Thread::CreateAndSetCompositorThread() {
       std::make_unique<scheduler::CompositorThread>(params);
   compositor_thread->Init();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && !BUILDFLAG(IS_OPENBSD)
   compositor_thread->GetTaskRunner()->PostTaskAndReplyWithResult(
       FROM_HERE, base::BindOnce(&base::PlatformThread::CurrentId),
       base::BindOnce([](base::PlatformThreadId compositor_thread_id) {
