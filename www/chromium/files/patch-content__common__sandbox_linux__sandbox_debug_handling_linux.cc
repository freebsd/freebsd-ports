--- content/common/sandbox_linux/sandbox_debug_handling_linux.cc.orig	2016-03-04 22:42:42.203612627 +0100
+++ content/common/sandbox_linux/sandbox_debug_handling_linux.cc	2016-03-04 22:43:36.442729525 +0100
@@ -7,7 +7,9 @@
 #include <errno.h>
 #include <signal.h>
 #include <stddef.h>
+#if 0 // no OS_FREEBSD here?
 #include <sys/prctl.h>
+#endif
 #include <unistd.h>
 
 #include "base/command_line.h"
@@ -69,12 +71,16 @@
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
