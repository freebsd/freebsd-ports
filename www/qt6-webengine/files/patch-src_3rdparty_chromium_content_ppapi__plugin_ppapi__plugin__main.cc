--- src/3rdparty/chromium/content/ppapi_plugin/ppapi_plugin_main.cc.orig	2023-02-08 09:03:45 UTC
+++ src/3rdparty/chromium/content/ppapi_plugin/ppapi_plugin_main.cc
@@ -54,6 +54,11 @@
 #include "gin/v8_initializer.h"
 #endif
 
+#if BUILDFLAG(IS_OPENBSD)
+#include "sandbox/policy/openbsd/sandbox_openbsd.h"
+#include "sandbox/policy/sandbox_type.h"
+#endif
+
 #if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_ANDROID)
 #include <stdlib.h>
 #endif
@@ -148,7 +153,7 @@ int PpapiPluginMain(MainFunctionParams parameters) {
   gin::V8Initializer::LoadV8Snapshot();
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OPENBSD)
   sandbox::policy::SandboxLinux::GetInstance()->InitializeSandbox(
       sandbox::policy::SandboxTypeFromCommandLine(command_line),
       sandbox::policy::SandboxLinux::PreSandboxHook(),
