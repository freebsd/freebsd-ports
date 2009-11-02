Index: bgpd/control.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/control.c,v
retrieving revision 1.1.1.1
retrieving revision 1.1.1.3
diff -u -p -r1.1.1.1 -r1.1.1.3
--- bgpd/control.c	30 Jun 2009 05:46:15 -0000	1.1.1.1
+++ bgpd/control.c	22 Oct 2009 14:24:02 -0000	1.1.1.3
@@ -1,4 +1,4 @@
-/*	$OpenBSD: control.c,v 1.60 2008/05/11 01:08:05 henning Exp $ */
+/*	$OpenBSD: control.c,v 1.61 2009/05/05 20:09:19 sthen Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Henning Brauer <henning@openbsd.org>
@@ -328,11 +328,11 @@ control_dispatch_msg(struct pollfd *pfd,
 					control_result(c, CTL_RES_OK);
 					break;
 				case IMSG_CTL_NEIGHBOR_DOWN:
-					bgp_fsm(p, EVNT_STOP);
+					session_stop(p, ERR_CEASE_ADMIN_DOWN);
 					control_result(c, CTL_RES_OK);
 					break;
 				case IMSG_CTL_NEIGHBOR_CLEAR:
-					bgp_fsm(p, EVNT_STOP);
+					session_stop(p, ERR_CEASE_ADMIN_RESET);
 					timer_set(p, Timer_IdleHold,
 					    SESSION_CLEAR_DELAY);
 					control_result(c, CTL_RES_OK);
@@ -396,6 +396,13 @@ control_dispatch_msg(struct pollfd *pfd,
 					control_result(c, CTL_RES_NOCAP);
 					break;
 				}
+				if ((imsg.hdr.type == IMSG_CTL_SHOW_RIB_PREFIX)
+				    && (ribreq->prefix.af != AF_INET)
+				    && (ribreq->prefix.af != AF_INET6)) {
+					/* malformed request, must specify af */
+					control_result(c, CTL_RES_PARSE_ERROR);
+					break;
+				}
 				c->ibuf.pid = imsg.hdr.pid;
 				imsg_compose_rde(imsg.hdr.type, imsg.hdr.pid,
 				    imsg.data, imsg.hdr.len - IMSG_HEADER_SIZE);
