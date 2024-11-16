--- third_party/blink/renderer/platform/scheduler/common/thread.cc.orig	2024-11-14 07:57:23 UTC
+++ third_party/blink/renderer/platform/scheduler/common/thread.cc
@@ -87,7 +87,7 @@ void Thread::CreateAndSetCompositorThread() {
             "Compositor");
       }));
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && !BUILDFLAG(IS_OPENBSD)
   compositor_thread->GetTaskRunner()->PostTaskAndReplyWithResult(
       FROM_HERE, base::BindOnce(&base::PlatformThread::CurrentId),
       base::BindOnce([](base::PlatformThreadId compositor_thread_id) {
