
$FreeBSD$

--- pan/queue.c	2001/09/14 13:20:29	1.1
+++ pan/queue.c	2001/09/14 13:20:44
@@ -1202,7 +1202,7 @@
 		pthread_mutex_lock (&queue_lock);
 		gettimeofday (&now, NULL);
 		timeout.tv_sec = now.tv_sec + TIMEOUT_SECS;
-		timeout.tv_nsec = timeout.tv_sec;
+		timeout.tv_nsec = 0;
 		retcode = pthread_cond_timedwait(&qcond, &queue_lock, &timeout);
                 pthread_mutex_unlock (&queue_lock);
 
