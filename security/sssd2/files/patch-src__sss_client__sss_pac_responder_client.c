--- src/sss_client/sss_pac_responder_client.c.orig	2023-05-05 08:11:07 UTC
+++ src/sss_client/sss_pac_responder_client.c
@@ -23,6 +23,7 @@
 #include <unistd.h>
 #include <sys/types.h>
 #include <errno.h>
+#include <pthread_np.h>
 
 #include <sys/syscall.h>
 
@@ -97,7 +98,7 @@ static void *pac_client(void *arg)
     size_t c;
 
     fprintf(stderr, "[%"SPRItime"][%d][%ld][%s] started\n",
-            time(NULL), getpid(), syscall(SYS_gettid), (char *) arg);
+            time(NULL), getpid(), pthread_getthreadid_np(), (char *) arg);
     for (c = 0; c < 1000; c++) {
         /* sss_pac_make_request() does not protect the client's file
          * descriptor to the PAC responder. With this one thread will miss a
