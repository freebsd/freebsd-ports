--- content/renderer/render_process_impl.cc.orig	2023-12-10 06:10:27 UTC
+++ content/renderer/render_process_impl.cc
@@ -47,7 +47,7 @@
 #if BUILDFLAG(IS_WIN)
 #include "base/win/win_util.h"
 #endif
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && defined(ARCH_CPU_X86_64)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_X86_64)
 #include "v8/include/v8-wasm-trap-handler-posix.h"
 #endif
 
@@ -224,7 +224,7 @@ RenderProcessImpl::RenderProcessImpl()
     v8::V8::SetFlagsFromString(kSABPerContextFlag, sizeof(kSABPerContextFlag));
   }
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && defined(ARCH_CPU_X86_64)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_X86_64)
   if (base::FeatureList::IsEnabled(features::kWebAssemblyTrapHandler)) {
     base::CommandLine* const command_line =
         base::CommandLine::ForCurrentProcess();
