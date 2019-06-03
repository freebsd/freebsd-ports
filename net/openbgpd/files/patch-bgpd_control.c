Index: bgpd/control.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/control.c,v
retrieving revision 1.1.1.7
retrieving revision 1.1.1.10
diff -u -p -r1.1.1.7 -r1.1.1.10
--- bgpd/control.c	14 Feb 2010 20:19:57 -0000	1.1.1.7
+++ bgpd/control.c	13 Oct 2012 18:22:41 -0000	1.1.1.10
@@ -1,4 +1,4 @@
-/*	$OpenBSD: control.c,v 1.61 2009/05/05 20:09:19 sthen Exp $ */
+/*	$OpenBSD: control.c,v 1.71 2012/04/12 17:26:09 claudio Exp $ */
 
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
@@ -122,15 +122,18 @@ control_accept(int listenfd, int restric
 	len = sizeof(sun);
 	if ((connfd = accept(listenfd,
 	    (struct sockaddr *)&sun, &len)) == -1) {
-		if (errno != EWOULDBLOCK && errno != EINTR)
-			log_warn("session_control_accept");
+		if (errno == ENFILE || errno == EMFILE) {
+			pauseaccept = getmonotime();
+			return (0);
+		} else if (errno != EWOULDBLOCK && errno != EINTR)
+			log_warn("control_accept: accept");
 		return (0);
 	}
 
 	session_socket_blockmode(connfd, BM_NONBLOCK);
 
-	if ((ctl_conn = malloc(sizeof(struct ctl_conn))) == NULL) {
-		log_warn("session_control_accept");
+	if ((ctl_conn = calloc(1, sizeof(struct ctl_conn))) == NULL) {
+		log_warn("control_accept");
 		close(connfd);
 		return (0);
 	}
@@ -182,7 +185,7 @@ control_close(int fd)
 
 	close(c->ibuf.fd);
 	free(c);
-
+	pauseaccept = 0;
 	return (1);
 }
 
@@ -191,7 +194,8 @@ control_dispatch_msg(struct pollfd *pfd,
 {
 	struct imsg		 imsg;
 	struct ctl_conn		*c;
-	int			 n;
+	ssize_t			 n;
+	int			 verbose;
 	struct peer		*p;
 	struct ctl_neighbor	*neighbor;
 	struct ctl_show_rib_request	*ribreq;
@@ -305,7 +309,8 @@ control_dispatch_msg(struct pollfd *pfd,
 			break;
 		case IMSG_CTL_FIB_COUPLE:
 		case IMSG_CTL_FIB_DECOUPLE:
-			imsg_compose_parent(imsg.hdr.type, 0, NULL, 0);
+			imsg_compose_parent(imsg.hdr.type, imsg.hdr.peerid,
+			    0, NULL, 0);
 			break;
 		case IMSG_CTL_NEIGHBOR_UP:
 		case IMSG_CTL_NEIGHBOR_DOWN:
@@ -328,13 +333,19 @@ control_dispatch_msg(struct pollfd *pfd,
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
@@ -352,13 +363,19 @@ control_dispatch_msg(struct pollfd *pfd,
 				    "wrong length");
 			break;
 		case IMSG_CTL_RELOAD:
+		case IMSG_CTL_SHOW_INTERFACE:
+		case IMSG_CTL_SHOW_FIB_TABLES:
+			c->ibuf.pid = imsg.hdr.pid;
+			imsg_compose_parent(imsg.hdr.type, 0, imsg.hdr.pid,
+			    imsg.data, imsg.hdr.len - IMSG_HEADER_SIZE);
+			break;
 		case IMSG_CTL_KROUTE:
 		case IMSG_CTL_KROUTE_ADDR:
 		case IMSG_CTL_SHOW_NEXTHOP:
-		case IMSG_CTL_SHOW_INTERFACE:
 			c->ibuf.pid = imsg.hdr.pid;
-			imsg_compose_parent(imsg.hdr.type, imsg.hdr.pid,
-			    imsg.data, imsg.hdr.len - IMSG_HEADER_SIZE);
+			imsg_compose_parent(imsg.hdr.type, imsg.hdr.peerid,
+			    imsg.hdr.pid, imsg.data, imsg.hdr.len -
+			    IMSG_HEADER_SIZE);
 			break;
 		case IMSG_CTL_SHOW_RIB:
 		case IMSG_CTL_SHOW_RIB_AS:
@@ -370,7 +387,7 @@ control_dispatch_msg(struct pollfd *pfd,
 				neighbor->descr[PEER_DESCR_LEN - 1] = 0;
 				ribreq->peerid = 0;
 				p = NULL;
-				if (neighbor->addr.af) {
+				if (neighbor->addr.aid) {
 					p = getpeerbyaddr(&neighbor->addr);
 					if (p == NULL) {
 						control_result(c,
@@ -397,8 +414,7 @@ control_dispatch_msg(struct pollfd *pfd,
 					break;
 				}
 				if ((imsg.hdr.type == IMSG_CTL_SHOW_RIB_PREFIX)
-				    && (ribreq->prefix.af != AF_INET)
-				    && (ribreq->prefix.af != AF_INET6)) {
+				    && (ribreq->prefix.aid == AID_UNSPEC)) {
 					/* malformed request, must specify af */
 					control_result(c, CTL_RES_PARSE_ERROR);
 					break;
@@ -418,6 +434,8 @@ control_dispatch_msg(struct pollfd *pfd,
 			    imsg.data, imsg.hdr.len - IMSG_HEADER_SIZE);
 			break;
 		case IMSG_NETWORK_ADD:
+		case IMSG_NETWORK_ASPATH:
+		case IMSG_NETWORK_ATTR:
 		case IMSG_NETWORK_REMOVE:
 		case IMSG_NETWORK_FLUSH:
 		case IMSG_NETWORK_DONE:
@@ -425,6 +443,20 @@ control_dispatch_msg(struct pollfd *pfd,
 			imsg_compose_rde(imsg.hdr.type, 0,
 			    imsg.data, imsg.hdr.len - IMSG_HEADER_SIZE);
 			break;
+		case IMSG_CTL_LOG_VERBOSE:
+			if (imsg.hdr.len != IMSG_HEADER_SIZE +
+			    sizeof(verbose))
+				break;
+
+			/* forward to other processes */
+			imsg_compose_parent(imsg.hdr.type, 0, imsg.hdr.pid,
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
