--- src/gp_creds.c.orig	2026-07-21 10:43:49 UTC
+++ src/gp_creds.c
@@ -3,7 +3,11 @@
 #include "config.h"
 #include <stdio.h>
 #include <sys/socket.h>
+#ifdef __FreeBSD__
+#include <pthread_np.h>
+#else
 #include <sys/syscall.h>
+#endif
 #include <sys/types.h>
 #include <errno.h>
 #include <string.h>
@@ -267,10 +271,14 @@ static int ensure_segregated_ccache(struct gp_call_ctx
         return ENOMEM;
     }
 
+#ifdef __FreeBSD__
+    tid = pthread_getthreadid_np();
+#else
     do {
         errno = 0;
         tid = syscall(SYS_gettid);
     } while (tid == -1 && errno == EINTR);
+#endif
 
     ret = asprintf(&buf, "MEMORY:internal_%d", tid);
     if (ret == -1) {
