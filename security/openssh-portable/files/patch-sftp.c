--- sftp.c.orig	2021-09-10 10:43:58.802512000 -0700
+++ sftp.c	2021-09-10 10:44:19.707367000 -0700
@@ -252,12 +252,14 @@ cmd_interrupt(int signo)
 	errno = olderrno;
 }
 
+#ifdef USE_LIBEDIT
 /* ARGSUSED */
 static void
 read_interrupt(int signo)
 {
 	interrupted = 1;
 }
+#endif
 
 /*ARGSUSED*/
 static void
