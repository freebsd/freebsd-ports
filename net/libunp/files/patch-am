--- lib/wrappthread.c.orig	Thu Sep 30 11:06:22 1999
+++ lib/wrappthread.c	Thu Sep 30 11:06:34 1999
@@ -40,17 +40,6 @@
 }
 
 void
-Pthread_kill(pthread_t tid, int signo)
-{
-	int		n;
-
-	if ( (n = pthread_kill(tid, signo)) == 0)
-		return;
-	errno = n;
-	err_sys("pthread_kill error");
-}
-
-void
 Pthread_mutexattr_init(pthread_mutexattr_t *attr)
 {
 	int		n;
