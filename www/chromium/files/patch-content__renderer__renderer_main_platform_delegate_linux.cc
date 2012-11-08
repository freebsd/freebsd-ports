--- content/renderer/renderer_main_platform_delegate_linux.cc.orig	2012-10-31 21:01:36.000000000 +0200
+++ content/renderer/renderer_main_platform_delegate_linux.cc	2012-11-07 17:38:32.000000000 +0200
@@ -34,7 +34,9 @@
   //
   // The seccomp sandbox mode 1 (sandbox/linux/seccomp-legacy) and mode 2
   // (sandbox/linux/seccomp-bpf) are started in InitializeSandbox().
+#if !defined(OS_BSD)
   content::InitializeSandbox();
+#endif
   return true;
 }
 
