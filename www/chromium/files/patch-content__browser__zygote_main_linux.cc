--- content/browser/zygote_main_linux.cc.orig	2011-09-14 11:01:10.000000000 +0300
+++ content/browser/zygote_main_linux.cc	2011-10-02 15:28:48.000000000 +0300
@@ -57,7 +57,7 @@
 #endif
 
 #if defined(ARCH_CPU_X86_FAMILY) && !defined(CHROMIUM_SELINUX) && \
-    !defined(__clang__)
+    !defined(__clang__) && !defined(OS_FREEBSD)
 // The seccomp sandbox is enabled on all ia32 and x86-64 processor as long as
 // we aren't using SELinux or clang.
 #define SECCOMP_SANDBOX
@@ -720,11 +720,16 @@
     // dumpable.
     const CommandLine& command_line = *CommandLine::ForCurrentProcess();
     if (!command_line.HasSwitch(switches::kAllowSandboxDebugging)) {
+#if !defined(OS_FREEBSD)
       prctl(PR_SET_DUMPABLE, 0, 0, 0, 0);
       if (prctl(PR_GET_DUMPABLE, 0, 0, 0, 0)) {
         LOG(ERROR) << "Failed to set non-dumpable flag";
         return false;
       }
+#else
+      NOTIMPLEMENTED();
+      return false;
+#endif
     }
   } else if (CommandLine::ForCurrentProcess()->HasSwitch(
         switches::kEnableSeccompSandbox)) {
