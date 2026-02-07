--- lib/wrappthread.c.orig	1997-06-27 22:04:01 UTC
+++ lib/wrappthread.c
@@ -40,17 +40,6 @@ Pthread_detach(pthread_t tid)
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
