--- src/scrun/anchor.c.orig	2023-11-21 22:33:29 UTC
+++ src/scrun/anchor.c
@@ -43,7 +43,12 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <sys/param.h>
+#ifdef __FreeBSD__
+#include <pthread_np.h>
+#include <sys/signal.h>
+#else
 #include <sys/prctl.h>
+#endif
 #include <sys/socket.h>
 #include <sys/stat.h>
 #include <sys/types.h>
@@ -1034,7 +1039,11 @@ static void _set_proctitle()
 
 	setproctitle("%s", state.id);
 	xstrfmtcat(thread_name, "scrun:%s", state.id);
+#ifdef __FreeBSD__
+	if (pthread_setname_np(pthread_self(), thread_name) < 0) {
+#else
 	if (prctl(PR_SET_NAME, thread_name, NULL, NULL, NULL) < 0) {
+#endif
 		fatal("Unable to set process name");
 	}
 	xfree(thread_name);
