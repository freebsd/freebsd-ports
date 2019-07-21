--- src/srun/libsrun/srun_job.c.orig	2019-05-28 17:23:14 UTC
+++ src/srun/libsrun/srun_job.c
@@ -117,6 +117,11 @@ static int pty_sigarray[] = { SIGWINCH, 0 };
 
 extern char **environ;
 
+#ifdef __FreeBSD__
+#define __environ environ
+extern char **environ;
+#endif
+
 /*
  * Prototypes:
  */
