diff -ur bgpd.orig/pfkey.c bgpd/pfkey.c
--- bgpd.orig/pfkey.c	2013-03-15 12:07:16.000000000 +0000
+++ bgpd/pfkey.c	2013-03-15 12:07:47.000000000 +0000
@@ -1,4 +1,4 @@
-/*	$OpenBSD: pfkey.c,v 1.37 2009/04/21 15:25:52 henning Exp $ */
+/*	$OpenBSD: pfkey.c,v 1.40 2009/12/14 17:38:18 claudio Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Henning Brauer <henning@openbsd.org>
@@ -21,7 +21,7 @@
 #include <sys/socket.h>
 #include <sys/uio.h>
 #include <net/pfkeyv2.h>
-#include <netinet/ip_ipsp.h>
+//#include <netinet/ip_ipsp.h>
 #include <ctype.h>
 #include <errno.h>
 #include <limits.h>
@@ -65,15 +65,15 @@
 {
 	struct sadb_msg		smsg;
 	struct sadb_sa		sa;
-	struct sadb_address	sa_src, sa_dst, sa_peer, sa_smask, sa_dmask;
+	struct sadb_address	sa_src, sa_dst;
 	struct sadb_key		sa_akey, sa_ekey;
 	struct sadb_spirange	sa_spirange;
-	struct sadb_protocol	sa_flowtype, sa_protocol;
 	struct iovec		iov[IOV_CNT];
 	ssize_t			n;
 	int			len = 0;
 	int			iov_cnt;
-	struct sockaddr_storage	ssrc, sdst, speer, smask, dmask;
+	struct sockaddr_storage	ssrc, sdst, smask, dmask;
+	struct sockaddr		*saptr;
 
 	if (!pid)
 		pid = getpid();
@@ -81,22 +81,17 @@
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
@@ -107,22 +102,17 @@
 
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
@@ -135,7 +125,7 @@
 	smsg.sadb_msg_version = PF_KEY_V2;
 	smsg.sadb_msg_seq = ++sadb_msg_seq;
 	smsg.sadb_msg_pid = pid;
-	smsg.sadb_msg_len = sizeof(smsg) / 8;
+	smsg.sadb_msg_len = PFKEY_UNIT64(sizeof(smsg));
 	smsg.sadb_msg_type = mtype;
 	smsg.sadb_msg_satype = satype;
 
@@ -143,7 +133,7 @@
 	case SADB_GETSPI:
 		bzero(&sa_spirange, sizeof(sa_spirange));
 		sa_spirange.sadb_spirange_exttype = SADB_EXT_SPIRANGE;
-		sa_spirange.sadb_spirange_len = sizeof(sa_spirange) / 8;
+		sa_spirange.sadb_spirange_len = PFKEY_UNIT64(sizeof(sa_spirange));
 		sa_spirange.sadb_spirange_min = 0x100;
 		sa_spirange.sadb_spirange_max = 0xffffffff;
 		sa_spirange.sadb_spirange_reserved = 0;
@@ -153,11 +143,12 @@
 	case SADB_DELETE:
 		bzero(&sa, sizeof(sa));
 		sa.sadb_sa_exttype = SADB_EXT_SA;
-		sa.sadb_sa_len = sizeof(sa) / 8;
+		sa.sadb_sa_len = PFKEY_UNIT64(sizeof(sa));
 		sa.sadb_sa_replay = 0;
 		sa.sadb_sa_spi = spi;
 		sa.sadb_sa_state = SADB_SASTATE_MATURE;
 		break;
+#if 0
 	case SADB_X_ADDFLOW:
 	case SADB_X_DELFLOW:
 		bzero(&sa_flowtype, sizeof(sa_flowtype));
@@ -172,35 +163,37 @@
 		sa_protocol.sadb_protocol_direction = 0;
 		sa_protocol.sadb_protocol_proto = 6;
 		break;
+#endif
 	}
 
 	bzero(&sa_src, sizeof(sa_src));
 	sa_src.sadb_address_exttype = SADB_EXT_ADDRESS_SRC;
-	sa_src.sadb_address_len = (sizeof(sa_src) + ROUNDUP(ssrc.ss_len)) / 8;
+	sa_src.sadb_address_len = PFKEY_UNIT64(sizeof(sa_src) + ROUNDUP(ssrc.ss_len));
 
 	bzero(&sa_dst, sizeof(sa_dst));
 	sa_dst.sadb_address_exttype = SADB_EXT_ADDRESS_DST;
-	sa_dst.sadb_address_len = (sizeof(sa_dst) + ROUNDUP(sdst.ss_len)) / 8;
+	sa_dst.sadb_address_len = PFKEY_UNIT64(sizeof(sa_dst) + ROUNDUP(sdst.ss_len));
 
 	sa.sadb_sa_auth = aalg;
-	sa.sadb_sa_encrypt = SADB_X_EALG_AES; /* XXX */
+	sa.sadb_sa_encrypt = ealg; /* XXX */
 
 	switch (mtype) {
 	case SADB_ADD:
 	case SADB_UPDATE:
 		bzero(&sa_akey, sizeof(sa_akey));
 		sa_akey.sadb_key_exttype = SADB_EXT_KEY_AUTH;
-		sa_akey.sadb_key_len = (sizeof(sa_akey) +
-		    ((alen + 7) / 8) * 8) / 8;
+		sa_akey.sadb_key_len = PFKEY_UNIT64(sizeof(sa_akey) +
+		    (PFKEY_ALIGN8(alen)));
 		sa_akey.sadb_key_bits = 8 * alen;
 
 		bzero(&sa_ekey, sizeof(sa_ekey));
 		sa_ekey.sadb_key_exttype = SADB_EXT_KEY_ENCRYPT;
-		sa_ekey.sadb_key_len = (sizeof(sa_ekey) +
-		    ((elen + 7) / 8) * 8) / 8;
+		sa_ekey.sadb_key_len = PFKEY_UNIT64(sizeof(sa_ekey) +
+		    (PFKEY_ALIGN8(elen)));
 		sa_ekey.sadb_key_bits = 8 * elen;
 
 		break;
+#if 0
 	case SADB_X_ADDFLOW:
 	case SADB_X_DELFLOW:
 		/* sa_peer always points to the remote machine */
@@ -220,8 +213,8 @@
 		sa_dst.sadb_address_exttype = SADB_X_EXT_DST_FLOW;
 
 		bzero(&smask, sizeof(smask));
-		switch (src->af) {
-		case AF_INET:
+		switch (src->aid) {
+		case AID_INET:
 			smask.ss_len = sizeof(struct sockaddr_in);
 			smask.ss_family = AF_INET;
 			memset(&((struct sockaddr_in *)&smask)->sin_addr,
@@ -233,7 +226,7 @@
 				    htons(0xffff);
 			}
 			break;
-		case AF_INET6:
+		case AID_INET6:
 			smask.ss_len = sizeof(struct sockaddr_in6);
 			smask.ss_family = AF_INET6;
 			memset(&((struct sockaddr_in6 *)&smask)->sin6_addr,
@@ -247,8 +240,8 @@
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
@@ -260,7 +253,7 @@
 				    htons(0xffff);
 			}
 			break;
-		case AF_INET6:
+		case AID_INET6:
 			dmask.ss_len = sizeof(struct sockaddr_in6);
 			dmask.ss_family = AF_INET6;
 			memset(&((struct sockaddr_in6 *)&dmask)->sin6_addr,
@@ -284,6 +277,7 @@
 		sa_dmask.sadb_address_len =
 		    (sizeof(sa_dmask) + ROUNDUP(dmask.ss_len)) / 8;
 		break;
+#endif
 	}
 
 	iov_cnt = 0;
@@ -310,6 +304,7 @@
 		smsg.sadb_msg_len += sa_spirange.sadb_spirange_len;
 		iov_cnt++;
 		break;
+#if 0
 	case SADB_X_ADDFLOW:
 		/* sa_peer always points to the remote machine */
 		iov[iov_cnt].iov_base = &sa_peer;
@@ -351,6 +346,7 @@
 		smsg.sadb_msg_len += sa_dmask.sadb_address_len;
 		iov_cnt++;
 		break;
+#endif
 	}
 
 	/* dest addr */
@@ -380,7 +376,7 @@
 			iov[iov_cnt].iov_len = sizeof(sa_akey);
 			iov_cnt++;
 			iov[iov_cnt].iov_base = akey;
-			iov[iov_cnt].iov_len = ((alen + 7) / 8) * 8;
+			iov[iov_cnt].iov_len = PFKEY_ALIGN8(alen);
 			smsg.sadb_msg_len += sa_akey.sadb_key_len;
 			iov_cnt++;
 		}
@@ -390,14 +386,14 @@
 			iov[iov_cnt].iov_len = sizeof(sa_ekey);
 			iov_cnt++;
 			iov[iov_cnt].iov_base = ekey;
-			iov[iov_cnt].iov_len = ((elen + 7) / 8) * 8;
+			iov[iov_cnt].iov_len = PFKEY_ALIGN8(elen);
 			smsg.sadb_msg_len += sa_ekey.sadb_key_len;
 			iov_cnt++;
 		}
 		break;
 	}
 
-	len = smsg.sadb_msg_len * 8;
+	len = PFKEY_UNUNIT64(smsg.sadb_msg_len);
 	do {
 		n = writev(sd, iov, iov_cnt);
 	} while (n == -1 && (errno == EAGAIN || errno == EINTR));
@@ -411,6 +407,33 @@
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
@@ -418,27 +441,17 @@
 	struct sadb_sa *sa;
 	u_int8_t *data;
 	ssize_t len;
+	int rv;
 
-	for (;;) {
-		if (recv(sd, &hdr, sizeof(hdr), MSG_PEEK) != sizeof(hdr)) {
-			log_warn("pfkey peek");
-			return (-1);
-		}
-
-		if (hdr.sadb_msg_seq == sadb_msg_seq &&
-		    hdr.sadb_msg_pid == pid)
-			break;
-
-		/* not ours, discard */
-		if (read(sd, &hdr, sizeof(hdr)) == -1) {
-			log_warn("pfkey read");
+	do {
+		rv = pfkey_read(sd, &hdr);
+		if (rv == -1)
 			return (-1);
-		}
-	}
+	} while (rv);
 
 	if (hdr.sadb_msg_errno != 0) {
 		errno = hdr.sadb_msg_errno;
-		if (errno == ESRCH)
+		if (errno == ESRCH || errno == EEXIST)
 			return (0);
 		else {
 			log_warn("pfkey");
@@ -486,13 +499,8 @@
 pfkey_sa_add(struct bgpd_addr *src, struct bgpd_addr *dst, u_int8_t keylen,
     char *key, u_int32_t *spi)
 {
-	if (pfkey_send(fd, SADB_X_SATYPE_TCPSIGNATURE, SADB_GETSPI, 0,
-	    src, dst, 0, 0, 0, NULL, 0, 0, NULL, 0, 0) < 0)
-		return (-1);
-	if (pfkey_reply(fd, spi) < 0)
-		return (-1);
-	if (pfkey_send(fd, SADB_X_SATYPE_TCPSIGNATURE, SADB_UPDATE, 0,
-		src, dst, *spi, 0, keylen, key, 0, 0, NULL, 0, 0) < 0)
+	if (pfkey_send(fd, SADB_X_SATYPE_TCPSIGNATURE, SADB_ADD, 0,
+		src, dst, *spi, SADB_X_AALG_TCP_MD5, keylen, key, SADB_EALG_NONE, 0, NULL, 0, 0) < 0)
 		return (-1);
 	if (pfkey_reply(fd, NULL) < 0)
 		return (-1);
@@ -503,7 +511,7 @@
 pfkey_sa_remove(struct bgpd_addr *src, struct bgpd_addr *dst, u_int32_t *spi)
 {
 	if (pfkey_send(fd, SADB_X_SATYPE_TCPSIGNATURE, SADB_DELETE, 0,
-	    src, dst, *spi, 0, 0, NULL, 0, 0, NULL, 0, 0) < 0)
+	    src, dst, *spi, SADB_X_AALG_TCP_MD5, 0, NULL, 0, 0, NULL, 0, 0) < 0)
 		return (-1);
 	if (pfkey_reply(fd, NULL) < 0)
 		return (-1);
@@ -511,37 +519,37 @@
 	return (0);
 }
 
+#define TCP_SIG_SPI     0x1000
 int
 pfkey_md5sig_establish(struct peer *p)
 {
 	sleep(1);
 
-	if (!p->auth.spi_out)
-		if (pfkey_sa_add(&p->auth.local_addr, &p->conf.remote_addr,
-		    p->conf.auth.md5key_len, p->conf.auth.md5key,
-		    &p->auth.spi_out) == -1)
-			return (-1);
-	if (!p->auth.spi_in)
-		if (pfkey_sa_add(&p->conf.remote_addr, &p->auth.local_addr,
-		    p->conf.auth.md5key_len, p->conf.auth.md5key,
-		    &p->auth.spi_in) == -1)
-			return (-1);
+	p->auth.spi_out = htonl(TCP_SIG_SPI);
+	if (pfkey_sa_add(&p->auth.local_addr, &p->conf.remote_addr,
+	    p->conf.auth.md5key_len, p->conf.auth.md5key,
+	    &p->auth.spi_out) == -1)
+		return (-1);
+	p->auth.spi_in = htonl(TCP_SIG_SPI);
+	if (pfkey_sa_add(&p->conf.remote_addr, &p->auth.local_addr,
+	    p->conf.auth.md5key_len, p->conf.auth.md5key,
+	    &p->auth.spi_out) == -1)
+		return (-1);
 
 	p->auth.established = 1;
 	return (0);
 }
+#undef TCP_SIG_SPI
 
 int
 pfkey_md5sig_remove(struct peer *p)
 {
-	if (p->auth.spi_out)
-		if (pfkey_sa_remove(&p->auth.local_addr, &p->conf.remote_addr,
-		    &p->auth.spi_out) == -1)
-			return (-1);
-	if (p->auth.spi_in)
-		if (pfkey_sa_remove(&p->conf.remote_addr, &p->auth.local_addr,
-		    &p->auth.spi_in) == -1)
-			return (-1);
+	if (pfkey_sa_remove(&p->auth.local_addr, &p->conf.remote_addr,
+	    &p->auth.spi_out) == -1)
+		return (-1);
+	if (pfkey_sa_remove(&p->conf.remote_addr, &p->auth.local_addr,
+	    &p->auth.spi_in) == -1)
+		return (-1);
 
 	p->auth.established = 0;
 	return (0);
@@ -550,6 +558,7 @@
 int
 pfkey_ipsec_establish(struct peer *p)
 {
+#if 0
 	uint8_t satype = SADB_SATYPE_ESP;
 
 	switch (p->auth.method) {
@@ -621,6 +630,9 @@
 
 	p->auth.established = 1;
 	return (0);
+#else
+	return (-1);
+#endif
 }
 
 int
@@ -660,6 +672,7 @@
 		break;
 	}
 
+#if 0
 	if (pfkey_flow(fd, satype, SADB_X_DELFLOW, IPSP_DIRECTION_OUT,
 	    &p->auth.local_addr, &p->conf.remote_addr, 0, BGP_PORT) < 0)
 		return (-1);
@@ -681,6 +694,7 @@
 	if (pfkey_flow(fd, satype, SADB_X_DELFLOW, IPSP_DIRECTION_IN,
 	    &p->conf.remote_addr, &p->auth.local_addr, BGP_PORT, 0) < 0)
 		return (-1);
+#endif
 	if (pfkey_reply(fd, NULL) < 0)
 		return (-1);
 
@@ -715,9 +729,7 @@
 int
 pfkey_remove(struct peer *p)
 {
-	if (!p->auth.established)
-		return (0);
-	else if (p->auth.method == AUTH_MD5SIG)
+	if (p->auth.method == AUTH_MD5SIG)
 		return (pfkey_md5sig_remove(p));
 	else
 		return (pfkey_ipsec_remove(p));
@@ -730,11 +742,9 @@
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
