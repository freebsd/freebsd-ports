--- components/crash/content/app/crashpad_linux.cc.orig	2019-12-19 16:47:28 UTC
+++ components/crash/content/app/crashpad_linux.cc
@@ -5,7 +5,9 @@
 #include "components/crash/content/app/crashpad.h"
 
 #include <pthread.h>
+#if !defined(OS_BSD)
 #include <sys/prctl.h>
+#endif
 
 #include <limits>
 
@@ -66,9 +68,11 @@ void SetPtracerAtFork() {
   if (!GetHandlerSocket(nullptr, &pid)) {
     return;
   }
+#if !defined(OS_BSD)
   if (pid > 0 && prctl(PR_SET_PTRACER, pid, 0, 0, 0) != 0) {
     PLOG(ERROR) << "prctl";
   }
+#endif
 }
 
 namespace internal {
