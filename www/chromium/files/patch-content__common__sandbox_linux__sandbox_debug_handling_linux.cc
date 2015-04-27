--- content/common/sandbox_linux/sandbox_debug_handling_linux.cc.orig	2015-04-19 22:52:03.000000000 +0200
+++ content/common/sandbox_linux/sandbox_debug_handling_linux.cc	2015-04-19 23:27:21.000000000 +0200
@@ -6,7 +6,9 @@
 
 #include <errno.h>
 #include <signal.h>
+#if 0 // no OS_FREEBSD here?
 #include <sys/prctl.h>
+#endif
 #include <unistd.h>
 
 #include "base/command_line.h"
@@ -68,12 +70,16 @@
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
