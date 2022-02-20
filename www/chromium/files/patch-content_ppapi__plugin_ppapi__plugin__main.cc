--- content/ppapi_plugin/ppapi_plugin_main.cc.orig	2022-02-07 13:39:41 UTC
+++ content/ppapi_plugin/ppapi_plugin_main.cc
@@ -54,6 +54,12 @@
 #include "gin/v8_initializer.h"
 #endif
 
+#if defined(OS_OPENBSD)
+#include "content/public/common/sandbox_init.h"
+#include "sandbox/policy/openbsd/sandbox_openbsd.h"
+#include "sandbox/policy/sandbox_type.h"
+#endif
+
 #if defined(OS_POSIX) && !defined(OS_ANDROID)
 #include <stdlib.h>
 #endif
@@ -135,7 +141,7 @@ int PpapiPluginMain(MainFunctionParams parameters) {
   gin::V8Initializer::LoadV8Snapshot();
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_OPENBSD)
   sandbox::policy::SandboxLinux::GetInstance()->InitializeSandbox(
       sandbox::policy::SandboxTypeFromCommandLine(command_line),
       sandbox::policy::SandboxLinux::PreSandboxHook(),
