--- mailutils/mail.c.orig	2018-12-05 14:44:34 UTC
+++ mailutils/mail.c
@@ -6,7 +6,13 @@
  *
  * Licensed under GPLv2, see file LICENSE in this source tree.
  */
+#ifdef __Linux__
 #include <sys/prctl.h>
+#define PRCTL
+#elif defined(__FreeBSD__)
+#include <sys/procctl.h>
+#define PROCCTL
+#endif
 #include "libbb.h"
 #include "mail.h"
 
@@ -60,7 +66,12 @@ void FAST_FUNC launch_helper(const char 
 	if (!G.helper_pid) {
 		// child
 		// if parent dies, get SIGTERM
-		prctl(PR_SET_PDEATHSIG, SIGTERM, 0, 0, 0);
+		int signum = SIGTERM;
+#ifdef PRCTL
+		prctl(PR_SET_PDEATHSIG, signum, 0, 0, 0);
+#elif defined PROCCTL
+		procctl(P_PID, 0, PROC_PDEATHSIG_CTL, &signum);
+#endif
 		// try to execute connection helper
 		// NB: SIGCHLD & SIGALRM revert to SIG_DFL on exec
 		BB_EXECVP_or_die((char**)argv);
