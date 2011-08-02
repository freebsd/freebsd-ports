--- content/browser/zygote_main_linux.cc.orig	2011-06-24 11:30:33.000000000 +0300
+++ content/browser/zygote_main_linux.cc	2011-06-26 21:25:52.734780676 +0300
@@ -58,7 +58,7 @@
 #endif
 
 #if defined(ARCH_CPU_X86_FAMILY) && !defined(CHROMIUM_SELINUX) && \
-    !defined(__clang__)
+    !defined(__clang__) && !defined(OS_FREEBSD)
 // The seccomp sandbox is enabled on all ia32 and x86-64 processor as long as
 // we aren't using SELinux or clang.
 #define SECCOMP_SANDBOX
@@ -181,6 +181,11 @@
         case ZygoteHost::kCmdGetSandboxStatus:
           HandleGetSandboxStatus(fd, pickle, iter);
           return false;
+#if defined(OS_FREEBSD)
+        case ZygoteHost::kCmdEnd:
+          _exit(0);
+          return false;
+#endif
         default:
           NOTREACHED();
           break;
@@ -667,7 +672,7 @@
 
     SkiaFontConfigSetImplementation(
         new FontConfigIPC(kMagicSandboxIPCDescriptor));
-
+#if !defined(OS_FREEBSD)
     // Previously, we required that the binary be non-readable. This causes the
     // kernel to mark the process as non-dumpable at startup. The thinking was
     // that, although we were putting the renderers into a PID namespace (with
@@ -693,6 +698,7 @@
         return false;
       }
     }
+#endif  // !OS_FREEBSD
   } else if (CommandLine::ForCurrentProcess()->HasSwitch(
         switches::kEnableSeccompSandbox)) {
     PreSandboxInit();
