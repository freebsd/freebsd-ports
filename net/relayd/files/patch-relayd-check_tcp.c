--- relayd/check_tcp.c.orig	2010-05-27 11:10:01.114202025 +0200
+++ relayd/check_tcp.c	2010-05-27 11:22:55.453595437 +0200
@@ -99,6 +99,7 @@
 
 	cte->buf = NULL;
 	cte->host->up = HOST_UP;
+	event_del(&cte->ev);
 	event_set(&cte->ev, s, EV_TIMEOUT|EV_WRITE, tcp_write, cte);
 	event_add(&cte->ev, &tv);
 	return;
