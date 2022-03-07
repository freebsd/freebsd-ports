--- platform-tracing.c.orig	2022-03-07 14:48:27.152541000 -0800
+++ platform-tracing.c	2022-03-07 14:56:33.402458000 -0800
@@ -32,6 +32,9 @@
 #include <stdarg.h>
 #include <stdio.h>
 #include <string.h>
+#if defined(HAVE_PROCCTL)
+#include <unistd.h>
+#endif
 
 #include "log.h"
 
@@ -42,7 +45,7 @@ platform_disable_tracing(int strict)
 	/* On FreeBSD, we should make this process untraceable */
 	int disable_trace = PROC_TRACE_CTL_DISABLE;
 
-	if (procctl(P_PID, 0, PROC_TRACE_CTL, &disable_trace) && strict)
+	if (procctl(P_PID, getpid(), PROC_TRACE_CTL, &disable_trace) && strict)
 		fatal("unable to make the process untraceable: %s",
 		    strerror(errno));
 #endif
