Index: bgpd/pfkey.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/pfkey.c,v
retrieving revision 1.1.1.6
retrieving revision 1.1.1.8
diff -u -p -r1.1.1.6 -r1.1.1.8
--- bgpd/pfkey.c	14 Feb 2010 20:19:57 -0000	1.1.1.6
+++ bgpd/pfkey.c	12 Jun 2011 10:44:25 -0000	1.1.1.8
@@ -1,4 +1,4 @@
-/*	$OpenBSD: pfkey.c,v 1.37 2009/04/21 15:25:52 henning Exp $ */
+/*	$OpenBSD: pfkey.c,v 1.41 2010/12/09 13:50:41 claudio Exp $ */
 
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
@@ -411,6 +402,33 @@ pfkey_send(int sd, uint8_t satype, uint8
 }
 
 int
+pfkey_read(int sd, struct sadb_msg *h)
+{
+	struct sadb_msg hdr;
+
+	if (recv(sd, &hdr, sizeof(hdr), MSG_PEEK) != sizeof(hdr)) {
+		log_warn("pfkey peek");
+		return (-1);
+	}
+
+	/* XXX: Only one message can be outstanding. */
+	if (hdr.sadb_msg_seq == sadb_msg_seq &&
+	    hdr.sadb_msg_pid == pid) {
+		if (h)
+			bcopy(&hdr, h, sizeof(hdr));
+		return (0);
+	}
+
+	/* not ours, discard */
+	if (read(sd, &hdr, sizeof(hdr)) == -1) {
+		log_warn("pfkey read");
+		return (-1);
+	}
+
+	return (1);
+}
+
+int
 pfkey_reply(int sd, u_int32_t *spip)
 {
 	struct sadb_msg hdr, *msg;
@@ -418,23 +436,13 @@ pfkey_reply(int sd, u_int32_t *spip)
 	struct sadb_sa *sa;
 	u_int8_t *data;
 	ssize_t len;
+	int rv;
 
-	for (;;) {
-		if (recv(sd, &hdr, sizeof(hdr), MSG_PEEK) != sizeof(hdr)) {
-			log_warn("pfkey peek");
+	do {
+		rv = pfkey_read(sd, &hdr);
+		if (rv == -1)
 			return (-1);
-		}
-
-		if (hdr.sadb_msg_seq == sadb_msg_seq &&
-		    hdr.sadb_msg_pid == pid)
-			break;
-
-		/* not ours, discard */
-		if (read(sd, &hdr, sizeof(hdr)) == -1) {
-			log_warn("pfkey read");
-			return (-1);
-		}
-	}
+	} while (rv);
 
 	if (hdr.sadb_msg_errno != 0) {
 		errno = hdr.sadb_msg_errno;
@@ -730,11 +738,9 @@ pfkey_init(struct bgpd_sysdep *sysdep)
 		if (errno == EPROTONOSUPPORT) {
 			log_warnx("PF_KEY not available, disabling ipsec");
 			sysdep->no_pfkey = 1;
-			return (0);
-		} else {
-			log_warn("PF_KEY socket");
 			return (-1);
-		}
+		} else
+			fatal("pfkey setup failed");
 	}
-	return (0);
+	return (fd);
 }
