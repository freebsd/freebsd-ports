--- content/renderer/render_process_impl.cc.orig	2021-07-19 18:45:16 UTC
+++ content/renderer/render_process_impl.cc
@@ -48,7 +48,7 @@
 #if defined(OS_WIN)
 #include "base/win/win_util.h"
 #endif
-#if (defined(OS_LINUX) || defined(OS_CHROMEOS)) && defined(ARCH_CPU_X86_64)
+#if (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) && defined(ARCH_CPU_X86_64)
 #include "v8/include/v8-wasm-trap-handler-posix.h"
 #endif
 namespace {
@@ -142,12 +142,12 @@ RenderProcessImpl::RenderProcessImpl()
   SetV8FlagIfNotFeature(features::kWebAssemblyCodeProtection,
                         "--no-wasm-write-protect-code-memory");
 
-#if defined(OS_LINUX) && defined(ARCH_CPU_X86_64)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && defined(ARCH_CPU_X86_64)
   SetV8FlagIfFeature(features::kWebAssemblyCodeProtectionPku,
                      "--wasm-memory-protection-keys");
   SetV8FlagIfNotFeature(features::kWebAssemblyCodeProtectionPku,
                         "--no-wasm-memory-protection-keys");
-#endif  // defined(OS_LINUX) && defined(ARCH_CPU_X86_64)
+#endif  // (defined(OS_LINUX) || defined(OS_BSD)) && defined(ARCH_CPU_X86_64)
 
   SetV8FlagIfFeature(features::kWebAssemblyLazyCompilation,
                      "--wasm-lazy-compilation");
@@ -207,7 +207,7 @@ RenderProcessImpl::RenderProcessImpl()
 
   SetV8FlagIfNotFeature(features::kWebAssemblyTrapHandler,
                         "--no-wasm-trap-handler");
-#if (defined(OS_LINUX) || defined(OS_CHROMEOS)) && defined(ARCH_CPU_X86_64)
+#if (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) && defined(ARCH_CPU_X86_64)
   if (base::FeatureList::IsEnabled(features::kWebAssemblyTrapHandler)) {
     if (command_line->HasSwitch(switches::kEnableCrashpad) ||
         command_line->HasSwitch(switches::kEnableCrashReporter) ||
