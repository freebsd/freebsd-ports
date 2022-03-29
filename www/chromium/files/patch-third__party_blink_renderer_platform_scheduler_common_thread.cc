--- third_party/blink/renderer/platform/scheduler/common/thread.cc.orig	2022-03-25 21:59:56 UTC
+++ third_party/blink/renderer/platform/scheduler/common/thread.cc
@@ -99,7 +99,8 @@ void Thread::CreateAndSetCompositorThread() {
       std::make_unique<scheduler::CompositorThread>(params);
   compositor_thread->Init();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+// pledge(2)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && !BUILDFLAG(IS_OPENBSD)
   if (base::FeatureList::IsEnabled(
           features::kBlinkCompositorUseDisplayThreadPriority)) {
     compositor_thread->GetTaskRunner()->PostTaskAndReplyWithResult(
