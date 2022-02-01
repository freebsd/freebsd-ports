--- content/ppapi_plugin/ppapi_plugin_main.cc.orig	2021-12-31 00:57:32 UTC
+++ content/ppapi_plugin/ppapi_plugin_main.cc
@@ -50,6 +50,10 @@
 #include "sandbox/policy/linux/sandbox_linux.h"
 #include "sandbox/policy/sandbox_type.h"
 #endif
+#if defined(OS_FREEBSD)
+#include "content/public/common/sandbox_init.h"
+#include "sandbox/policy/freebsd/sandbox_freebsd.h"
+#endif
 
 #ifdef V8_USE_EXTERNAL_STARTUP_DATA
 #include "gin/v8_initializer.h"
@@ -141,6 +145,9 @@ int PpapiPluginMain(const MainFunctionParams& paramete
       sandbox::policy::SandboxTypeFromCommandLine(command_line),
       sandbox::policy::SandboxLinux::PreSandboxHook(),
       sandbox::policy::SandboxLinux::Options());
+#elif defined(OS_FREEBSD)
+  sandbox::policy::SandboxFreeBSD::GetInstance()->InitializeSandbox(
+      sandbox::policy::SandboxTypeFromCommandLine(command_line));
 #endif
 
   ChildProcess ppapi_process;
