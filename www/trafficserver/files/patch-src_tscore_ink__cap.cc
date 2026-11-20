--- src/tscore/ink_cap.cc.orig	2026-10-19 23:11:17 UTC
+++ src/tscore/ink_cap.cc
@@ -28,6 +28,10 @@
 #include <sys/capability.h>
 #endif
 
+#if __has_include(<sys/procctl.h>)
+#include <sys/procctl.h>
+#endif
+
 #if __has_include(<sys/prctl.h>)
 #include <sys/prctl.h>
 #endif
@@ -364,6 +368,10 @@ EnableDeathSignal([[maybe_unused]] int signum)
 #if defined(PR_SET_PDEATHSIG)
   if (prctl(PR_SET_PDEATHSIG, signum, 0, 0, 0) != 0) {
     Dbg(dbg_ctl_privileges, "prctl(PR_SET_PDEATHSIG) failed: %s", strerror(errno));
+  }
+#elif defined(PROC_PDEATHSIG_CTL)
+  if (procctl(P_PID, 0, PROC_PDEATHSIG_CTL, &signum) != 0) {
+    Dbg(dbg_ctl_privileges, "procctl(PROC_PDEATHSIG_CTL) failed: %s", strerror(errno));
   }
 #endif
 }
