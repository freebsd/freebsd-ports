Index: bgpd/pfkey.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/pfkey.c,v
retrieving revision 1.1.1.6
retrieving revision 1.1.1.7
diff -u -p -r1.1.1.6 -r1.1.1.7
--- bgpd/pfkey.c	14 Feb 2010 20:19:57 -0000	1.1.1.6
+++ bgpd/pfkey.c	14 Feb 2010 20:27:06 -0000	1.1.1.7
@@ -1,4 +1,4 @@
-/*	$OpenBSD: pfkey.c,v 1.37 2009/04/21 15:25:52 henning Exp $ */
+/*	$OpenBSD: pfkey.c,v 1.40 2009/12/14 17:38:18 claudio Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Henning Brauer <henning@openbsd.org>
@@ -74,6 +74,7 @@ pfkey_send(int sd, uint8_t satype, uint8
 	int			len = 0;
 	int			iov_cnt;
 	struct sockaddr_storage	ssrc, sdst, speer, smask, dmask;
+	struct sockaddr		*saptr;
 
 	if (!pid)
 		pid = getpid();
@@ -81,22 +82,17 @@ pfkey_send(int sd, uint8_t satype, uint8
 	/* we need clean sockaddr... no ports set */
 	bzero(&ssrc, sizeof(ssrc));
 	bzero(&smask, sizeof(smask));
-	switch (src->af) {
-	case AF_INET:
-		((struct sockaddr_in *)&ssrc)->sin_addr = src->v4;
-		ssrc.ss_len = sizeof(struct sockaddr_in);
-		ssrc.ss_family = AF_INET;
+	if ((saptr = addr2sa(src, 0)))
+		memcpy(&ssrc, saptr, sizeof(ssrc));
+	switch (src->aid) {
+	case AID_INET:
 		memset(&((struct sockaddr_in *)&smask)->sin_addr, 0xff, 32/8);
 		break;
-	case AF_INET6:
-		memcpy(&((struct sockaddr_in6 *)&ssrc)->sin6_addr,
-		    &src->v6, sizeof(struct in6_addr));
-		ssrc.ss_len = sizeof(struct sockaddr_in6);
-		ssrc.ss_family = AF_INET6;
+	case AID_INET6:
 		memset(&((struct sockaddr_in6 *)&smask)->sin6_addr, 0xff,
 		    128/8);
 		break;
-	case 0:
+	case AID_UNSPEC:
 		ssrc.ss_len = sizeof(struct sockaddr);
 		break;
 	default:
@@ -107,22 +103,17 @@ pfkey_send(int sd, uint8_t satype, uint8
 
 	bzero(&sdst, sizeof(sdst));
 	bzero(&dmask, sizeof(dmask));
-	switch (dst->af) {
-	case AF_INET:
-		((struct sockaddr_in *)&sdst)->sin_addr = dst->v4;
-		sdst.ss_len = sizeof(struct sockaddr_in);
-		sdst.ss_family = AF_INET;
+	if ((saptr = addr2sa(dst, 0)))
+		memcpy(&sdst, saptr, sizeof(sdst));
+	switch (dst->aid) {
+	case AID_INET:
 		memset(&((struct sockaddr_in *)&dmask)->sin_addr, 0xff, 32/8);
 		break;
-	case AF_INET6:
-		memcpy(&((struct sockaddr_in6 *)&sdst)->sin6_addr,
-		    &dst->v6, sizeof(struct in6_addr));
-		sdst.ss_len = sizeof(struct sockaddr_in6);
-		sdst.ss_family = AF_INET6;
+	case AID_INET6:
 		memset(&((struct sockaddr_in6 *)&dmask)->sin6_addr, 0xff,
 		    128/8);
 		break;
-	case 0:
+	case AID_UNSPEC:
 		sdst.ss_len = sizeof(struct sockaddr);
 		break;
 	default:
@@ -220,8 +211,8 @@ pfkey_send(int sd, uint8_t satype, uint8
 		sa_dst.sadb_address_exttype = SADB_X_EXT_DST_FLOW;
 
 		bzero(&smask, sizeof(smask));
-		switch (src->af) {
-		case AF_INET:
+		switch (src->aid) {
+		case AID_INET:
 			smask.ss_len = sizeof(struct sockaddr_in);
 			smask.ss_family = AF_INET;
 			memset(&((struct sockaddr_in *)&smask)->sin_addr,
@@ -233,7 +224,7 @@ pfkey_send(int sd, uint8_t satype, uint8
 				    htons(0xffff);
 			}
 			break;
-		case AF_INET6:
+		case AID_INET6:
 			smask.ss_len = sizeof(struct sockaddr_in6);
 			smask.ss_family = AF_INET6;
 			memset(&((struct sockaddr_in6 *)&smask)->sin6_addr,
@@ -247,8 +238,8 @@ pfkey_send(int sd, uint8_t satype, uint8
 			break;
 		}
 		bzero(&dmask, sizeof(dmask));
-		switch (dst->af) {
-		case AF_INET:
+		switch (dst->aid) {
+		case AID_INET:
 			dmask.ss_len = sizeof(struct sockaddr_in);
 			dmask.ss_family = AF_INET;
 			memset(&((struct sockaddr_in *)&dmask)->sin_addr,
@@ -260,7 +251,7 @@ pfkey_send(int sd, uint8_t satype, uint8
 				    htons(0xffff);
 			}
 			break;
-		case AF_INET6:
+		case AID_INET6:
 			dmask.ss_len = sizeof(struct sockaddr_in6);
 			dmask.ss_family = AF_INET6;
 			memset(&((struct sockaddr_in6 *)&dmask)->sin6_addr,
