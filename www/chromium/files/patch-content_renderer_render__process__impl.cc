--- content/renderer/render_process_impl.cc.orig	2020-05-13 18:40:32 UTC
+++ content/renderer/render_process_impl.cc
@@ -44,7 +44,7 @@
 #if defined(OS_WIN)
 #include "base/win/win_util.h"
 #endif
-#if defined(OS_LINUX) && defined(ARCH_CPU_X86_64)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && defined(ARCH_CPU_X86_64)
 #include "v8/include/v8-wasm-trap-handler-posix.h"
 #endif
 namespace {
@@ -162,7 +162,7 @@ RenderProcessImpl::RenderProcessImpl()
 
   SetV8FlagIfNotFeature(features::kWebAssemblyTrapHandler,
                         "--no-wasm-trap-handler");
-#if defined(OS_LINUX) && defined(ARCH_CPU_X86_64)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && defined(ARCH_CPU_X86_64)
   if (base::FeatureList::IsEnabled(features::kWebAssemblyTrapHandler)) {
     base::CommandLine* command_line = base::CommandLine::ForCurrentProcess();
     if (!command_line->HasSwitch(
