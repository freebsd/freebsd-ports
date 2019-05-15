--- src/srun/libsrun/srun_job.c.orig	2018-10-24 20:21:46 UTC
+++ src/srun/libsrun/srun_job.c
@@ -113,6 +113,11 @@ static int shepherd_fd = -1;
 static pthread_t signal_thread = (pthread_t) 0;
 static int pty_sigarray[] = { SIGWINCH, 0 };
 
+#ifdef __FreeBSD__
+#define __environ environ
+extern char **environ;
+#endif
+
 /*
  * Prototypes:
  */
