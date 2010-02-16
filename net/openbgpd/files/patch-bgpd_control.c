Index: bgpd/control.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/control.c,v
retrieving revision 1.1.1.7
retrieving revision 1.1.1.8
diff -u -p -r1.1.1.7 -r1.1.1.8
--- bgpd/control.c	14 Feb 2010 20:19:57 -0000	1.1.1.7
+++ bgpd/control.c	14 Feb 2010 20:27:06 -0000	1.1.1.8
@@ -1,4 +1,4 @@
-/*	$OpenBSD: control.c,v 1.61 2009/05/05 20:09:19 sthen Exp $ */
+/*	$OpenBSD: control.c,v 1.68 2010/01/13 06:02:37 claudio Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Henning Brauer <henning@openbsd.org>
@@ -53,7 +53,7 @@ control_init(int restricted, char *path)
 
 	if (unlink(path) == -1)
 		if (errno != ENOENT) {
-			log_warn("unlink %s", path);
+			log_warn("control_init: unlink %s", path);
 			close(fd);
 			return (-1);
 		}
@@ -123,14 +123,14 @@ control_accept(int listenfd, int restric
 	if ((connfd = accept(listenfd,
 	    (struct sockaddr *)&sun, &len)) == -1) {
 		if (errno != EWOULDBLOCK && errno != EINTR)
-			log_warn("session_control_accept");
+			log_warn("control_accept: accept");
 		return (0);
 	}
 
 	session_socket_blockmode(connfd, BM_NONBLOCK);
 
 	if ((ctl_conn = malloc(sizeof(struct ctl_conn))) == NULL) {
-		log_warn("session_control_accept");
+		log_warn("control_accept");
 		close(connfd);
 		return (0);
 	}
@@ -191,7 +191,8 @@ control_dispatch_msg(struct pollfd *pfd,
 {
 	struct imsg		 imsg;
 	struct ctl_conn		*c;
-	int			 n;
+	ssize_t			 n;
+	int			 verbose;
 	struct peer		*p;
 	struct ctl_neighbor	*neighbor;
 	struct ctl_show_rib_request	*ribreq;
@@ -328,13 +329,19 @@ control_dispatch_msg(struct pollfd *pfd,
 					control_result(c, CTL_RES_OK);
 					break;
 				case IMSG_CTL_NEIGHBOR_DOWN:
-					bgp_fsm(p, EVNT_STOP);
+					session_stop(p, ERR_CEASE_ADMIN_DOWN);
 					control_result(c, CTL_RES_OK);
 					break;
 				case IMSG_CTL_NEIGHBOR_CLEAR:
-					bgp_fsm(p, EVNT_STOP);
-					timer_set(p, Timer_IdleHold,
-					    SESSION_CLEAR_DELAY);
+					if (!p->conf.down) {
+						session_stop(p,
+						    ERR_CEASE_ADMIN_RESET);
+						timer_set(p, Timer_IdleHold,
+						    SESSION_CLEAR_DELAY);
+					} else {
+						session_stop(p,
+						    ERR_CEASE_ADMIN_DOWN);
+					}
 					control_result(c, CTL_RES_OK);
 					break;
 				case IMSG_CTL_NEIGHBOR_RREFRESH:
@@ -370,7 +377,7 @@ control_dispatch_msg(struct pollfd *pfd,
 				neighbor->descr[PEER_DESCR_LEN - 1] = 0;
 				ribreq->peerid = 0;
 				p = NULL;
-				if (neighbor->addr.af) {
+				if (neighbor->addr.aid) {
 					p = getpeerbyaddr(&neighbor->addr);
 					if (p == NULL) {
 						control_result(c,
@@ -397,8 +404,7 @@ control_dispatch_msg(struct pollfd *pfd,
 					break;
 				}
 				if ((imsg.hdr.type == IMSG_CTL_SHOW_RIB_PREFIX)
-				    && (ribreq->prefix.af != AF_INET)
-				    && (ribreq->prefix.af != AF_INET6)) {
+				    && (ribreq->prefix.aid == AID_UNSPEC)) {
 					/* malformed request, must specify af */
 					control_result(c, CTL_RES_PARSE_ERROR);
 					break;
@@ -425,6 +431,20 @@ control_dispatch_msg(struct pollfd *pfd,
 			imsg_compose_rde(imsg.hdr.type, 0,
 			    imsg.data, imsg.hdr.len - IMSG_HEADER_SIZE);
 			break;
+		case IMSG_CTL_LOG_VERBOSE:
+			if (imsg.hdr.len != IMSG_HEADER_SIZE +
+			    sizeof(verbose))
+				break;
+
+			/* forward to other processes */
+			imsg_compose_parent(imsg.hdr.type, imsg.hdr.pid,
+			    imsg.data, imsg.hdr.len - IMSG_HEADER_SIZE);
+			imsg_compose_rde(imsg.hdr.type, 0,
+			    imsg.data, imsg.hdr.len - IMSG_HEADER_SIZE);
+
+			memcpy(&verbose, imsg.data, sizeof(verbose));
+			log_verbose(verbose);
+			break;
 		default:
 			break;
 		}
