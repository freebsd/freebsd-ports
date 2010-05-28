--- relayd/control.c.orig	2009-06-06 01:39:51.000000000 +0200
+++ relayd/control.c	2010-05-27 10:41:16.689809156 +0200
@@ -142,7 +142,7 @@
 
 	session_socket_blockmode(connfd, BM_NONBLOCK);
 
-	if ((c = malloc(sizeof(struct ctl_conn))) == NULL) {
+	if ((c = calloc(1, sizeof(struct ctl_conn))) == NULL) {
 		close(connfd);
 		log_warn("control_accept");
 		return;
