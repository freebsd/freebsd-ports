--- main/utils.c.orig	2014-11-07 20:16:06 UTC
+++ main/utils.c
@@ -1192,8 +1192,8 @@ int ast_pthread_create_stack(pthread_t *
 		pthread_attr_init(attr);
 	}
 
-#ifdef __linux__
-	/* On Linux, pthread_attr_init() defaults to PTHREAD_EXPLICIT_SCHED,
+#if defined(__linux__) || defined(__FreeBSD__)
+	/* On Linux and FreeBSD, pthread_attr_init() defaults to PTHREAD_EXPLICIT_SCHED,
 	   which is kind of useless. Change this here to
 	   PTHREAD_INHERIT_SCHED; that way the -p option to set realtime
 	   priority will propagate down to new threads by default.
