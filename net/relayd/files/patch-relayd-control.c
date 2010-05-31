--- relayd/control.c.orig	2010-05-31 09:31:24.548916055 +0000
+++ relayd/control.c	2010-05-31 09:31:09.036333394 +0000
@@ -136,13 +136,13 @@
 	if ((connfd = accept(listenfd,
 	    (struct sockaddr *)&sun, &len)) == -1) {
 		if (errno != EWOULDBLOCK && errno != EINTR)
-			log_warn("control_accept");
+			log_warn("control_accept: accept");
 		return;
 	}
 
 	session_socket_blockmode(connfd, BM_NONBLOCK);
 
-	if ((c = malloc(sizeof(struct ctl_conn))) == NULL) {
+	if ((c = calloc(1, sizeof(struct ctl_conn))) == NULL) {
 		close(connfd);
 		log_warn("control_accept");
 		return;
@@ -196,6 +196,7 @@
 	struct imsg		 imsg;
 	struct ctl_id		 id;
 	int			 n;
+	int			 verbose;
 	struct relayd		*env = arg;
 
 	if ((c = control_connbyfd(fd)) == NULL) {
@@ -356,6 +357,22 @@
 			}
 			c->flags |= CTL_CONN_NOTIFY;
 			break;
+		case IMSG_CTL_LOG_VERBOSE:
+			if (imsg.hdr.len != IMSG_HEADER_SIZE +
+			    sizeof(verbose))
+				break;
+
+			memcpy(&verbose, imsg.data, sizeof(verbose));
+
+			imsg_compose_event(iev_hce, IMSG_CTL_LOG_VERBOSE,
+			    0, 0, -1, &verbose, sizeof(verbose));
+			imsg_compose_event(iev_main, IMSG_CTL_LOG_VERBOSE,
+			    0, 0, -1, &verbose, sizeof(verbose));
+			memcpy(imsg.data, &verbose, sizeof(verbose));
+			control_imsg_forward(&imsg);
+
+			log_verbose(verbose);
+			break;
 		default:
 			log_debug("control_dispatch_imsg: "
 			    "error handling imsg %d", imsg.hdr.type);
