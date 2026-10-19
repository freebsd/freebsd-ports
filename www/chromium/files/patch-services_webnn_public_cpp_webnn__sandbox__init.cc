--- services/webnn/public/cpp/webnn_sandbox_init.cc.orig	2026-10-18 13:29:39 UTC
+++ services/webnn/public/cpp/webnn_sandbox_init.cc
@@ -12,7 +12,7 @@
 #include "services/webnn/public/cpp/webnn_buildflags.h"
 #include "services/webnn/public/mojom/features.mojom-features.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <dlfcn.h>
 #endif
 
@@ -34,7 +34,7 @@ void PreSandboxWebNNInitialization(bool is_gpu_process
   base::FilePath library_path(
       FILE_PATH_LITERAL("libLiteRtWebGpuAccelerator.dll"));
   base::LoadNativeLibrary(library_path, nullptr);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Linux, the library is preloaded once in the Zygote process during
   // PreSandboxInit(), allowing all forked renderers to share the library
   // pages via copy-on-write without repeating initialization. The Zygote
