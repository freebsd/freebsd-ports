
$FreeBSD$

--- rtp.c.orig	Sat Sep 18 16:56:28 2004
+++ rtp.c	Sun Oct 10 15:57:22 2004
@@ -127,7 +127,7 @@
 {
 	switch(buf & TYPE_MASK) {
 	case TYPE_DONTSEND:
-		return 0;
+		return 2;
 		break;
 	case TYPE_SILENCE:
 		return 4;
@@ -841,8 +841,10 @@
 		/* Must be an even port number by RTP spec */
 		rtp->us.sin_port = htons(x);
 		rtp->us.sin_addr = addr;
-		if (rtp->rtcp)
+		if (rtp->rtcp) {
 			rtp->rtcp->us.sin_port = htons(x + 1);
+			rtp->rtcp->us.sin_addr = addr;
+		}
 		if (!(first = bind(rtp->s, (struct sockaddr *)&rtp->us, sizeof(rtp->us))) &&
 			(!rtp->rtcp || !bind(rtp->rtcp->s, (struct sockaddr *)&rtp->rtcp->us, sizeof(rtp->rtcp->us))))
 			break;
