--- extras/Mesa/src/X86/common_x86.c.orig	Fri Aug 17 11:40:11 2001
+++ extras/Mesa/src/X86/common_x86.c	Tue Dec  3 21:51:31 2002
@@ -38,6 +38,10 @@
 #if defined(USE_KATMAI_ASM) && defined(__linux__)
 #include <signal.h>
 #endif
+#if defined(USE_KATMAI_ASM) && defined(__FreeBSD__)
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#endif
 
 #include "context.h"
 #include "common_x86_asm.h"
@@ -213,8 +217,17 @@
    message( "Cannot test OS support for SSE, disabling to be safe.\n" );
    gl_x86_cpu_features &= ~(X86_FEATURE_XMM);
 #endif /* _POSIX_SOURCE && X86_FXSR_MAGIC */
+#elif defined(__FreeBSD__)
+   {
+      int ret, enabled;
+      size_t len;
+      len = sizeof(enabled);
+      ret = sysctlbyname("hw.instruction_sse", &enabled, &len, NULL, 0);
+      if (ret || !enabled)
+         gl_x86_cpu_features &= ~(X86_FEATURE_XMM);
+   }
 #else
-   /* Do nothing on non-Linux platforms for now.
+   /* Do nothing on other platforms for now.
     */
    message( "Not testing OS support for SSE, leaving enabled.\n" );
 #endif /* __linux__ */
