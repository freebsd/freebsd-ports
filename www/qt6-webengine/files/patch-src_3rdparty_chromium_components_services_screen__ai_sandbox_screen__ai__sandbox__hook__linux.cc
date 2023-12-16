--- src/3rdparty/chromium/components/services/screen_ai/sandbox/screen_ai_sandbox_hook_linux.cc.orig	2023-04-05 11:05:06 UTC
+++ src/3rdparty/chromium/components/services/screen_ai/sandbox/screen_ai_sandbox_hook_linux.cc
@@ -53,6 +53,7 @@ bool ScreenAIPreSandboxHook(sandbox::policy::SandboxLi
     }
   }
 
+#if !BUILDFLAG(IS_BSD)
   auto* instance = sandbox::policy::SandboxLinux::GetInstance();
 
   std::vector<BrokerFilePermission> permissions{
@@ -76,6 +77,7 @@ bool ScreenAIPreSandboxHook(sandbox::policy::SandboxLi
                             sandbox::syscall_broker::COMMAND_OPEN}),
       permissions, sandbox::policy::SandboxLinux::PreSandboxHook(), options);
   instance->EngageNamespaceSandboxIfPossible();
+#endif
 
   return true;
 }
