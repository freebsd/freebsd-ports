Index: bgpd/mrt.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/mrt.c,v
retrieving revision 1.1.1.7
retrieving revision 1.1.1.11
diff -u -p -r1.1.1.7 -r1.1.1.11
--- bgpd/mrt.c	14 Feb 2010 20:19:57 -0000	1.1.1.7
+++ bgpd/mrt.c	8 Dec 2012 10:37:09 -0000	1.1.1.11
@@ -1,4 +1,4 @@
-/*	$OpenBSD: mrt.c,v 1.63 2009/06/29 12:22:16 claudio Exp $ */
+/*	$OpenBSD: mrt.c,v 1.72 2011/11/06 10:29:05 guenther Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Claudio Jeker <claudio@openbsd.org>
@@ -21,6 +21,7 @@
 
 #include <errno.h>
 #include <fcntl.h>
+#include <limits.h>
 #include <stdlib.h>
 #include <string.h>
 #include <time.h>
@@ -32,20 +33,22 @@
 
 #include "mrt.h"
 
-int mrt_attr_dump(struct buf *, struct rde_aspath *, struct bgpd_addr *);
+int mrt_attr_dump(struct ibuf *, struct rde_aspath *, struct bgpd_addr *, int);
 int mrt_dump_entry_mp(struct mrt *, struct prefix *, u_int16_t,
     struct rde_peer*);
 int mrt_dump_entry(struct mrt *, struct prefix *, u_int16_t, struct rde_peer*);
-int mrt_dump_hdr_se(struct buf **, struct peer *, u_int16_t, u_int16_t,
+int mrt_dump_entry_v2(struct mrt *, struct rib_entry *, u_int32_t);
+int mrt_dump_peer(struct ibuf *, struct rde_peer *);
+int mrt_dump_hdr_se(struct ibuf **, struct peer *, u_int16_t, u_int16_t,
     u_int32_t, int);
-int mrt_dump_hdr_rde(struct buf **, u_int16_t type, u_int16_t, u_int32_t);
+int mrt_dump_hdr_rde(struct ibuf **, u_int16_t type, u_int16_t, u_int32_t);
 int mrt_open(struct mrt *, time_t);
 
 #define DUMP_BYTE(x, b)							\
 	do {								\
 		u_char		t = (b);				\
-		if (buf_add((x), &t, sizeof(t)) == -1) {		\
-			log_warnx("mrt_dump1: buf_add error");		\
+		if (ibuf_add((x), &t, sizeof(t)) == -1) {		\
+			log_warn("mrt_dump1: ibuf_add error");		\
 			goto fail;					\
 		}							\
 	} while (0)
@@ -54,8 +57,8 @@ int mrt_open(struct mrt *, time_t);
 	do {								\
 		u_int16_t	t;					\
 		t = htons((s));						\
-		if (buf_add((x), &t, sizeof(t)) == -1) {		\
-			log_warnx("mrt_dump2: buf_add error");		\
+		if (ibuf_add((x), &t, sizeof(t)) == -1) {		\
+			log_warn("mrt_dump2: ibuf_add error");		\
 			goto fail;					\
 		}							\
 	} while (0)
@@ -64,8 +67,8 @@ int mrt_open(struct mrt *, time_t);
 	do {								\
 		u_int32_t	t;					\
 		t = htonl((l));						\
-		if (buf_add((x), &t, sizeof(t)) == -1) {		\
-			log_warnx("mrt_dump3: buf_add error");		\
+		if (ibuf_add((x), &t, sizeof(t)) == -1) {		\
+			log_warn("mrt_dump3: ibuf_add error");		\
 			goto fail;					\
 		}							\
 	} while (0)
@@ -73,8 +76,8 @@ int mrt_open(struct mrt *, time_t);
 #define DUMP_NLONG(x, l)						\
 	do {								\
 		u_int32_t	t = (l);				\
-		if (buf_add((x), &t, sizeof(t)) == -1) {		\
-			log_warnx("mrt_dump4: buf_add error");		\
+		if (ibuf_add((x), &t, sizeof(t)) == -1) {		\
+			log_warn("mrt_dump4: ibuf_add error");		\
 			goto fail;					\
 		}							\
 	} while (0)
@@ -83,55 +86,64 @@ void
 mrt_dump_bgp_msg(struct mrt *mrt, void *pkg, u_int16_t pkglen,
     struct peer *peer)
 {
-	struct buf	*buf;
+	struct ibuf	*buf;
 	int		 incoming = 0;
+	u_int16_t	 subtype = BGP4MP_MESSAGE;
+
+	if (peer->capa.neg.as4byte)
+		subtype = BGP4MP_MESSAGE_AS4;
 
 	/* get the direction of the message to swap address and AS fields */
 	if (mrt->type == MRT_ALL_IN || mrt->type == MRT_UPDATE_IN)
 		incoming = 1;
 
-	if (mrt_dump_hdr_se(&buf, peer, MSG_PROTOCOL_BGP4MP, BGP4MP_MESSAGE,
+	if (mrt_dump_hdr_se(&buf, peer, MSG_PROTOCOL_BGP4MP, subtype,
 	    pkglen, incoming) == -1)
 		return;
 
-	if (buf_add(buf, pkg, pkglen) == -1) {
-		log_warnx("mrt_dump_bgp_msg: buf_add error");
-		buf_free(buf);
+	if (ibuf_add(buf, pkg, pkglen) == -1) {
+		log_warn("mrt_dump_bgp_msg: ibuf_add error");
+		ibuf_free(buf);
 		return;
 	}
 
-	buf_close(&mrt->wbuf, buf);
+	ibuf_close(&mrt->wbuf, buf);
 }
 
 void
 mrt_dump_state(struct mrt *mrt, u_int16_t old_state, u_int16_t new_state,
     struct peer *peer)
 {
-	struct buf	*buf;
+	struct ibuf	*buf;
+	u_int16_t	 subtype = BGP4MP_STATE_CHANGE;
+
+	if (peer->capa.neg.as4byte)
+		subtype = BGP4MP_STATE_CHANGE_AS4;
 
-	if (mrt_dump_hdr_se(&buf, peer, MSG_PROTOCOL_BGP4MP, BGP4MP_MESSAGE,
+	if (mrt_dump_hdr_se(&buf, peer, MSG_PROTOCOL_BGP4MP, subtype,
 	    2 * sizeof(short), 0) == -1)
 		return;
 
 	DUMP_SHORT(buf, old_state);
 	DUMP_SHORT(buf, new_state);
 
-	buf_close(&mrt->wbuf, buf);
+	ibuf_close(&mrt->wbuf, buf);
 	return;
 
 fail:
-	buf_free(buf);
+	ibuf_free(buf);
 }
 
 int
-mrt_attr_dump(struct buf *buf, struct rde_aspath *a, struct bgpd_addr *nexthop)
+mrt_attr_dump(struct ibuf *buf, struct rde_aspath *a, struct bgpd_addr *nexthop,
+    int v2)
 {
 	struct attr	*oa;
 	u_char		*pdata;
 	u_int32_t	 tmp;
 	int		 neednewpath = 0;
-	u_int16_t	 plen;
-	u_int8_t	 l;
+	u_int16_t	 plen, afi;
+	u_int8_t	 l, safi;
 
 	/* origin */
 	if (attr_writebuf(buf, ATTR_WELL_KNOWN, ATTR_ORIGIN,
@@ -140,12 +152,16 @@ mrt_attr_dump(struct buf *buf, struct rd
 
 	/* aspath */
 	pdata = aspath_prepend(a->aspath, rde_local_as(), 0, &plen);
-	pdata = aspath_deflate(pdata, &plen, &neednewpath);
-	if (attr_writebuf(buf, ATTR_WELL_KNOWN, ATTR_ASPATH, pdata, plen) == -1)
+	if (!v2)
+		pdata = aspath_deflate(pdata, &plen, &neednewpath);
+	if (attr_writebuf(buf, ATTR_WELL_KNOWN, ATTR_ASPATH, pdata,
+	    plen) == -1) {
+		free(pdata);
 		return (-1);
+	}
 	free(pdata);
 
-	if (nexthop) {
+	if (nexthop && nexthop->aid == AID_INET) {
 		/* nexthop, already network byte order */
 		if (attr_writebuf(buf, ATTR_WELL_KNOWN, ATTR_NEXTHOP,
 		    &nexthop->v4.s_addr, 4) ==	-1)
@@ -159,7 +175,7 @@ mrt_attr_dump(struct buf *buf, struct rd
 			return (-1);
 	}
 
-	/* local preference, only valid for ibgp */
+	/* local preference */
 	tmp = htonl(a->lpref);
 	if (attr_writebuf(buf, ATTR_WELL_KNOWN, ATTR_LOCALPREF, &tmp, 4) == -1)
 		return (-1);
@@ -173,12 +189,51 @@ mrt_attr_dump(struct buf *buf, struct rd
 			return (-1);
 	}
 
+	if (nexthop && nexthop->aid != AID_INET) {
+		struct ibuf *nhbuf;
+
+		if ((nhbuf = ibuf_dynamic(0, UCHAR_MAX)) == NULL)
+			return (-1);
+		if (!v2) {
+			if (aid2afi(nexthop->aid, &afi, &safi))
+				return (-1);
+			DUMP_SHORT(nhbuf, afi);
+			DUMP_BYTE(nhbuf, safi);
+		}
+		switch (nexthop->aid) {
+		case AID_INET6:
+			DUMP_BYTE(nhbuf, sizeof(struct in6_addr));
+			if (ibuf_add(nhbuf, &nexthop->v6,
+			    sizeof(struct in6_addr)) == -1) {
+			}
+			break;
+		case AID_VPN_IPv4:
+			DUMP_BYTE(nhbuf, sizeof(u_int64_t) +
+			    sizeof(struct in_addr));
+			DUMP_NLONG(nhbuf, 0);	/* set RD to 0 */
+			DUMP_NLONG(nhbuf, 0);
+			DUMP_NLONG(nhbuf, nexthop->v4.s_addr);
+			break;
+		}
+		if (!v2)
+			DUMP_BYTE(nhbuf, 0);
+		if (attr_writebuf(buf, ATTR_OPTIONAL, ATTR_MP_REACH_NLRI,
+		    nhbuf->buf, ibuf_size(nhbuf)) == -1) {
+fail:
+			ibuf_free(nhbuf);
+			return (-1);
+		}
+		ibuf_free(nhbuf);
+	}
+
 	if (neednewpath) {
 		pdata = aspath_prepend(a->aspath, rde_local_as(), 0, &plen);
 		if (plen != 0)
 			if (attr_writebuf(buf, ATTR_OPTIONAL|ATTR_TRANSITIVE,
-			    ATTR_AS4_PATH, pdata, plen) == -1)
+			    ATTR_AS4_PATH, pdata, plen) == -1) {
+				free(pdata);
 				return (-1);
+			}
 		free(pdata);
 	}
 
@@ -189,28 +244,26 @@ int
 mrt_dump_entry_mp(struct mrt *mrt, struct prefix *p, u_int16_t snum,
     struct rde_peer *peer)
 {
-	struct buf	*buf, *hbuf = NULL, *h2buf = NULL;
-	void		*bptr;
+	struct ibuf	*buf, *hbuf = NULL, *h2buf = NULL;
 	struct bgpd_addr addr, nexthop, *nh;
 	u_int16_t	 len;
-	u_int8_t	 p_len;
-	sa_family_t	 af;
+	u_int8_t	 aid;
 
-	if ((buf = buf_dynamic(0, MAX_PKTSIZE)) == NULL) {
-		log_warn("mrt_dump_entry_mp: buf_dynamic");
+	if ((buf = ibuf_dynamic(0, MAX_PKTSIZE)) == NULL) {
+		log_warn("mrt_dump_entry_mp: ibuf_dynamic");
 		return (-1);
 	}
 
-	if (mrt_attr_dump(buf, p->aspath, NULL) == -1) {
+	if (mrt_attr_dump(buf, p->aspath, NULL, 0) == -1) {
 		log_warnx("mrt_dump_entry_mp: mrt_attr_dump error");
 		goto fail;
 	}
-	len = buf_size(buf);
+	len = ibuf_size(buf);
 
-	if ((h2buf = buf_dynamic(MRT_BGP4MP_IPv4_HEADER_SIZE +
+	if ((h2buf = ibuf_dynamic(MRT_BGP4MP_IPv4_HEADER_SIZE +
 	    MRT_BGP4MP_IPv4_ENTRY_SIZE, MRT_BGP4MP_IPv6_HEADER_SIZE +
 	    MRT_BGP4MP_IPv6_ENTRY_SIZE + MRT_BGP4MP_MAX_PREFIXLEN)) == NULL) {
-		log_warn("mrt_dump_entry_mp: buf_dynamic");
+		log_warn("mrt_dump_entry_mp: ibuf_dynamic");
 		goto fail;
 	}
 
@@ -219,25 +272,26 @@ mrt_dump_entry_mp(struct mrt *mrt, struc
 	DUMP_SHORT(h2buf, /* ifindex */ 0);
 
 	/* XXX is this for peer self? */
-	af = peer->remote_addr.af == 0 ? p->prefix->af : peer->remote_addr.af;
-	switch (af) {
-	case AF_INET:
+	aid = peer->remote_addr.aid == AID_UNSPEC ? p->prefix->aid :
+	     peer->remote_addr.aid;
+	switch (aid) {
+	case AID_INET:
 		DUMP_SHORT(h2buf, AFI_IPv4);
 		DUMP_NLONG(h2buf, peer->local_v4_addr.v4.s_addr);
 		DUMP_NLONG(h2buf, peer->remote_addr.v4.s_addr);
 		break;
-	case AF_INET6:
+	case AID_INET6:
 		DUMP_SHORT(h2buf, AFI_IPv6);
-		if (buf_add(h2buf, &peer->local_v6_addr.v6,
+		if (ibuf_add(h2buf, &peer->local_v6_addr.v6,
 		    sizeof(struct in6_addr)) == -1 ||
-		    buf_add(h2buf, &peer->remote_addr.v6,
+		    ibuf_add(h2buf, &peer->remote_addr.v6,
 		    sizeof(struct in6_addr)) == -1) {
-			log_warnx("mrt_dump_entry_mp: buf_add error");
+			log_warn("mrt_dump_entry_mp: ibuf_add error");
 			goto fail;
 		}
 		break;
 	default:
-		log_warnx("king bula found new AF %d in mrt_dump_entry_mp", af);
+		log_warnx("king bula found new AF in mrt_dump_entry_mp");
 		goto fail;
 	}
 
@@ -247,25 +301,25 @@ mrt_dump_entry_mp(struct mrt *mrt, struc
 
 	if (p->aspath->nexthop == NULL) {
 		bzero(&nexthop, sizeof(struct bgpd_addr));
-		nexthop.af = addr.af;
+		nexthop.aid = addr.aid;
 		nh = &nexthop;
 	} else
 		nh = &p->aspath->nexthop->exit_nexthop;
 
 	pt_getaddr(p->prefix, &addr);
-	switch (addr.af) {
-	case AF_INET:
+	switch (addr.aid) {
+	case AID_INET:
 		DUMP_SHORT(h2buf, AFI_IPv4);	/* afi */
 		DUMP_BYTE(h2buf, SAFI_UNICAST);	/* safi */
 		DUMP_BYTE(h2buf, 4);		/* nhlen */
 		DUMP_NLONG(h2buf, nh->v4.s_addr);	/* nexthop */
 		break;
-	case AF_INET6:
+	case AID_INET6:
 		DUMP_SHORT(h2buf, AFI_IPv6);	/* afi */
 		DUMP_BYTE(h2buf, SAFI_UNICAST);	/* safi */
 		DUMP_BYTE(h2buf, 16);		/* nhlen */
-		if (buf_add(h2buf, &nh->v6, sizeof(struct in6_addr)) == -1) {
-			log_warnx("mrt_dump_entry_mp: buf_add error");
+		if (ibuf_add(h2buf, &nh->v6, sizeof(struct in6_addr)) == -1) {
+			log_warn("mrt_dump_entry_mp: ibuf_add error");
 			goto fail;
 		}
 		break;
@@ -274,35 +328,30 @@ mrt_dump_entry_mp(struct mrt *mrt, struc
 		goto fail;
 	}
 
-	p_len = PREFIX_SIZE(p->prefix->prefixlen);
-	if ((bptr = buf_reserve(h2buf, p_len)) == NULL) {
-		log_warnx("mrt_dump_entry_mp: buf_reserve error");
-		goto fail;
-	}
-	if (prefix_write(bptr, p_len, &addr, p->prefix->prefixlen) == -1) {
-		log_warnx("mrt_dump_entry_mp: prefix_write error");
+	if (prefix_writebuf(h2buf, &addr, p->prefix->prefixlen) == -1) {
+		log_warn("mrt_dump_entry_mp: prefix_writebuf error");
 		goto fail;
 	}
 
 	DUMP_SHORT(h2buf, len);
-	len += buf_size(h2buf);
+	len += ibuf_size(h2buf);
 
 	if (mrt_dump_hdr_rde(&hbuf, MSG_PROTOCOL_BGP4MP, BGP4MP_ENTRY,
 	    len) == -1)
 		goto fail;
 
-	buf_close(&mrt->wbuf, hbuf);
-	buf_close(&mrt->wbuf, h2buf);
-	buf_close(&mrt->wbuf, buf);
+	ibuf_close(&mrt->wbuf, hbuf);
+	ibuf_close(&mrt->wbuf, h2buf);
+	ibuf_close(&mrt->wbuf, buf);
 
 	return (len + MRT_HEADER_SIZE);
 
 fail:
 	if (hbuf)
-		buf_free(hbuf);
-	if (h2buf);
-		buf_free(h2buf);
-	buf_free(buf);
+		ibuf_free(hbuf);
+	if (h2buf)
+		ibuf_free(h2buf);
+	ibuf_free(buf);
 	return (-1);
 }
 
@@ -310,34 +359,37 @@ int
 mrt_dump_entry(struct mrt *mrt, struct prefix *p, u_int16_t snum,
     struct rde_peer *peer)
 {
-	struct buf	*buf, *hbuf;
+	struct ibuf	*buf, *hbuf;
 	struct bgpd_addr addr, *nh;
 	size_t		 len;
+	u_int16_t	 subtype;
+	u_int8_t	 dummy;
 
-	if (p->prefix->af != AF_INET && peer->remote_addr.af == AF_INET)
-		/* only able to dump IPv4 */
+	if (p->prefix->aid != peer->remote_addr.aid &&
+	    p->prefix->aid != AID_INET && p->prefix->aid != AID_INET6)
+		/* only able to dump pure IPv4/IPv6 */
 		return (0);
 
-	if ((buf = buf_dynamic(0, MAX_PKTSIZE)) == NULL) {
-		log_warnx("mrt_dump_entry: buf_dynamic");
+	if ((buf = ibuf_dynamic(0, MAX_PKTSIZE)) == NULL) {
+		log_warn("mrt_dump_entry: ibuf_dynamic");
 		return (-1);
 	}
 
 	if (p->aspath->nexthop == NULL) {
 		bzero(&addr, sizeof(struct bgpd_addr));
-		addr.af = AF_INET;
+		addr.aid = p->prefix->aid;
 		nh = &addr;
 	} else
 		nh = &p->aspath->nexthop->exit_nexthop;
-	if (mrt_attr_dump(buf, p->aspath, nh) == -1) {
+	if (mrt_attr_dump(buf, p->aspath, nh, 0) == -1) {
 		log_warnx("mrt_dump_entry: mrt_attr_dump error");
-		buf_free(buf);
+		ibuf_free(buf);
 		return (-1);
 	}
-	len = buf_size(buf);
-
-	if (mrt_dump_hdr_rde(&hbuf, MSG_TABLE_DUMP, AFI_IPv4, len) == -1) {
-		buf_free(buf);
+	len = ibuf_size(buf);
+	aid2afi(p->prefix->aid, &subtype, &dummy);
+	if (mrt_dump_hdr_rde(&hbuf, MSG_TABLE_DUMP, subtype, len) == -1) {
+		ibuf_free(buf);
 		return (-1);
 	}
 
@@ -345,23 +397,241 @@ mrt_dump_entry(struct mrt *mrt, struct p
 	DUMP_SHORT(hbuf, snum);
 
 	pt_getaddr(p->prefix, &addr);
-	DUMP_NLONG(hbuf, addr.v4.s_addr);
+	switch (p->prefix->aid) {
+	case AID_INET:
+		DUMP_NLONG(hbuf, addr.v4.s_addr);
+		break;
+	case AID_INET6:
+		if (ibuf_add(hbuf, &addr.v6, sizeof(struct in6_addr)) == -1) {
+			log_warn("mrt_dump_entry: ibuf_add error");
+			goto fail;
+		}
+		break;
+	}
 	DUMP_BYTE(hbuf, p->prefix->prefixlen);
 
 	DUMP_BYTE(hbuf, 1);		/* state */
 	DUMP_LONG(hbuf, p->lastchange);	/* originated */
-	DUMP_NLONG(hbuf, peer->remote_addr.v4.s_addr);
+	switch (p->prefix->aid) {
+	case AID_INET:
+		DUMP_NLONG(hbuf, peer->remote_addr.v4.s_addr);
+		break;
+	case AID_INET6:
+		if (ibuf_add(hbuf, &peer->remote_addr.v6,
+		    sizeof(struct in6_addr)) == -1) {
+			log_warn("mrt_dump_entry: ibuf_add error");
+			goto fail;
+		}
+		break;
+	}
 	DUMP_SHORT(hbuf, peer->short_as);
 	DUMP_SHORT(hbuf, len);
 
-	buf_close(&mrt->wbuf, hbuf);
-	buf_close(&mrt->wbuf, buf);
+	ibuf_close(&mrt->wbuf, hbuf);
+	ibuf_close(&mrt->wbuf, buf);
 
 	return (len + MRT_HEADER_SIZE);
 
 fail:
-	buf_free(hbuf);
-	buf_free(buf);
+	ibuf_free(hbuf);
+	ibuf_free(buf);
+	return (-1);
+}
+
+int
+mrt_dump_entry_v2(struct mrt *mrt, struct rib_entry *re, u_int32_t snum)
+{
+	struct ibuf	*buf, *hbuf = NULL;
+	struct prefix	*p;
+	struct bgpd_addr addr;
+	size_t		 len, off;
+	u_int16_t	 subtype, nump;
+
+	switch (re->prefix->aid) {
+	case AID_INET:
+		subtype = MRT_DUMP_V2_RIB_IPV4_UNICAST;
+		break;
+	case AID_INET6:
+		subtype = MRT_DUMP_V2_RIB_IPV6_UNICAST;
+		break;
+	default:
+		subtype = MRT_DUMP_V2_RIB_GENERIC;
+		break;
+	}
+
+	if ((buf = ibuf_dynamic(0, UINT_MAX)) == NULL) {
+		log_warn("mrt_dump_entry: ibuf_dynamic");
+		return (-1);
+	}
+
+	DUMP_LONG(buf, snum);
+	pt_getaddr(re->prefix, &addr);
+	if (subtype == MRT_DUMP_V2_RIB_GENERIC) {
+		u_int16_t afi;
+		u_int8_t safi;
+
+		aid2afi(re->prefix->aid, &afi, &safi);
+		DUMP_SHORT(buf, afi);
+		DUMP_BYTE(buf, safi);
+	}
+	if (prefix_writebuf(buf, &addr, re->prefix->prefixlen) == -1) {
+		log_warn("mrt_dump_entry_mp: prefix_writebuf error");
+		goto fail;
+	}
+
+	off = ibuf_size(buf);
+	if (ibuf_reserve(buf, sizeof(nump)) == NULL) {
+		log_warn("mrt_dump_v2_hdr: ibuf_reserve error");
+		goto fail;
+	}
+	nump = 0;
+	LIST_FOREACH(p, &re->prefix_h, rib_l) {
+		struct bgpd_addr	*nh;
+		struct ibuf		*tbuf;
+
+		if (p->aspath->nexthop == NULL) {
+			bzero(&addr, sizeof(struct bgpd_addr));
+			addr.aid = p->prefix->aid;
+			nh = &addr;
+		} else
+			nh = &p->aspath->nexthop->exit_nexthop;
+
+		DUMP_SHORT(buf, p->aspath->peer->mrt_idx);
+		DUMP_LONG(buf, p->lastchange); /* originated */
+
+		if ((tbuf = ibuf_dynamic(0, MAX_PKTSIZE)) == NULL) {
+			log_warn("mrt_dump_entry_v2: ibuf_dynamic");
+			return (-1);
+		}
+		if (mrt_attr_dump(tbuf, p->aspath, nh, 1) == -1) {
+			log_warnx("mrt_dump_entry_v2: mrt_attr_dump error");
+			ibuf_free(buf);
+			return (-1);
+		}
+		len = ibuf_size(tbuf);
+		DUMP_SHORT(buf, (u_int16_t)len);
+		if (ibuf_add(buf, tbuf->buf, ibuf_size(tbuf)) == -1) {
+			log_warn("mrt_dump_entry_v2: ibuf_add error");
+			ibuf_free(tbuf);
+			return (-1);
+		}
+		ibuf_free(tbuf);
+		nump++;
+	}
+	nump = htons(nump);
+	memcpy(ibuf_seek(buf, off, sizeof(nump)), &nump, sizeof(nump));
+
+	len = ibuf_size(buf);
+	if (mrt_dump_hdr_rde(&hbuf, MSG_TABLE_DUMP_V2, subtype, len) == -1) {
+		ibuf_free(buf);
+		return (-1);
+	}
+
+	ibuf_close(&mrt->wbuf, hbuf);
+	ibuf_close(&mrt->wbuf, buf);
+
+	return (0);
+fail:
+	if (hbuf)
+		ibuf_free(hbuf);
+	ibuf_free(buf);
+	return (-1);
+}
+
+int
+mrt_dump_v2_hdr(struct mrt *mrt, struct bgpd_config *conf,
+    struct rde_peer_head *ph)
+{
+	struct rde_peer	*peer;
+	struct ibuf	*buf, *hbuf = NULL;
+	size_t		 len, off;
+	u_int16_t	 nlen, nump;
+
+	if ((buf = ibuf_dynamic(0, UINT_MAX)) == NULL) {
+		log_warn("mrt_dump_v2_hdr: ibuf_dynamic");
+		return (-1);
+	}
+
+	DUMP_NLONG(buf, conf->bgpid);
+	nlen = strlen(mrt->rib);
+	if (nlen > 0)
+		nlen += 1;
+	DUMP_SHORT(buf, nlen);
+	if (ibuf_add(buf, mrt->rib, nlen) == -1) {
+		log_warn("mrt_dump_v2_hdr: ibuf_add error");
+		goto fail;
+	}
+
+	off = ibuf_size(buf);
+	if (ibuf_reserve(buf, sizeof(nump)) == NULL) {
+		log_warn("mrt_dump_v2_hdr: ibuf_reserve error");
+		goto fail;
+	}
+	nump = 0;
+	LIST_FOREACH(peer, ph, peer_l) {
+		peer->mrt_idx = nump;
+		if (mrt_dump_peer(buf, peer) == -1)
+			goto fail;
+		nump++;
+	}
+	nump = htons(nump);
+	memcpy(ibuf_seek(buf, off, sizeof(nump)), &nump, sizeof(nump));
+
+	len = ibuf_size(buf);
+	if (mrt_dump_hdr_rde(&hbuf, MSG_TABLE_DUMP_V2,
+	    MRT_DUMP_V2_PEER_INDEX_TABLE, len) == -1)
+		goto fail;
+
+	ibuf_close(&mrt->wbuf, hbuf);
+	ibuf_close(&mrt->wbuf, buf);
+
+	return (0);
+fail:
+	if (hbuf)
+		ibuf_free(hbuf);
+	ibuf_free(buf);
+	return (-1);
+}
+
+int
+mrt_dump_peer(struct ibuf *buf, struct rde_peer *peer)
+{
+	u_int8_t	type = 0;
+
+	if (peer->capa.as4byte)
+		type |= MRT_DUMP_V2_PEER_BIT_A;
+	if (peer->remote_addr.aid == AID_INET6)
+		type |= MRT_DUMP_V2_PEER_BIT_I;
+
+	DUMP_BYTE(buf, type);
+	DUMP_LONG(buf, peer->remote_bgpid);
+
+	switch (peer->remote_addr.aid) {
+	case AID_INET:
+		DUMP_NLONG(buf, peer->remote_addr.v4.s_addr);
+		break;
+	case AID_INET6:
+		if (ibuf_add(buf, &peer->remote_addr.v6,
+		    sizeof(struct in6_addr)) == -1) {
+			log_warn("mrt_dump_peer: ibuf_add error");
+			goto fail;
+		}
+		break;
+	case AID_UNSPEC: /* XXX special handling for peer_self? */
+		DUMP_NLONG(buf, 0);
+		break;
+	default:
+		log_warnx("king bula found new AF in mrt_dump_entry_mp");
+		goto fail;
+	}
+
+	if (peer->capa.as4byte)
+		DUMP_LONG(buf, peer->conf.remote_as);
+	else
+		DUMP_SHORT(buf, peer->short_as);
+
+	return (0);
+fail:
 	return (-1);
 }
 
@@ -371,6 +641,11 @@ mrt_dump_upcall(struct rib_entry *re, vo
 	struct mrt		*mrtbuf = ptr;
 	struct prefix		*p;
 
+	if (mrtbuf->type == MRT_TABLE_DUMP_V2) {
+		mrt_dump_entry_v2(mrtbuf, re, mrtbuf->seqnum++);
+		return;
+	}
+
 	/*
 	 * dump all prefixes even the inactive ones. That is the way zebra
 	 * dumps the table so we do the same. If only the active route should
@@ -387,7 +662,7 @@ mrt_dump_upcall(struct rib_entry *re, vo
 }
 
 void
-mrt_dump_done(void *ptr)
+mrt_done(void *ptr)
 {
 	struct mrt		*mrtbuf = ptr;
 
@@ -395,14 +670,14 @@ mrt_dump_done(void *ptr)
 }
 
 int
-mrt_dump_hdr_se(struct buf ** bp, struct peer *peer, u_int16_t type,
+mrt_dump_hdr_se(struct ibuf ** bp, struct peer *peer, u_int16_t type,
     u_int16_t subtype, u_int32_t len, int swap)
 {
 	time_t	 	now;
 
-	if ((*bp = buf_dynamic(MRT_HEADER_SIZE, MRT_HEADER_SIZE +
+	if ((*bp = ibuf_dynamic(MRT_HEADER_SIZE, MRT_HEADER_SIZE +
 	    MRT_BGP4MP_AS4_IPv6_HEADER_SIZE + len)) == NULL) {
-		log_warnx("mrt_dump_hdr_se: buf_open error");
+		log_warn("mrt_dump_hdr_se: ibuf_dynamic error");
 		return (-1);
 	}
 
@@ -468,23 +743,23 @@ mrt_dump_hdr_se(struct buf ** bp, struct
 	case AF_INET6:
 		DUMP_SHORT(*bp, AFI_IPv6);
 		if (!swap)
-			if (buf_add(*bp, &((struct sockaddr_in6 *)
+			if (ibuf_add(*bp, &((struct sockaddr_in6 *)
 			    &peer->sa_local)->sin6_addr,
 			    sizeof(struct in6_addr)) == -1) {
-				log_warnx("mrt_dump_hdr_se: buf_add error");
+				log_warn("mrt_dump_hdr_se: ibuf_add error");
 				goto fail;
 			}
-		if (buf_add(*bp,
+		if (ibuf_add(*bp,
 		    &((struct sockaddr_in6 *)&peer->sa_remote)->sin6_addr,
 		    sizeof(struct in6_addr)) == -1) {
-			log_warnx("mrt_dump_hdr_se: buf_add error");
+			log_warn("mrt_dump_hdr_se: ibuf_add error");
 			goto fail;
 		}
 		if (swap)
-			if (buf_add(*bp, &((struct sockaddr_in6 *)
+			if (ibuf_add(*bp, &((struct sockaddr_in6 *)
 			    &peer->sa_local)->sin6_addr,
 			    sizeof(struct in6_addr)) == -1) {
-				log_warnx("mrt_dump_hdr_se: buf_add error");
+				log_warn("mrt_dump_hdr_se: ibuf_add error");
 				goto fail;
 			}
 		break;
@@ -493,20 +768,20 @@ mrt_dump_hdr_se(struct buf ** bp, struct
 	return (0);
 
 fail:
-	buf_free(*bp);
+	ibuf_free(*bp);
 	return (-1);
 }
 
 int
-mrt_dump_hdr_rde(struct buf **bp, u_int16_t type, u_int16_t subtype,
+mrt_dump_hdr_rde(struct ibuf **bp, u_int16_t type, u_int16_t subtype,
     u_int32_t len)
 {
 	time_t		 now;
 
-	if ((*bp = buf_dynamic(MRT_HEADER_SIZE, MRT_HEADER_SIZE +
+	if ((*bp = ibuf_dynamic(MRT_HEADER_SIZE, MRT_HEADER_SIZE +
 	    MRT_BGP4MP_AS4_IPv6_HEADER_SIZE + MRT_BGP4MP_IPv6_ENTRY_SIZE)) ==
 	    NULL) {
-		log_warnx("mrt_dump_hdr_rde: buf_dynamic error");
+		log_warn("mrt_dump_hdr_rde: ibuf_dynamic error");
 		return (-1);
 	}
 
@@ -517,19 +792,28 @@ mrt_dump_hdr_rde(struct buf **bp, u_int1
 
 	switch (type) {
 	case MSG_TABLE_DUMP:
-		DUMP_LONG(*bp, MRT_DUMP_HEADER_SIZE + len);
+		switch (subtype) {
+		case AFI_IPv4:
+			len += MRT_DUMP_HEADER_SIZE;
+			break;
+		case AFI_IPv6:
+			len += MRT_DUMP_HEADER_SIZE_V6;
+			break;
+		}
+		DUMP_LONG(*bp, len);
 		break;
 	case MSG_PROTOCOL_BGP4MP:
+	case MSG_TABLE_DUMP_V2:
 		DUMP_LONG(*bp, len);
 		break;
 	default:
 		log_warnx("mrt_dump_hdr_rde: unsupported type");
 		goto fail;
-	}	
+	}
 	return (0);
 
 fail:
-	buf_free(*bp);
+	ibuf_free(*bp);
 	return (-1);
 }
 
@@ -538,21 +822,22 @@ mrt_write(struct mrt *mrt)
 {
 	int	r;
 
-	if ((r = buf_write(&mrt->wbuf)) < 0) {
+	if ((r = ibuf_write(&mrt->wbuf)) < 0) {
 		log_warn("mrt dump aborted, mrt_write");
 		mrt_clean(mrt);
+		mrt_done(mrt);
 	}
 }
 
 void
 mrt_clean(struct mrt *mrt)
 {
-	struct buf	*b;
+	struct ibuf	*b;
 
 	close(mrt->wbuf.fd);
 	while ((b = TAILQ_FIRST(&mrt->wbuf.bufs))) {
 		TAILQ_REMOVE(&mrt->wbuf.bufs, b, entry);
-		buf_free(b);
+		ibuf_free(b);
 	}
 	mrt->wbuf.queued = 0;
 }
@@ -590,7 +875,8 @@ mrt_open(struct mrt *mrt, time_t now)
 	else
 		type = IMSG_MRT_REOPEN;
 
-	if (mrt->type == MRT_TABLE_DUMP || mrt->type == MRT_TABLE_DUMP_MP)
+	if (mrt->type == MRT_TABLE_DUMP || mrt->type == MRT_TABLE_DUMP_MP ||
+	    mrt->type == MRT_TABLE_DUMP_V2)
 		i = 0;
 
 	if (imsg_compose(mrt_imsgbuf[i], type, 0, 0, fd,
@@ -659,7 +945,9 @@ mrt_handler(struct mrt_head *mrt)
 	LIST_FOREACH(m, mrt, entry) {
 		if (m->state == MRT_STATE_RUNNING &&
 		    (MRT2MC(m)->ReopenTimerInterval != 0 ||
-		     m->type == MRT_TABLE_DUMP)) {
+		     m->type == MRT_TABLE_DUMP ||
+		     m->type == MRT_TABLE_DUMP_MP ||
+		     m->type == MRT_TABLE_DUMP_V2)) {
 			if (mrt_open(m, now) == -1)
 				continue;
 			MRT2MC(m)->ReopenTimer =
