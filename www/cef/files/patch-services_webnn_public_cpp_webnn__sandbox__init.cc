--- services/webnn/public/cpp/webnn_sandbox_init.cc.orig	2026-08-31 10:59:09 UTC
+++ services/webnn/public/cpp/webnn_sandbox_init.cc
@@ -9,20 +9,20 @@
 #include "base/path_service.h"
 #include "services/webnn/public/cpp/webnn_buildflags.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <dlfcn.h>
 #endif
 
 namespace webnn {
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void PreSandboxWebNNInitialization() {
 #if BUILDFLAG(WEBNN_USE_WEBGPU_ACCELERATOR)
 #if BUILDFLAG(IS_WIN)
   base::FilePath library_path(
       FILE_PATH_LITERAL("libLiteRtWebGpuAccelerator.dll"));
   base::LoadNativeLibrary(library_path, nullptr);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::FilePath library_path;
   if (base::PathService::Get(base::DIR_MODULE, &library_path)) {
     library_path =
