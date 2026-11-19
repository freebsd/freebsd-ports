--- services/webnn/public/cpp/webnn_sandbox_init.cc.orig	2026-11-19 12:25:27 UTC
+++ services/webnn/public/cpp/webnn_sandbox_init.cc
@@ -13,7 +13,7 @@
 #include "services/webnn/public/cpp/webnn_buildflags.h"
 #include "services/webnn/public/mojom/features.mojom-features.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <dlfcn.h>
 #endif
 
@@ -21,7 +21,7 @@ namespace webnn {
 
 void PreSandboxWebNNInitialization(bool is_gpu_process) {
 #if BUILDFLAG(WEBNN_USE_WEBGPU_ACCELERATOR) && \
-    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX))
+    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
 #if BUILDFLAG(IS_WIN)
   if (!base::FeatureList::IsEnabled(
           webnn::mojom::features::kWebMachineLearningNeuralNetwork)) {
@@ -40,7 +40,7 @@ void PreSandboxWebNNInitialization(bool is_gpu_process
 
   constexpr base::FilePath::StringViewType kLibraryName =
       FILE_PATH_LITERAL("libLiteRtWebGpuAccelerator.dll");
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Linux, the library is preloaded once in the Zygote process during
   // PreSandboxInit(), allowing all forked renderers to share the library
   // pages via copy-on-write without repeating initialization. The Zygote
@@ -59,7 +59,7 @@ void PreSandboxWebNNInitialization(bool is_gpu_process
 
 #if BUILDFLAG(IS_WIN)
   base::LoadNativeLibrary(library_path, nullptr);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   dlopen(library_path.value().c_str(), RTLD_LAZY | RTLD_LOCAL | RTLD_NODELETE);
 #endif
 #endif  // BUILDFLAG(WEBNN_USE_WEBGPU_ACCELERATOR) && (BUILDFLAG(IS_WIN) ||
