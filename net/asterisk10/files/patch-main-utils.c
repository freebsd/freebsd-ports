--- main/utils.c.orig	2008-05-29 19:20:16.000000000 +0200
+++ main/utils.c	2008-10-03 21:36:14.000000000 +0200
@@ -914,8 +914,7 @@
 		pthread_attr_init(attr);
 	}
 
-#ifdef __linux__
-	/* On Linux, pthread_attr_init() defaults to PTHREAD_EXPLICIT_SCHED,
+	/* On Linux and FreeBSD, pthread_attr_init() defaults to PTHREAD_EXPLICIT_SCHED,
 	   which is kind of useless. Change this here to
 	   PTHREAD_INHERIT_SCHED; that way the -p option to set realtime
 	   priority will propagate down to new threads by default.
@@ -924,7 +923,6 @@
 	   the priority afterwards with pthread_setschedparam(). */
 	if ((errno = pthread_attr_setinheritsched(attr, PTHREAD_INHERIT_SCHED)))
 		ast_log(LOG_WARNING, "pthread_attr_setinheritsched: %s\n", strerror(errno));
-#endif
 
 	if (!stacksize)
 		stacksize = AST_STACKSIZE;
