--- services/webnn/public/cpp/webnn_sandbox_init.cc.orig	2026-09-25 15:26:43 UTC
+++ services/webnn/public/cpp/webnn_sandbox_init.cc
@@ -10,7 +10,7 @@
 #include "build/build_config.h"
 #include "services/webnn/public/cpp/webnn_buildflags.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <dlfcn.h>
 #endif
 
@@ -22,7 +22,7 @@ void PreSandboxWebNNInitialization() {
   base::FilePath library_path(
       FILE_PATH_LITERAL("libLiteRtWebGpuAccelerator.dll"));
   base::LoadNativeLibrary(library_path, nullptr);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::FilePath library_path;
   if (base::PathService::Get(base::DIR_MODULE, &library_path)) {
     library_path =
