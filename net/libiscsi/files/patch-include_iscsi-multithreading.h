--- include/iscsi-multithreading.h.orig	2025-05-03 00:02:42 UTC
+++ include/iscsi-multithreading.h
@@ -46,6 +46,9 @@ typedef uint64_t iscsi_tid_t;
 #endif
 #ifdef HAVE_PTHREAD_THREADID_NP
 typedef uint64_t iscsi_tid_t;
+#elif defined(__FreeBSD__)
+#include <pthread_np.h>
+typedef int iscsi_tid_t;
 #else
 typedef pid_t iscsi_tid_t;
 #endif
