--- content/browser/zygote_main_linux.cc.orig	2011-10-07 11:31:44.000000000 +0300
+++ content/browser/zygote_main_linux.cc	2011-10-08 22:11:46.609222627 +0300
@@ -727,11 +727,16 @@
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
 #if defined(SECCOMP_SANDBOX)
   } else if (SeccompSandboxEnabled()) {
