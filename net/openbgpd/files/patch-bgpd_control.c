Index: bgpd/control.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/control.c,v
retrieving revision 1.1.1.1
retrieving revision 1.1.1.2
diff -u -p -r1.1.1.1 -r1.1.1.2
--- bgpd/control.c	30 Jun 2009 05:46:15 -0000	1.1.1.1
+++ bgpd/control.c	9 Jul 2009 16:49:54 -0000	1.1.1.2
@@ -1,4 +1,4 @@
-/*	$OpenBSD: control.c,v 1.60 2008/05/11 01:08:05 henning Exp $ */
+/*	$OpenBSD: control.c,v 1.61 2009/05/05 20:09:19 sthen Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Henning Brauer <henning@openbsd.org>
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
