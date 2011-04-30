--- content/browser/zygote_main_linux.cc.orig	2011-04-15 11:01:10.000000000 +0300
+++ content/browser/zygote_main_linux.cc	2011-04-16 21:45:54.101069128 +0300
@@ -2,12 +2,18 @@
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
 
+#include "build/build_config.h"
+
 #include <dlfcn.h>
 #include <fcntl.h>
 #include <pthread.h>
+#if defined(OS_FREEBSD)
+#include <signal.h>
+#else
 #include <sys/epoll.h>
 #include <sys/prctl.h>
 #include <sys/signal.h>
+#endif
 #include <sys/socket.h>
 #include <sys/stat.h>
 #include <sys/types.h>
@@ -51,7 +57,7 @@
 #include "unicode/timezone.h"
 
 #if defined(ARCH_CPU_X86_FAMILY) && !defined(CHROMIUM_SELINUX) && \
-    !defined(__clang__)
+    !defined(__clang__) && !defined(OS_FREEBSD)
 // The seccomp sandbox is enabled on all ia32 and x86-64 processor as long as
 // we aren't using SELinux or clang.
 #define SECCOMP_SANDBOX
@@ -174,6 +180,11 @@
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
@@ -648,7 +659,7 @@
 
     SkiaFontConfigSetImplementation(
         new FontConfigIPC(kMagicSandboxIPCDescriptor));
-
+#if !defined(OS_FREEBSD)
     // Previously, we required that the binary be non-readable. This causes the
     // kernel to mark the process as non-dumpable at startup. The thinking was
     // that, although we were putting the renderers into a PID namespace (with
@@ -674,6 +685,7 @@
         return false;
       }
     }
+#endif  // !OS_FREEBSD
   } else if (CommandLine::ForCurrentProcess()->HasSwitch(
         switches::kEnableSeccompSandbox)) {
     PreSandboxInit();
