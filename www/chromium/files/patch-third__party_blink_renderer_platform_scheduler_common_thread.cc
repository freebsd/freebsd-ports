--- third_party/blink/renderer/platform/scheduler/common/thread.cc.orig	2022-02-07 13:39:41 UTC
+++ third_party/blink/renderer/platform/scheduler/common/thread.cc
@@ -99,7 +99,8 @@ void Thread::CreateAndSetCompositorThread() {
       std::make_unique<scheduler::CompositorThread>(params);
   compositor_thread->Init();
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+// pledge
+#if (defined(OS_LINUX) || defined(OS_CHROMEOS)) && !defined(OS_OPENBSD)
   if (base::FeatureList::IsEnabled(
           features::kBlinkCompositorUseDisplayThreadPriority)) {
     compositor_thread->GetTaskRunner()->PostTaskAndReplyWithResult(
