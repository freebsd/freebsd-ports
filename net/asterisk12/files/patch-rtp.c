
$FreeBSD$

--- rtp.c.orig	Fri Jan 13 13:38:01 2006
+++ rtp.c	Fri Jan 13 13:40:50 2006
@@ -950,8 +950,10 @@ struct ast_rtp *ast_rtp_new_with_bindadd
 		rtp->us.sin_port = htons(x);
 		rtp->us.sin_addr = addr;
 		/* If there's rtcp, initialize it as well. */
-		if (rtp->rtcp)
+		if (rtp->rtcp) {
 			rtp->rtcp->us.sin_port = htons(x + 1);
+			rtp->rtcp->us.sin_addr = addr;
+		}
 		/* Try to bind it/them. */
 		if (!(first = bind(rtp->s, (struct sockaddr *)&rtp->us, sizeof(rtp->us))) &&
 			(!rtp->rtcp || !bind(rtp->rtcp->s, (struct sockaddr *)&rtp->rtcp->us, sizeof(rtp->rtcp->us))))
