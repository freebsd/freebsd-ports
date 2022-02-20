--- content/renderer/renderer_main_platform_delegate_linux.cc.orig	2022-02-07 13:39:41 UTC
+++ content/renderer/renderer_main_platform_delegate_linux.cc
@@ -45,6 +45,7 @@ bool RendererMainPlatformDelegate::EnableSandbox() {
   // any renderer has been started.
   // Here, we test that the status of SeccompBpf in the renderer is consistent
   // with what SandboxLinux::GetStatus() said we would do.
+#if !defined(OS_BSD)
   auto* linux_sandbox = sandbox::policy::SandboxLinux::GetInstance();
   if (linux_sandbox->GetStatus() & sandbox::policy::SandboxLinux::kSeccompBPF) {
     CHECK(linux_sandbox->seccomp_bpf_started());
@@ -66,6 +67,7 @@ bool RendererMainPlatformDelegate::EnableSandbox() {
     CHECK_EQ(errno, EPERM);
   }
 #endif  // __x86_64__
+#endif
 
   return true;
 }
