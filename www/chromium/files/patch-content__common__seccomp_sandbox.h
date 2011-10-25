--- content/common/seccomp_sandbox.h.orig	2011-10-10 20:30:54.487723398 +0000
+++ content/common/seccomp_sandbox.h	2011-10-10 20:31:27.083734776 +0000
@@ -18,7 +18,8 @@
 #include "content/common/content_switches.h"
 
 #if defined(ARCH_CPU_X86_FAMILY) && !defined(CHROMIUM_SELINUX) && \
-  !defined(__clang__) && !defined(OS_CHROMEOS) && !defined(TOOLKIT_VIEWS)
+  !defined(__clang__) && !defined(OS_CHROMEOS) && !defined(TOOLKIT_VIEWS) && \
+  !defined(OS_FREEBSD)
 #define SECCOMP_SANDBOX
 #include "seccompsandbox/sandbox.h"
 #endif
