--- content/common/sandbox_linux/sandbox_debug_handling_linux.cc.orig	2017-06-05 19:03:07 UTC
+++ content/common/sandbox_linux/sandbox_debug_handling_linux.cc
@@ -7,7 +7,9 @@
 #include <errno.h>
 #include <signal.h>
 #include <stddef.h>
+#if 0 // no OS_FREEBSD here?
 #include <sys/prctl.h>
+#endif
 #include <unistd.h>
 
 #include "base/command_line.h"
@@ -69,12 +71,16 @@ bool SandboxDebugHandling::SetDumpableStatusAndHandler
     return true;
   }
 
+#if 0 // no OS_FREEBSD here?
   if (prctl(PR_SET_DUMPABLE, 0) != 0) {
     PLOG(ERROR) << "Failed to set non-dumpable flag";
     return false;
   }
 
   return prctl(PR_GET_DUMPABLE) == 0;
+#else
+  return false;
+#endif
 }
 
 }  // namespace content
