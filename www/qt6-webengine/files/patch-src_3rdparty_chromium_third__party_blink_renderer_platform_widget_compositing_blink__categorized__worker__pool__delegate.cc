--- src/3rdparty/chromium/third_party/blink/renderer/platform/widget/compositing/blink_categorized_worker_pool_delegate.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/widget/compositing/blink_categorized_worker_pool_delegate.cc
@@ -27,7 +27,7 @@ void BlinkCategorizedWorkerPoolDelegate::NotifyThreadW
 
 void BlinkCategorizedWorkerPoolDelegate::NotifyThreadWillRun(
     base::PlatformThreadId tid) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   scoped_refptr<base::TaskRunner> task_runner =
       Thread::MainThread()->GetTaskRunner(MainThreadTaskRunnerRestricted());
   task_runner->PostTask(FROM_HERE, base::BindOnce(
