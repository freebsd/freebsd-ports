--- third_party/blink/renderer/platform/scheduler/common/thread.cc.orig	2021-07-19 18:45:22 UTC
+++ third_party/blink/renderer/platform/scheduler/common/thread.cc
@@ -99,7 +99,7 @@ void Thread::CreateAndSetCompositorThread() {
       std::make_unique<scheduler::CompositorThread>(params);
   compositor_thread->Init();
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   if (base::FeatureList::IsEnabled(
           features::kBlinkCompositorUseDisplayThreadPriority)) {
     compositor_thread->GetTaskRunner()->PostTaskAndReplyWithResult(
