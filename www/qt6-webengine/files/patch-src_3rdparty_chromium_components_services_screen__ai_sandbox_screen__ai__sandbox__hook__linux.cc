--- src/3rdparty/chromium/components/services/screen_ai/sandbox/screen_ai_sandbox_hook_linux.cc.orig	2023-03-28 19:45:02 UTC
+++ src/3rdparty/chromium/components/services/screen_ai/sandbox/screen_ai_sandbox_hook_linux.cc
@@ -36,6 +36,7 @@ bool ScreenAIPreSandboxHook(sandbox::policy::SandboxLi
   }
   screen_ai::StoreComponentBinaryPath(library_path);
 
+#if !BUILDFLAG(IS_BSD)
   auto* instance = sandbox::policy::SandboxLinux::GetInstance();
 
   std::vector<BrokerFilePermission> permissions{
@@ -59,6 +60,7 @@ bool ScreenAIPreSandboxHook(sandbox::policy::SandboxLi
                             sandbox::syscall_broker::COMMAND_OPEN}),
       permissions, sandbox::policy::SandboxLinux::PreSandboxHook(), options);
   instance->EngageNamespaceSandboxIfPossible();
+#endif
 
   return true;
 }
