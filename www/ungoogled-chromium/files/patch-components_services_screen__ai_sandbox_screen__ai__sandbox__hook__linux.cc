--- components/services/screen_ai/sandbox/screen_ai_sandbox_hook_linux.cc.orig	2023-01-13 08:56:02 UTC
+++ components/services/screen_ai/sandbox/screen_ai_sandbox_hook_linux.cc
@@ -34,6 +34,7 @@ bool ScreenAIPreSandboxHook(sandbox::policy::SandboxLi
     }
   }
 
+#if !BUILDFLAG(IS_BSD)
   auto* instance = sandbox::policy::SandboxLinux::GetInstance();
 
   std::vector<BrokerFilePermission> permissions{
@@ -52,6 +53,7 @@ bool ScreenAIPreSandboxHook(sandbox::policy::SandboxLi
                             sandbox::syscall_broker::COMMAND_OPEN}),
       permissions, sandbox::policy::SandboxLinux::PreSandboxHook(), options);
   instance->EngageNamespaceSandboxIfPossible();
+#endif
 
   return true;
 }
