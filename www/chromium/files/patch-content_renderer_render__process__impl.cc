--- content/renderer/render_process_impl.cc.orig	2019-06-04 18:55:23 UTC
+++ content/renderer/render_process_impl.cc
@@ -161,7 +161,7 @@ RenderProcessImpl::RenderProcessImpl(
 
   SetV8FlagIfNotFeature(features::kWebAssemblyTrapHandler,
                         "--no-wasm-trap-handler");
-#if defined(OS_LINUX) && defined(ARCH_CPU_X86_64)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && defined(ARCH_CPU_X86_64)
   if (base::FeatureList::IsEnabled(features::kWebAssemblyTrapHandler)) {
     bool use_v8_signal_handler = false;
     base::CommandLine* command_line = base::CommandLine::ForCurrentProcess();
