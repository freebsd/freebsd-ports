--- content/common/seccomp_sandbox.h.orig	2012-07-18 10:01:27.000000000 +0300
+++ content/common/seccomp_sandbox.h	2012-07-25 21:10:12.000000000 +0300
@@ -18,7 +18,7 @@
 #include "content/public/common/content_switches.h"
 
 #if defined(ARCH_CPU_X86_FAMILY) && !defined(CHROMIUM_SELINUX) && \
-  !defined(OS_CHROMEOS) && !defined(TOOLKIT_VIEWS) && !defined(OS_OPENBSD)
+  !defined(OS_CHROMEOS) && !defined(TOOLKIT_VIEWS) && !defined(OS_BSD)
 #define SECCOMP_SANDBOX
 #include "seccompsandbox/sandbox.h"
 #endif
