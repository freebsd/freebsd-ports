--- components/services/screen_ai/sandbox/screen_ai_sandbox_hook_linux.cc.orig	2022-04-21 18:48:31 UTC
+++ components/services/screen_ai/sandbox/screen_ai_sandbox_hook_linux.cc
@@ -30,6 +30,7 @@ bool ScreenAIPreSandboxHook(sandbox::policy::SandboxLi
   if (!screen_ai_library)
     VLOG(1) << dlerror();
 
+#if !BUILDFLAG(IS_BSD)
   auto* instance = sandbox::policy::SandboxLinux::GetInstance();
 
   std::vector<BrokerFilePermission> permissions{
@@ -41,6 +42,7 @@ bool ScreenAIPreSandboxHook(sandbox::policy::SandboxLi
                             sandbox::syscall_broker::COMMAND_OPEN}),
       permissions, sandbox::policy::SandboxLinux::PreSandboxHook(), options);
   instance->EngageNamespaceSandboxIfPossible();
+#endif
 
   return true;
 }
