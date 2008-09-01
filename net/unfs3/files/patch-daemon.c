--- ./daemon.c.orig	2008-08-31 22:26:12.000000000 -0400
+++ ./daemon.c	2008-08-31 22:26:25.000000000 -0400
@@ -131,7 +131,7 @@
 
     l = sizeof(v);
 
-    if (getsockopt(rqstp->rq_xprt->xp_sock, SOL_SOCKET, SO_TYPE, &v, &l) < 0) {
+    if (getsockopt(rqstp->rq_xprt->xp_fd, SOL_SOCKET, SO_TYPE, &v, &l) < 0) {
 	logmsg(LOG_CRIT, "unable to determine socket type");
 	return -1;
     }
