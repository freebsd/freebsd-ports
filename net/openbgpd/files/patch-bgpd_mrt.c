Index: bgpd/mrt.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/mrt.c,v
retrieving revision 1.1.1.1
retrieving revision 1.1.1.2
diff -u -p -r1.1.1.1 -r1.1.1.2
--- bgpd/mrt.c	30 Jun 2009 05:46:15 -0000	1.1.1.1
+++ bgpd/mrt.c	9 Jul 2009 16:49:54 -0000	1.1.1.2
@@ -1,4 +1,4 @@
-/*	$OpenBSD: mrt.c,v 1.53 2007/04/23 13:04:24 claudio Exp $ */
+/*	$OpenBSD: mrt.c,v 1.63 2009/06/29 12:22:16 claudio Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Claudio Jeker <claudio@openbsd.org>
@@ -32,24 +32,21 @@
 
 #include "mrt.h"
 
-static u_int16_t	mrt_attr_length(struct rde_aspath *, int);
-static int		mrt_attr_dump(void *, u_int16_t, struct rde_aspath *,
-			    struct bgpd_addr *);
-static int		mrt_dump_entry_mp(struct mrt *, struct prefix *,
-			    u_int16_t, struct rde_peer*);
-static int		mrt_dump_entry(struct mrt *, struct prefix *,
-			    u_int16_t, struct rde_peer*);
-static int		mrt_dump_header(struct buf *, u_int16_t, u_int16_t,
-			    u_int32_t);
-static int		mrt_open(struct mrt *, time_t);
+int mrt_attr_dump(struct buf *, struct rde_aspath *, struct bgpd_addr *);
+int mrt_dump_entry_mp(struct mrt *, struct prefix *, u_int16_t,
+    struct rde_peer*);
+int mrt_dump_entry(struct mrt *, struct prefix *, u_int16_t, struct rde_peer*);
+int mrt_dump_hdr_se(struct buf **, struct peer *, u_int16_t, u_int16_t,
+    u_int32_t, int);
+int mrt_dump_hdr_rde(struct buf **, u_int16_t type, u_int16_t, u_int32_t);
+int mrt_open(struct mrt *, time_t);
 
 #define DUMP_BYTE(x, b)							\
 	do {								\
 		u_char		t = (b);				\
 		if (buf_add((x), &t, sizeof(t)) == -1) {		\
 			log_warnx("mrt_dump1: buf_add error");		\
-			buf_free((x));					\
-			return (-1);					\
+			goto fail;					\
 		}							\
 	} while (0)
 
@@ -59,8 +56,7 @@ static int		mrt_open(struct mrt *, time_
 		t = htons((s));						\
 		if (buf_add((x), &t, sizeof(t)) == -1) {		\
 			log_warnx("mrt_dump2: buf_add error");		\
-			buf_free((x));					\
-			return (-1);					\
+			goto fail;					\
 		}							\
 	} while (0)
 
@@ -70,8 +66,7 @@ static int		mrt_open(struct mrt *, time_
 		t = htonl((l));						\
 		if (buf_add((x), &t, sizeof(t)) == -1) {		\
 			log_warnx("mrt_dump3: buf_add error");		\
-			buf_free((x));					\
-			return (-1);					\
+			goto fail;					\
 		}							\
 	} while (0)
 
@@ -80,327 +75,175 @@ static int		mrt_open(struct mrt *, time_
 		u_int32_t	t = (l);				\
 		if (buf_add((x), &t, sizeof(t)) == -1) {		\
 			log_warnx("mrt_dump4: buf_add error");		\
-			buf_free((x));					\
-			return (-1);					\
+			goto fail;					\
 		}							\
 	} while (0)
 
-int
+void
 mrt_dump_bgp_msg(struct mrt *mrt, void *pkg, u_int16_t pkglen,
-    struct peer *peer, struct bgpd_config *bgp)
+    struct peer *peer)
 {
 	struct buf	*buf;
-	u_int16_t	 len;
 	int		 incoming = 0;
 
-	switch (peer->sa_local.ss_family) {
-	case AF_INET:
-		len = pkglen + MRT_BGP4MP_IPv4_HEADER_SIZE;
-		break;
-	case AF_INET6:
-		len = pkglen + MRT_BGP4MP_IPv6_HEADER_SIZE;
-		break;
-	default:
-		return (-1);
-	}
-
 	/* get the direction of the message to swap address and AS fields */
 	if (mrt->type == MRT_ALL_IN || mrt->type == MRT_UPDATE_IN)
 		incoming = 1;
 
-	if ((buf = buf_open(len + MRT_HEADER_SIZE)) == NULL) {
-		log_warnx("mrt_dump_bgp_msg: buf_open error");
-		return (-1);
-	}
-
-	if (mrt_dump_header(buf, MSG_PROTOCOL_BGP4MP, BGP4MP_MESSAGE,
-	    len) == -1) {
-		log_warnx("mrt_dump_bgp_msg: buf_add error");
-		return (-1);
-	}
-
-	if (!incoming)
-		DUMP_SHORT(buf, bgp->short_as);
-	DUMP_SHORT(buf, peer->short_as);
-	if (incoming)
-		DUMP_SHORT(buf, bgp->short_as);
-	DUMP_SHORT(buf, /* ifindex */ 0);
-	switch (peer->sa_local.ss_family) {
-	case AF_INET:
-		DUMP_SHORT(buf, AFI_IPv4);
-		if (!incoming)
-			DUMP_NLONG(buf, ((struct sockaddr_in *)
-			    &peer->sa_local)->sin_addr.s_addr);
-		DUMP_NLONG(buf,
-		    ((struct sockaddr_in *)&peer->sa_remote)->sin_addr.s_addr);
-		if (incoming)
-			DUMP_NLONG(buf, ((struct sockaddr_in *)
-			    &peer->sa_local)->sin_addr.s_addr);
-		break;
-	case AF_INET6:
-		DUMP_SHORT(buf, AFI_IPv6);
-		if (!incoming)
-			if (buf_add(buf, &((struct sockaddr_in6 *)
-			    &peer->sa_local)->sin6_addr,
-			    sizeof(struct in6_addr)) == -1) {
-				log_warnx("mrt_dump_bgp_msg: buf_add error");
-				buf_free(buf);
-				return (-1);
-			}
-		if (buf_add(buf,
-		    &((struct sockaddr_in6 *)&peer->sa_remote)->sin6_addr,
-		    sizeof(struct in6_addr)) == -1) {
-			log_warnx("mrt_dump_bgp_msg: buf_add error");
-			buf_free(buf);
-			return (-1);
-		}
-		if (incoming)
-			if (buf_add(buf, &((struct sockaddr_in6 *)
-			    &peer->sa_local)->sin6_addr,
-			    sizeof(struct in6_addr)) == -1) {
-				log_warnx("mrt_dump_bgp_msg: buf_add error");
-				buf_free(buf);
-				return (-1);
-			}
-		break;
-	}
+	if (mrt_dump_hdr_se(&buf, peer, MSG_PROTOCOL_BGP4MP, BGP4MP_MESSAGE,
+	    pkglen, incoming) == -1)
+		return;
 
 	if (buf_add(buf, pkg, pkglen) == -1) {
 		log_warnx("mrt_dump_bgp_msg: buf_add error");
 		buf_free(buf);
-		return (-1);
+		return;
 	}
 
-	TAILQ_INSERT_TAIL(&mrt->bufs, buf, entry);
-	mrt->queued++;
-
-	return (len + MRT_HEADER_SIZE);
+	buf_close(&mrt->wbuf, buf);
 }
 
-int
+void
 mrt_dump_state(struct mrt *mrt, u_int16_t old_state, u_int16_t new_state,
-    struct peer *peer, struct bgpd_config *bgp)
+    struct peer *peer)
 {
 	struct buf	*buf;
-	u_int16_t	 len;
-
-	switch (peer->sa_local.ss_family) {
-	case AF_INET:
-		len = 4 + MRT_BGP4MP_IPv4_HEADER_SIZE;
-		break;
-	case AF_INET6:
-		len = 4 + MRT_BGP4MP_IPv6_HEADER_SIZE;
-		break;
-	default:
-		return (-1);
-	}
-
-	if ((buf = buf_open(len + MRT_HEADER_SIZE)) == NULL) {
-		log_warnx("mrt_dump_bgp_state: buf_open error");
-		return (-1);
-	}
 
-	if (mrt_dump_header(buf, MSG_PROTOCOL_BGP4MP, BGP4MP_STATE_CHANGE,
-	    len) == -1) {
-		log_warnx("mrt_dump_bgp_state: buf_add error");
-		return (-1);
-	}
-
-	DUMP_SHORT(buf, bgp->short_as);
-	DUMP_SHORT(buf, peer->short_as);
-	DUMP_SHORT(buf, /* ifindex */ 0);
-	switch (peer->sa_local.ss_family) {
-	case AF_INET:
-		DUMP_SHORT(buf, AFI_IPv4);
-		DUMP_NLONG(buf,
-		    ((struct sockaddr_in *)&peer->sa_local)->sin_addr.s_addr);
-		DUMP_NLONG(buf,
-		    ((struct sockaddr_in *)&peer->sa_remote)->sin_addr.s_addr);
-		break;
-	case AF_INET6:
-		DUMP_SHORT(buf, AFI_IPv6);
-		if (buf_add(buf,
-		    &((struct sockaddr_in6 *)&peer->sa_local)->sin6_addr,
-		    sizeof(struct in6_addr)) == -1 ||
-		    buf_add(buf,
-		    &((struct sockaddr_in6 *)&peer->sa_remote)->sin6_addr,
-		    sizeof(struct in6_addr)) == -1) {
-			log_warnx("mrt_dump_bgp_msg: buf_add error");
-			buf_free(buf);
-			return (-1);
-		}
-		break;
-	}
+	if (mrt_dump_hdr_se(&buf, peer, MSG_PROTOCOL_BGP4MP, BGP4MP_MESSAGE,
+	    2 * sizeof(short), 0) == -1)
+		return;
 
 	DUMP_SHORT(buf, old_state);
 	DUMP_SHORT(buf, new_state);
 
-	TAILQ_INSERT_TAIL(&mrt->bufs, buf, entry);
-	mrt->queued++;
-
-	return (len + MRT_HEADER_SIZE);
-}
-
-static u_int16_t
-mrt_attr_length(struct rde_aspath *a, int oldform)
-{
-	u_int16_t	 alen, plen;
-	u_int8_t	 l;
+	buf_close(&mrt->wbuf, buf);
+	return;
 
-	alen = 4 /* origin */ + 7 /* lpref */;
-	if (oldform)
-		alen += 7 /* nexthop */;
-	plen = aspath_length(a->aspath);
-	alen += 2 + plen + (plen > 255 ? 2 : 1);
-	if (a->med != 0)
-		alen += 7;
-
-	for (l = 0; l < a->others_len; l++)
-		if (a->others[l] != NULL)
-			alen += 2 + a->others[l]->len +
-			    (a->others[l]->len > 255 ? 2 : 1);
-		else
-			break;
-
-	return alen;
+fail:
+	buf_free(buf);
 }
 
-static int
-mrt_attr_dump(void *p, u_int16_t len, struct rde_aspath *a,
-    struct bgpd_addr *nexthop)
+int
+mrt_attr_dump(struct buf *buf, struct rde_aspath *a, struct bgpd_addr *nexthop)
 {
 	struct attr	*oa;
-	u_char		*buf = p;
-	u_int32_t	 tmp32;
-	int		 r;
-	u_int16_t	 aslen, wlen = 0;
+	u_char		*pdata;
+	u_int32_t	 tmp;
+	int		 neednewpath = 0;
+	u_int16_t	 plen;
 	u_int8_t	 l;
 
 	/* origin */
-	if ((r = attr_write(buf + wlen, len, ATTR_WELL_KNOWN, ATTR_ORIGIN,
-	    &a->origin, 1)) == -1)
+	if (attr_writebuf(buf, ATTR_WELL_KNOWN, ATTR_ORIGIN,
+	    &a->origin, 1) == -1)
 		return (-1);
-	wlen += r; len -= r;
 
 	/* aspath */
-	aslen = aspath_length(a->aspath);
-	if ((r = attr_write(buf + wlen, len, ATTR_WELL_KNOWN, ATTR_ASPATH,
-	    aspath_dump(a->aspath), aslen)) == -1)
+	pdata = aspath_prepend(a->aspath, rde_local_as(), 0, &plen);
+	pdata = aspath_deflate(pdata, &plen, &neednewpath);
+	if (attr_writebuf(buf, ATTR_WELL_KNOWN, ATTR_ASPATH, pdata, plen) == -1)
 		return (-1);
-	wlen += r; len -= r;
+	free(pdata);
 
 	if (nexthop) {
 		/* nexthop, already network byte order */
-		if ((r = attr_write(buf + wlen, len, ATTR_WELL_KNOWN,
-		    ATTR_NEXTHOP, &nexthop->v4.s_addr, 4)) ==	-1)
+		if (attr_writebuf(buf, ATTR_WELL_KNOWN, ATTR_NEXTHOP,
+		    &nexthop->v4.s_addr, 4) ==	-1)
 			return (-1);
-		wlen += r; len -= r;
 	}
 
 	/* MED, non transitive */
 	if (a->med != 0) {
-		tmp32 = htonl(a->med);
-		if ((r = attr_write(buf + wlen, len, ATTR_OPTIONAL, ATTR_MED,
-		    &tmp32, 4)) == -1)
+		tmp = htonl(a->med);
+		if (attr_writebuf(buf, ATTR_OPTIONAL, ATTR_MED, &tmp, 4) == -1)
 			return (-1);
-		wlen += r; len -= r;
 	}
 
 	/* local preference, only valid for ibgp */
-	tmp32 = htonl(a->lpref);
-	if ((r = attr_write(buf + wlen, len, ATTR_WELL_KNOWN, ATTR_LOCALPREF,
-	    &tmp32, 4)) == -1)
+	tmp = htonl(a->lpref);
+	if (attr_writebuf(buf, ATTR_WELL_KNOWN, ATTR_LOCALPREF, &tmp, 4) == -1)
 		return (-1);
-	wlen += r; len -= r;
 
 	/* dump all other path attributes without modification */
 	for (l = 0; l < a->others_len; l++) {
 		if ((oa = a->others[l]) == NULL)
 			break;
-		if ((r = attr_write(buf + wlen, len, oa->flags, oa->type,
-		    oa->data, oa->len)) == -1)
+		if (attr_writebuf(buf, oa->flags, oa->type,
+		    oa->data, oa->len) == -1)
 			return (-1);
-		wlen += r; len -= r;
 	}
 
-	return (wlen);
+	if (neednewpath) {
+		pdata = aspath_prepend(a->aspath, rde_local_as(), 0, &plen);
+		if (plen != 0)
+			if (attr_writebuf(buf, ATTR_OPTIONAL|ATTR_TRANSITIVE,
+			    ATTR_AS4_PATH, pdata, plen) == -1)
+				return (-1);
+		free(pdata);
+	}
+
+	return (0);
 }
 
-static int
+int
 mrt_dump_entry_mp(struct mrt *mrt, struct prefix *p, u_int16_t snum,
     struct rde_peer *peer)
 {
-	struct buf	*buf;
+	struct buf	*buf, *hbuf = NULL, *h2buf = NULL;
 	void		*bptr;
 	struct bgpd_addr addr, nexthop, *nh;
-	u_int16_t	 len, attr_len;
+	u_int16_t	 len;
 	u_int8_t	 p_len;
 	sa_family_t	 af;
 
-	attr_len = mrt_attr_length(p->aspath, 0);
-	p_len = PREFIX_SIZE(p->prefix->prefixlen);
-	pt_getaddr(p->prefix, &addr);
-
-	af = peer->remote_addr.af == 0 ? addr.af : peer->remote_addr.af;
-	switch (af) {
-	case AF_INET:
-		len = MRT_BGP4MP_IPv4_HEADER_SIZE;
-		break;
-	case AF_INET6:
-		len = MRT_BGP4MP_IPv6_HEADER_SIZE;
-		break;
-	default:
-		return (-1);
-	}
-
-	switch (addr.af) {
-	case AF_INET:
-		len += MRT_BGP4MP_IPv4_ENTRY_SIZE + p_len + attr_len;
-		break;
-	case AF_INET6:
-		len += MRT_BGP4MP_IPv4_ENTRY_SIZE + p_len + attr_len;
-		break;
-	default:
+	if ((buf = buf_dynamic(0, MAX_PKTSIZE)) == NULL) {
+		log_warn("mrt_dump_entry_mp: buf_dynamic");
 		return (-1);
 	}
 
-	if ((buf = buf_open(len + MRT_HEADER_SIZE)) == NULL) {
-		log_warnx("mrt_dump_entry_mp: buf_open error");
-		return (-1);
+	if (mrt_attr_dump(buf, p->aspath, NULL) == -1) {
+		log_warnx("mrt_dump_entry_mp: mrt_attr_dump error");
+		goto fail;
 	}
+	len = buf_size(buf);
 
-	if (mrt_dump_header(buf, MSG_PROTOCOL_BGP4MP, BGP4MP_ENTRY,
-	    len) == -1) {
-		log_warnx("mrt_dump_entry_mp: buf_add error");
-		return (-1);
+	if ((h2buf = buf_dynamic(MRT_BGP4MP_IPv4_HEADER_SIZE +
+	    MRT_BGP4MP_IPv4_ENTRY_SIZE, MRT_BGP4MP_IPv6_HEADER_SIZE +
+	    MRT_BGP4MP_IPv6_ENTRY_SIZE + MRT_BGP4MP_MAX_PREFIXLEN)) == NULL) {
+		log_warn("mrt_dump_entry_mp: buf_dynamic");
+		goto fail;
 	}
 
-	DUMP_SHORT(buf, rde_local_as());
-	DUMP_SHORT(buf, peer->short_as);
-	DUMP_SHORT(buf, /* ifindex */ 0);
+	DUMP_SHORT(h2buf, rde_local_as());
+	DUMP_SHORT(h2buf, peer->short_as);
+	DUMP_SHORT(h2buf, /* ifindex */ 0);
 
+	/* XXX is this for peer self? */
+	af = peer->remote_addr.af == 0 ? p->prefix->af : peer->remote_addr.af;
 	switch (af) {
 	case AF_INET:
-		DUMP_SHORT(buf, AFI_IPv4);
-		DUMP_NLONG(buf, peer->local_v4_addr.v4.s_addr);
-		DUMP_NLONG(buf, peer->remote_addr.v4.s_addr);
+		DUMP_SHORT(h2buf, AFI_IPv4);
+		DUMP_NLONG(h2buf, peer->local_v4_addr.v4.s_addr);
+		DUMP_NLONG(h2buf, peer->remote_addr.v4.s_addr);
 		break;
 	case AF_INET6:
-		DUMP_SHORT(buf, AFI_IPv6);
-		if (buf_add(buf, &peer->local_v6_addr.v6,
+		DUMP_SHORT(h2buf, AFI_IPv6);
+		if (buf_add(h2buf, &peer->local_v6_addr.v6,
 		    sizeof(struct in6_addr)) == -1 ||
-		    buf_add(buf, &peer->remote_addr.v6,
+		    buf_add(h2buf, &peer->remote_addr.v6,
 		    sizeof(struct in6_addr)) == -1) {
 			log_warnx("mrt_dump_entry_mp: buf_add error");
-			buf_free(buf);
-			return (-1);
+			goto fail;
 		}
 		break;
+	default:
+		log_warnx("king bula found new AF %d in mrt_dump_entry_mp", af);
+		goto fail;
 	}
 
-	DUMP_SHORT(buf, 0);		/* view */
-	DUMP_SHORT(buf, 1);		/* status */
-	DUMP_LONG(buf, p->lastchange);	/* originated */
+	DUMP_SHORT(h2buf, 0);		/* view */
+	DUMP_SHORT(h2buf, 1);		/* status */
+	DUMP_LONG(h2buf, p->lastchange);	/* originated */
 
 	if (p->aspath->nexthop == NULL) {
 		bzero(&nexthop, sizeof(struct bgpd_addr));
@@ -409,95 +252,74 @@ mrt_dump_entry_mp(struct mrt *mrt, struc
 	} else
 		nh = &p->aspath->nexthop->exit_nexthop;
 
+	pt_getaddr(p->prefix, &addr);
 	switch (addr.af) {
 	case AF_INET:
-		DUMP_SHORT(buf, AFI_IPv4);	/* afi */
-		DUMP_BYTE(buf, SAFI_UNICAST);	/* safi */
-		DUMP_BYTE(buf, 4);		/* nhlen */
-		DUMP_NLONG(buf, nh->v4.s_addr);	/* nexthop */
+		DUMP_SHORT(h2buf, AFI_IPv4);	/* afi */
+		DUMP_BYTE(h2buf, SAFI_UNICAST);	/* safi */
+		DUMP_BYTE(h2buf, 4);		/* nhlen */
+		DUMP_NLONG(h2buf, nh->v4.s_addr);	/* nexthop */
 		break;
 	case AF_INET6:
-		DUMP_SHORT(buf, AFI_IPv6);	/* afi */
-		DUMP_BYTE(buf, SAFI_UNICAST);	/* safi */
-		DUMP_BYTE(buf, 16);		/* nhlen */
-		if (buf_add(buf, &nh->v6, sizeof(struct in6_addr)) == -1) {
+		DUMP_SHORT(h2buf, AFI_IPv6);	/* afi */
+		DUMP_BYTE(h2buf, SAFI_UNICAST);	/* safi */
+		DUMP_BYTE(h2buf, 16);		/* nhlen */
+		if (buf_add(h2buf, &nh->v6, sizeof(struct in6_addr)) == -1) {
 			log_warnx("mrt_dump_entry_mp: buf_add error");
-			buf_free(buf);
-			return (-1);
+			goto fail;
 		}
 		break;
+	default:
+		log_warnx("king bula found new AF in mrt_dump_entry_mp");
+		goto fail;
 	}
 
-	if ((bptr = buf_reserve(buf, p_len)) == NULL) {
+	p_len = PREFIX_SIZE(p->prefix->prefixlen);
+	if ((bptr = buf_reserve(h2buf, p_len)) == NULL) {
 		log_warnx("mrt_dump_entry_mp: buf_reserve error");
-		buf_free(buf);
-		return (-1);
+		goto fail;
 	}
 	if (prefix_write(bptr, p_len, &addr, p->prefix->prefixlen) == -1) {
 		log_warnx("mrt_dump_entry_mp: prefix_write error");
-		buf_free(buf);
-		return (-1);
+		goto fail;
 	}
 
-	DUMP_SHORT(buf, attr_len);
-	if ((bptr = buf_reserve(buf, attr_len)) == NULL) {
-		log_warnx("mrt_dump_entry_mp: buf_reserve error");
-		buf_free(buf);
-		return (-1);
-	}
+	DUMP_SHORT(h2buf, len);
+	len += buf_size(h2buf);
 
-	if (mrt_attr_dump(bptr, attr_len, p->aspath, NULL) == -1) {
-		log_warnx("mrt_dump_entry_mp: mrt_attr_dump error");
-		buf_free(buf);
-		return (-1);
-	}
+	if (mrt_dump_hdr_rde(&hbuf, MSG_PROTOCOL_BGP4MP, BGP4MP_ENTRY,
+	    len) == -1)
+		goto fail;
 
-	TAILQ_INSERT_TAIL(&mrt->bufs, buf, entry);
-	mrt->queued++;
+	buf_close(&mrt->wbuf, hbuf);
+	buf_close(&mrt->wbuf, h2buf);
+	buf_close(&mrt->wbuf, buf);
 
 	return (len + MRT_HEADER_SIZE);
+
+fail:
+	if (hbuf)
+		buf_free(hbuf);
+	if (h2buf);
+		buf_free(h2buf);
+	buf_free(buf);
+	return (-1);
 }
 
-static int
+int
 mrt_dump_entry(struct mrt *mrt, struct prefix *p, u_int16_t snum,
     struct rde_peer *peer)
 {
-	struct buf	*buf;
-	void		*bptr;
+	struct buf	*buf, *hbuf;
 	struct bgpd_addr addr, *nh;
-	u_int16_t	 len, attr_len;
+	size_t		 len;
 
 	if (p->prefix->af != AF_INET && peer->remote_addr.af == AF_INET)
-		/* only for true IPv4 */
+		/* only able to dump IPv4 */
 		return (0);
 
-	attr_len = mrt_attr_length(p->aspath, 1);
-	len = MRT_DUMP_HEADER_SIZE + attr_len;
-	pt_getaddr(p->prefix, &addr);
-
-	if ((buf = buf_open(len + MRT_HEADER_SIZE)) == NULL) {
-		log_warnx("mrt_dump_entry: buf_open error");
-		return (-1);
-	}
-
-	if (mrt_dump_header(buf, MSG_TABLE_DUMP, AFI_IPv4, len) == -1) {
-		log_warnx("mrt_dump_entry: buf_add error");
-		return (-1);
-	}
-
-	DUMP_SHORT(buf, 0);
-	DUMP_SHORT(buf, snum);
-	DUMP_NLONG(buf, addr.v4.s_addr);
-	DUMP_BYTE(buf, p->prefix->prefixlen);
-	DUMP_BYTE(buf, 1);		/* state */
-	DUMP_LONG(buf, p->lastchange);	/* originated */
-	DUMP_NLONG(buf, peer->remote_addr.v4.s_addr);
-	DUMP_SHORT(buf, peer->short_as);
-
-	DUMP_SHORT(buf, attr_len);
-	if ((bptr = buf_reserve(buf, attr_len)) == NULL) {
-		log_warnx("mrt_dump_entry: buf_reserve error");
-		buf_free(buf);
+	if ((buf = buf_dynamic(0, MAX_PKTSIZE)) == NULL) {
+		log_warnx("mrt_dump_entry: buf_dynamic");
 		return (-1);
 	}
 
@@ -507,28 +329,44 @@ mrt_dump_entry(struct mrt *mrt, struct p
 		nh = &addr;
 	} else
 		nh = &p->aspath->nexthop->exit_nexthop;
-	if (mrt_attr_dump(bptr, attr_len, p->aspath, nh) == -1) {
+	if (mrt_attr_dump(buf, p->aspath, nh) == -1) {
 		log_warnx("mrt_dump_entry: mrt_attr_dump error");
 		buf_free(buf);
 		return (-1);
 	}
+	len = buf_size(buf);
 
-	TAILQ_INSERT_TAIL(&mrt->bufs, buf, entry);
-	mrt->queued++;
+	if (mrt_dump_hdr_rde(&hbuf, MSG_TABLE_DUMP, AFI_IPv4, len) == -1) {
+		buf_free(buf);
+		return (-1);
+	}
 
-	return (len + MRT_HEADER_SIZE);
-}
+	DUMP_SHORT(hbuf, 0);
+	DUMP_SHORT(hbuf, snum);
 
-static u_int16_t sequencenum = 0;
+	pt_getaddr(p->prefix, &addr);
+	DUMP_NLONG(hbuf, addr.v4.s_addr);
+	DUMP_BYTE(hbuf, p->prefix->prefixlen);
 
-void
-mrt_clear_seq(void)
-{
-	sequencenum = 0;
+	DUMP_BYTE(hbuf, 1);		/* state */
+	DUMP_LONG(hbuf, p->lastchange);	/* originated */
+	DUMP_NLONG(hbuf, peer->remote_addr.v4.s_addr);
+	DUMP_SHORT(hbuf, peer->short_as);
+	DUMP_SHORT(hbuf, len);
+
+	buf_close(&mrt->wbuf, hbuf);
+	buf_close(&mrt->wbuf, buf);
+
+	return (len + MRT_HEADER_SIZE);
+
+fail:
+	buf_free(hbuf);
+	buf_free(buf);
+	return (-1);
 }
 
 void
-mrt_dump_upcall(struct pt_entry *pt, void *ptr)
+mrt_dump_upcall(struct rib_entry *re, void *ptr)
 {
 	struct mrt		*mrtbuf = ptr;
 	struct prefix		*p;
@@ -538,53 +376,172 @@ mrt_dump_upcall(struct pt_entry *pt, voi
 	 * dumps the table so we do the same. If only the active route should
 	 * be dumped p should be set to p = pt->active.
 	 */
-	LIST_FOREACH(p, &pt->prefix_h, prefix_l) {
-		/* for now dump only stuff from the local-RIB */
-		if (!(p->flags & F_LOCAL))
-			continue;
+	LIST_FOREACH(p, &re->prefix_h, rib_l) {
 		if (mrtbuf->type == MRT_TABLE_DUMP)
-			mrt_dump_entry(mrtbuf, p, sequencenum++,
+			mrt_dump_entry(mrtbuf, p, mrtbuf->seqnum++,
 			    p->aspath->peer);
 		else
-			mrt_dump_entry_mp(mrtbuf, p, sequencenum++,
+			mrt_dump_entry_mp(mrtbuf, p, mrtbuf->seqnum++,
 			    p->aspath->peer);
 	}
 }
 
-static int
-mrt_dump_header(struct buf *buf, u_int16_t type, u_int16_t subtype,
-    u_int32_t len)
+void
+mrt_dump_done(void *ptr)
+{
+	struct mrt		*mrtbuf = ptr;
+
+	mrtbuf->state = MRT_STATE_REMOVE;
+}
+
+int
+mrt_dump_hdr_se(struct buf ** bp, struct peer *peer, u_int16_t type,
+    u_int16_t subtype, u_int32_t len, int swap)
 {
-	time_t			now;
+	time_t	 	now;
+
+	if ((*bp = buf_dynamic(MRT_HEADER_SIZE, MRT_HEADER_SIZE +
+	    MRT_BGP4MP_AS4_IPv6_HEADER_SIZE + len)) == NULL) {
+		log_warnx("mrt_dump_hdr_se: buf_open error");
+		return (-1);
+	}
 
 	now = time(NULL);
 
-	DUMP_LONG(buf, now);
-	DUMP_SHORT(buf, type);
-	DUMP_SHORT(buf, subtype);
-	DUMP_LONG(buf, len);
+	DUMP_LONG(*bp, now);
+	DUMP_SHORT(*bp, type);
+	DUMP_SHORT(*bp, subtype);
+
+	switch (peer->sa_local.ss_family) {
+	case AF_INET:
+		if (subtype == BGP4MP_STATE_CHANGE_AS4 ||
+		    subtype == BGP4MP_MESSAGE_AS4)
+			len += MRT_BGP4MP_AS4_IPv4_HEADER_SIZE;
+		else
+			len += MRT_BGP4MP_IPv4_HEADER_SIZE;
+		break;
+	case AF_INET6:
+		if (subtype == BGP4MP_STATE_CHANGE_AS4 ||
+		    subtype == BGP4MP_MESSAGE_AS4)
+			len += MRT_BGP4MP_AS4_IPv6_HEADER_SIZE;
+		else
+			len += MRT_BGP4MP_IPv6_HEADER_SIZE;
+		break;
+	case 0:
+		goto fail;
+	default:
+		log_warnx("king bula found new AF in mrt_dump_hdr_se");
+		goto fail;
+	}
+
+	DUMP_LONG(*bp, len);
+
+	if (subtype == BGP4MP_STATE_CHANGE_AS4 ||
+	    subtype == BGP4MP_MESSAGE_AS4) {
+		if (!swap)
+			DUMP_LONG(*bp, peer->conf.local_as);
+		DUMP_LONG(*bp, peer->conf.remote_as);
+		if (swap)
+			DUMP_LONG(*bp, peer->conf.local_as);
+	} else {
+		if (!swap)
+			DUMP_SHORT(*bp, peer->conf.local_short_as);
+		DUMP_SHORT(*bp, peer->short_as);
+		if (swap)
+			DUMP_SHORT(*bp, peer->conf.local_short_as);
+	}
+
+	DUMP_SHORT(*bp, /* ifindex */ 0);
+
+	switch (peer->sa_local.ss_family) {
+	case AF_INET:
+		DUMP_SHORT(*bp, AFI_IPv4);
+		if (!swap)
+			DUMP_NLONG(*bp, ((struct sockaddr_in *)
+			    &peer->sa_local)->sin_addr.s_addr);
+		DUMP_NLONG(*bp,
+		    ((struct sockaddr_in *)&peer->sa_remote)->sin_addr.s_addr);
+		if (swap)
+			DUMP_NLONG(*bp, ((struct sockaddr_in *)
+			    &peer->sa_local)->sin_addr.s_addr);
+		break;
+	case AF_INET6:
+		DUMP_SHORT(*bp, AFI_IPv6);
+		if (!swap)
+			if (buf_add(*bp, &((struct sockaddr_in6 *)
+			    &peer->sa_local)->sin6_addr,
+			    sizeof(struct in6_addr)) == -1) {
+				log_warnx("mrt_dump_hdr_se: buf_add error");
+				goto fail;
+			}
+		if (buf_add(*bp,
+		    &((struct sockaddr_in6 *)&peer->sa_remote)->sin6_addr,
+		    sizeof(struct in6_addr)) == -1) {
+			log_warnx("mrt_dump_hdr_se: buf_add error");
+			goto fail;
+		}
+		if (swap)
+			if (buf_add(*bp, &((struct sockaddr_in6 *)
+			    &peer->sa_local)->sin6_addr,
+			    sizeof(struct in6_addr)) == -1) {
+				log_warnx("mrt_dump_hdr_se: buf_add error");
+				goto fail;
+			}
+		break;
+	}
 
 	return (0);
+
+fail:
+	buf_free(*bp);
+	return (-1);
 }
 
 int
-mrt_write(struct mrt *mrt)
+mrt_dump_hdr_rde(struct buf **bp, u_int16_t type, u_int16_t subtype,
+    u_int32_t len)
 {
-	struct buf	*b;
-	int		 r = 0;
+	time_t		 now;
 
-	while ((b = TAILQ_FIRST(&mrt->bufs)) &&
-	    (r = buf_write(mrt->fd, b)) == 1) {
-		TAILQ_REMOVE(&mrt->bufs, b, entry);
-		mrt->queued--;
-		buf_free(b);
-	}
-	if (r <= -1) {
-		log_warn("mrt dump write");
-		mrt_clean(mrt);
+	if ((*bp = buf_dynamic(MRT_HEADER_SIZE, MRT_HEADER_SIZE +
+	    MRT_BGP4MP_AS4_IPv6_HEADER_SIZE + MRT_BGP4MP_IPv6_ENTRY_SIZE)) ==
+	    NULL) {
+		log_warnx("mrt_dump_hdr_rde: buf_dynamic error");
 		return (-1);
 	}
+
+	now = time(NULL);
+	DUMP_LONG(*bp, now);
+	DUMP_SHORT(*bp, type);
+	DUMP_SHORT(*bp, subtype);
+
+	switch (type) {
+	case MSG_TABLE_DUMP:
+		DUMP_LONG(*bp, MRT_DUMP_HEADER_SIZE + len);
+		break;
+	case MSG_PROTOCOL_BGP4MP:
+		DUMP_LONG(*bp, len);
+		break;
+	default:
+		log_warnx("mrt_dump_hdr_rde: unsupported type");
+		goto fail;
+	}	
 	return (0);
+
+fail:
+	buf_free(*bp);
+	return (-1);
+}
+
+void
+mrt_write(struct mrt *mrt)
+{
+	int	r;
+
+	if ((r = buf_write(&mrt->wbuf)) < 0) {
+		log_warn("mrt dump aborted, mrt_write");
+		mrt_clean(mrt);
+	}
 }
 
 void
@@ -592,12 +549,12 @@ mrt_clean(struct mrt *mrt)
 {
 	struct buf	*b;
 
-	close(mrt->fd);
-	while ((b = TAILQ_FIRST(&mrt->bufs))) {
-		TAILQ_REMOVE(&mrt->bufs, b, entry);
+	close(mrt->wbuf.fd);
+	while ((b = TAILQ_FIRST(&mrt->wbuf.bufs))) {
+		TAILQ_REMOVE(&mrt->wbuf.bufs, b, entry);
 		buf_free(b);
 	}
-	mrt->queued = 0;
+	mrt->wbuf.queued = 0;
 }
 
 static struct imsgbuf	*mrt_imsgbuf[2];
@@ -613,30 +570,30 @@ int
 mrt_open(struct mrt *mrt, time_t now)
 {
 	enum imsg_type	type;
-	int		i;
+	int		i = 1, fd;
 
 	if (strftime(MRT2MC(mrt)->file, sizeof(MRT2MC(mrt)->file),
 	    MRT2MC(mrt)->name, localtime(&now)) == 0) {
 		log_warnx("mrt_open: strftime conversion failed");
-		mrt->fd = -1;
 		return (-1);
 	}
 
-	mrt->fd = open(MRT2MC(mrt)->file,
+	fd = open(MRT2MC(mrt)->file,
 	    O_WRONLY|O_NONBLOCK|O_CREAT|O_TRUNC, 0644);
-	if (mrt->fd == -1) {
+	if (fd == -1) {
 		log_warn("mrt_open %s", MRT2MC(mrt)->file);
 		return (1);
 	}
 
-	if (MRT2MC(mrt)->state == MRT_STATE_OPEN)
+	if (mrt->state == MRT_STATE_OPEN)
 		type = IMSG_MRT_OPEN;
 	else
 		type = IMSG_MRT_REOPEN;
 
-	i = mrt->type == MRT_TABLE_DUMP ? 0 : 1;
+	if (mrt->type == MRT_TABLE_DUMP || mrt->type == MRT_TABLE_DUMP_MP)
+		i = 0;
 
-	if (imsg_compose(mrt_imsgbuf[i], type, 0, 0, mrt->fd,
+	if (imsg_compose(mrt_imsgbuf[i], type, 0, 0, fd,
 	    mrt, sizeof(struct mrt)) == -1)
 		log_warn("mrt_open");
 
@@ -652,7 +609,7 @@ mrt_timeout(struct mrt_head *mrt)
 
 	now = time(NULL);
 	LIST_FOREACH(m, mrt, entry) {
-		if (MRT2MC(m)->state == MRT_STATE_RUNNING &&
+		if (m->state == MRT_STATE_RUNNING &&
 		    MRT2MC(m)->ReopenTimerInterval != 0) {
 			if (MRT2MC(m)->ReopenTimer <= now) {
 				mrt_open(m, now);
@@ -675,16 +632,16 @@ mrt_reconfigure(struct mrt_head *mrt)
 	now = time(NULL);
 	for (m = LIST_FIRST(mrt); m != NULL; m = xm) {
 		xm = LIST_NEXT(m, entry);
-		if (MRT2MC(m)->state == MRT_STATE_OPEN ||
-		    MRT2MC(m)->state == MRT_STATE_REOPEN) {
+		if (m->state == MRT_STATE_OPEN ||
+		    m->state == MRT_STATE_REOPEN) {
 			if (mrt_open(m, now) == -1)
 				continue;
 			if (MRT2MC(m)->ReopenTimerInterval != 0)
 				MRT2MC(m)->ReopenTimer =
 				    now + MRT2MC(m)->ReopenTimerInterval;
-			MRT2MC(m)->state = MRT_STATE_RUNNING;
+			m->state = MRT_STATE_RUNNING;
 		}
-		if (MRT2MC(m)->state == MRT_STATE_REMOVE) {
+		if (m->state == MRT_STATE_REMOVE) {
 			LIST_REMOVE(m, entry);
 			free(m);
 			continue;
@@ -700,7 +657,7 @@ mrt_handler(struct mrt_head *mrt)
 
 	now = time(NULL);
 	LIST_FOREACH(m, mrt, entry) {
-		if (MRT2MC(m)->state == MRT_STATE_RUNNING &&
+		if (m->state == MRT_STATE_RUNNING &&
 		    (MRT2MC(m)->ReopenTimerInterval != 0 ||
 		     m->type == MRT_TABLE_DUMP)) {
 			if (mrt_open(m, now) == -1)
@@ -719,8 +676,8 @@ mrt_get(struct mrt_head *c, struct mrt *
 	LIST_FOREACH(t, c, entry) {
 		if (t->type != m->type)
 			continue;
-		if (t->type == MRT_TABLE_DUMP)
-			return (t);
+		if (strcmp(t->rib, m->rib))
+			continue;
 		if (t->peer_id == m->peer_id &&
 		    t->group_id == m->group_id)
 			return (t);
@@ -739,8 +696,7 @@ mrt_mergeconfig(struct mrt_head *xconf, 
 			if ((xm = calloc(1, sizeof(struct mrt_config))) == NULL)
 				fatal("mrt_mergeconfig");
 			memcpy(xm, m, sizeof(struct mrt_config));
-			xm->fd = -1;
-			MRT2MC(xm)->state = MRT_STATE_OPEN;
+			xm->state = MRT_STATE_OPEN;
 			LIST_INSERT_HEAD(xconf, xm, entry);
 		} else {
 			/* MERGE */
@@ -750,14 +706,14 @@ mrt_mergeconfig(struct mrt_head *xconf, 
 				fatalx("mrt_mergeconfig: strlcpy");
 			MRT2MC(xm)->ReopenTimerInterval =
 			    MRT2MC(m)->ReopenTimerInterval;
-			MRT2MC(xm)->state = MRT_STATE_REOPEN;
+			xm->state = MRT_STATE_REOPEN;
 		}
 	}
 
 	LIST_FOREACH(xm, xconf, entry)
 		if (mrt_get(nconf, xm) == NULL)
 			/* REMOVE */
-			MRT2MC(xm)->state = MRT_STATE_REMOVE;
+			xm->state = MRT_STATE_REMOVE;
 
 	/* free config */
 	while ((m = LIST_FIRST(nconf)) != NULL) {
@@ -767,4 +723,3 @@ mrt_mergeconfig(struct mrt_head *xconf, 
 
 	return (0);
 }
-
