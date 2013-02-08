--- content/renderer/renderer_main_platform_delegate_linux.cc.orig	2012-11-27 10:01:25.000000000 +0200
+++ content/renderer/renderer_main_platform_delegate_linux.cc	2012-12-10 22:47:50.000000000 +0200
@@ -42,11 +42,14 @@
   //
   // The seccomp sandbox mode 1 (sandbox/linux/seccomp-legacy) and mode 2
   // (sandbox/linux/seccomp-bpf) are started in InitializeSandbox().
+#if !defined(OS_BSD)
   InitializeSandbox();
+#endif
   return true;
 }
 
 void RendererMainPlatformDelegate::RunSandboxTests(bool no_sandbox) {
+#if !defined(OS_BSD)
   // The LinuxSandbox class requires going through initialization before
   // GetStatus() and others can be used.  When we are not launched through the
   // Zygote, this initialization will only happen in the renderer process if
@@ -81,6 +84,7 @@
     CHECK_EQ(errno, EPERM);
   }
 #endif  // __x86_64__
+#endif
 }
 
 }  // namespace content
