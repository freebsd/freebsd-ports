--- ./main/utils.c.orig	2010-08-06 20:57:10.000000000 +0200
+++ ./main/utils.c	2010-11-06 14:54:37.000000000 +0100
@@ -990,8 +990,8 @@
 		pthread_attr_init(attr);
 	}
 
-#ifdef __linux__
-	/* On Linux, pthread_attr_init() defaults to PTHREAD_EXPLICIT_SCHED,
+#ifdef __linux__ || defined(__FreeBSD__)
+	/* On Linux and FreeBSD, pthread_attr_init() defaults to PTHREAD_EXPLICIT_SCHED,
 	   which is kind of useless. Change this here to
 	   PTHREAD_INHERIT_SCHED; that way the -p option to set realtime
 	   priority will propagate down to new threads by default.
