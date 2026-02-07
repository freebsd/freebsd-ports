--- services/screen_ai/sandbox/screen_ai_sandbox_hook_linux.cc.orig	2026-01-16 13:40:34 UTC
+++ services/screen_ai/sandbox/screen_ai_sandbox_hook_linux.cc
@@ -69,6 +69,7 @@ bool ScreenAIPreSandboxHook(base::FilePath binary_path
     }
   }
 
+#if !BUILDFLAG(IS_BSD)
   auto* instance = sandbox::policy::SandboxLinux::GetInstance();
 
   std::vector<BrokerFilePermission> permissions{
@@ -90,6 +91,7 @@ bool ScreenAIPreSandboxHook(base::FilePath binary_path
                             sandbox::syscall_broker::COMMAND_OPEN}),
       permissions, options);
   instance->EngageNamespaceSandboxIfPossible();
+#endif
 
   return true;
 }
