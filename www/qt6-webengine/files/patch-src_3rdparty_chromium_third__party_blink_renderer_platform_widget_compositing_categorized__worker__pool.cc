--- src/3rdparty/chromium/third_party/blink/renderer/platform/widget/compositing/categorized_worker_pool.cc.orig	2023-03-09 06:31:50 UTC
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/widget/compositing/categorized_worker_pool.cc
@@ -242,7 +242,7 @@ void CategorizedWorkerPoolImpl::Start(int max_concurre
       "CompositorTileWorkerBackground", thread_options, this,
       background_thread_prio_categories,
       &has_task_for_background_priority_thread_cv_);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   thread->SetBackgroundingCallback(
       Thread::MainThread()->GetTaskRunner(MainThreadTaskRunnerRestricted()),
       base::BindOnce([](base::PlatformThreadId thread_id) {
