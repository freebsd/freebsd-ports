--- src/3rdparty/chromium/components/services/screen_ai/sandbox/screen_ai_sandbox_hook_linux.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/components/services/screen_ai/sandbox/screen_ai_sandbox_hook_linux.cc
@@ -35,6 +35,7 @@ bool ScreenAIPreSandboxHook(sandbox::policy::SandboxLi
       VLOG(2) << "Screen AI library loaded pre-sandboxing:" << library_path;
   }
 
+#if !BUILDFLAG(IS_BSD)
   auto* instance = sandbox::policy::SandboxLinux::GetInstance();
 
   std::vector<BrokerFilePermission> permissions{
@@ -46,6 +47,7 @@ bool ScreenAIPreSandboxHook(sandbox::policy::SandboxLi
                             sandbox::syscall_broker::COMMAND_OPEN}),
       permissions, sandbox::policy::SandboxLinux::PreSandboxHook(), options);
   instance->EngageNamespaceSandboxIfPossible();
+#endif
 
   return true;
 }
