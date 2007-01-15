--- event.c.orig	Thu Feb 27 17:42:32 2003
+++ event.c	Tue Nov 14 17:40:52 2006
@@ -288,7 +288,7 @@
 #ifdef	HAVE_PTHREAD
 	pthread_mutex_lock(&localtime_lock);
 #endif
-	tm = localtime(&tvp->tv_sec);
+	tm = localtime((time_t *)&tvp->tv_sec);
 	defect = tm->tm_sec + 60 * tm->tm_min + 3600 * tm->tm_hour + off;
 #ifdef	HAVE_PTHREAD
 	pthread_mutex_unlock(&localtime_lock);
