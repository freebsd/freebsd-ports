--- content/common/seccomp_sandbox.h.orig	2012-01-18 11:11:41.000000000 +0200
+++ content/common/seccomp_sandbox.h	2012-01-29 17:00:42.000000000 +0200
@@ -19,7 +19,7 @@
 
 #if defined(ARCH_CPU_X86_FAMILY) && !defined(CHROMIUM_SELINUX) && \
   !defined(__clang__) && !defined(OS_CHROMEOS) && !defined(TOOLKIT_VIEWS) && \
-  !defined(OS_OPENBSD)
+  !defined(OS_BSD)
 #define SECCOMP_SANDBOX
 #include "seccompsandbox/sandbox.h"
 #endif
