Index: bgpd/rde_update.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/rde_update.c,v
retrieving revision 1.1.1.7
retrieving revision 1.8
diff -u -p -r1.1.1.7 -r1.8
--- bgpd/rde_update.c	14 Feb 2010 20:19:57 -0000	1.1.1.7
+++ bgpd/rde_update.c	13 Oct 2012 18:36:00 -0000	1.8
@@ -1,4 +1,4 @@
-/*	$OpenBSD: rde_update.c,v 1.68 2009/06/06 01:10:29 claudio Exp $ */
+/*	$OpenBSD: rde_update.c,v 1.77 2010/01/13 06:02:37 claudio Exp $ */
 
 /*
  * Copyright (c) 2004 Claudio Jeker <claudio@openbsd.org>
@@ -17,19 +17,27 @@
  */
 #include <sys/types.h>
 #include <sys/queue.h>
+#if defined(__FreeBSD__)	/* sys/hash.h */
+#include "hash.h"
+#else
 #include <sys/hash.h>
+#endif /* defined(__FreeBSD__) */
 
+#include <limits.h>
 #include <stdlib.h>
 #include <string.h>
+#if defined(__FreeBSD__)	/* limits.h */
+#include <limits.h>
+#endif /* defined(__FreeBSD__) */
 
 #include "bgpd.h"
 #include "rde.h"
 
 in_addr_t	up_get_nexthop(struct rde_peer *, struct rde_aspath *);
 int		up_generate_mp_reach(struct rde_peer *, struct update_attr *,
-		    struct rde_aspath *, sa_family_t);
+		    struct rde_aspath *, u_int8_t);
 int		up_generate_attr(struct rde_peer *, struct update_attr *,
-		    struct rde_aspath *, sa_family_t);
+		    struct rde_aspath *, u_int8_t);
 
 /* update stuff. */
 struct update_prefix {
@@ -65,10 +73,12 @@ RB_GENERATE(uptree_attr, update_attr, en
 void
 up_init(struct rde_peer *peer)
 {
-	TAILQ_INIT(&peer->updates);
-	TAILQ_INIT(&peer->withdraws);
-	TAILQ_INIT(&peer->updates6);
-	TAILQ_INIT(&peer->withdraws6);
+	u_int8_t	i;
+
+	for (i = 0; i < AID_MAX; i++) {
+		TAILQ_INIT(&peer->updates[i]);
+		TAILQ_INIT(&peer->withdraws[i]);
+	}
 	RB_INIT(&peer->up_prefix);
 	RB_INIT(&peer->up_attrs);
 	peer->up_pcnt = 0;
@@ -103,8 +113,10 @@ up_clear(struct uplist_attr *updates, st
 void
 up_down(struct rde_peer *peer)
 {
-	up_clear(&peer->updates, &peer->withdraws);
-	up_clear(&peer->updates6, &peer->withdraws6);
+	u_int8_t	i;
+
+	for (i = 0; i < AID_MAX; i++)
+		up_clear(&peer->updates[i], &peer->withdraws[i]);
 
 	RB_INIT(&peer->up_prefix);
 	RB_INIT(&peer->up_attrs);
@@ -120,19 +132,19 @@ up_prefix_cmp(struct update_prefix *a, s
 {
 	int	i;
 
-	if (a->prefix.af < b->prefix.af)
+	if (a->prefix.aid < b->prefix.aid)
 		return (-1);
-	if (a->prefix.af > b->prefix.af)
+	if (a->prefix.aid > b->prefix.aid)
 		return (1);
 
-	switch (a->prefix.af) {
-	case AF_INET:
+	switch (a->prefix.aid) {
+	case AID_INET:
 		if (ntohl(a->prefix.v4.s_addr) < ntohl(b->prefix.v4.s_addr))
 			return (-1);
 		if (ntohl(a->prefix.v4.s_addr) > ntohl(b->prefix.v4.s_addr))
 			return (1);
 		break;
-	case AF_INET6:
+	case AID_INET6:
 		i = memcmp(&a->prefix.v6, &b->prefix.v6,
 		    sizeof(struct in6_addr));
 		if (i > 0)
@@ -140,6 +152,25 @@ up_prefix_cmp(struct update_prefix *a, s
 		if (i < 0)
 			return (-1);
 		break;
+	case AID_VPN_IPv4:
+		if (betoh64(a->prefix.vpn4.rd) < betoh64(b->prefix.vpn4.rd))
+			return (-1);
+		if (betoh64(a->prefix.vpn4.rd) > betoh64(b->prefix.vpn4.rd))
+			return (1);
+		if (ntohl(a->prefix.v4.s_addr) < ntohl(b->prefix.v4.s_addr))
+			return (-1);
+		if (ntohl(a->prefix.v4.s_addr) > ntohl(b->prefix.v4.s_addr))
+			return (1);
+		if (a->prefixlen < b->prefixlen)
+			return (-1);
+		if (a->prefixlen > b->prefixlen)
+			return (1);
+		if (a->prefix.vpn4.labellen < b->prefix.vpn4.labellen)
+			return (-1);
+		if (a->prefix.vpn4.labellen > b->prefix.vpn4.labellen)
+			return (1);
+		return (memcmp(a->prefix.vpn4.labelstack,
+		    b->prefix.vpn4.labelstack, a->prefix.vpn4.labellen));
 	default:
 		fatalx("pt_prefix_cmp: unknown af");
 	}
@@ -174,18 +205,8 @@ up_add(struct rde_peer *peer, struct upd
 	struct uplist_attr	*upl = NULL;
 	struct uplist_prefix	*wdl = NULL;
 
-	switch (p->prefix.af) {
-	case AF_INET:
-		upl = &peer->updates;
-		wdl = &peer->withdraws;
-		break;
-	case AF_INET6:
-		upl = &peer->updates6;
-		wdl = &peer->withdraws6;
-		break;
-	default:
-		fatalx("up_add: unknown AF");
-	}
+	upl = &peer->updates[p->prefix.aid];
+	wdl = &peer->withdraws[p->prefix.aid];
 
 	/* 1. search for attr */
 	if (a != NULL && (na = RB_FIND(uptree_attr, &peer->up_attrs, a)) ==
@@ -270,23 +291,16 @@ up_test_update(struct rde_peer *peer, st
 		/* Do not send routes back to sender */
 		return (0);
 
+	if (p->aspath->flags & F_ATTR_PARSE_ERR)
+		fatalx("try to send out a botched path");
 	if (p->aspath->flags & F_ATTR_LOOP)
 		fatalx("try to send out a looped path");
 
 	pt_getaddr(p->prefix, &addr);
-	switch (addr.af) {
-	case AF_INET:
-		if (peer->capa_announced.mp_v4 == SAFI_NONE &&
-		    peer->capa_received.mp_v6 != SAFI_NONE)
-			return (-1);
-		break;
-	case AF_INET6:
-		if (peer->capa_announced.mp_v6 == SAFI_NONE)
-			return (-1);
-		break;
-	}
+	if (peer->capa.mp[addr.aid] == 0)
+		return (-1);
 
-	if (p->aspath->peer->conf.ebgp == 0 && peer->conf.ebgp == 0) {
+	if (!p->aspath->peer->conf.ebgp && !peer->conf.ebgp) {
 		/*
 		 * route reflector redistribution rules:
 		 * 1. if announce is set                -> announce
@@ -325,13 +339,13 @@ up_test_update(struct rde_peer *peer, st
 	}
 
 	/* well known communities */
-	if (rde_filter_community(p->aspath,
+	if (community_match(p->aspath,
 	    COMMUNITY_WELLKNOWN, COMMUNITY_NO_ADVERTISE))
 		return (0);
-	if (peer->conf.ebgp && rde_filter_community(p->aspath,
+	if (peer->conf.ebgp && community_match(p->aspath,
 	    COMMUNITY_WELLKNOWN, COMMUNITY_NO_EXPORT))
 		return (0);
-	if (peer->conf.ebgp && rde_filter_community(p->aspath,
+	if (peer->conf.ebgp && community_match(p->aspath,
 	    COMMUNITY_WELLKNOWN, COMMUNITY_NO_EXPSUBCONFED))
 		return (0);
 
@@ -362,7 +376,7 @@ up_generate(struct rde_peer *peer, struc
 		if (ua == NULL)
 			fatal("up_generate");
 
-		if (up_generate_attr(peer, ua, asp, addr->af) == -1) {
+		if (up_generate_attr(peer, ua, asp, addr->aid) == -1) {
 			log_warnx("generation of bgp path attributes failed");
 			free(ua);
 			return (-1);
@@ -444,18 +458,12 @@ up_generate_updates(struct filter_head *
 /* send a default route to the specified peer */
 void
 up_generate_default(struct filter_head *rules, struct rde_peer *peer,
-    sa_family_t af)
+    u_int8_t aid)
 {
 	struct rde_aspath	*asp, *fasp;
 	struct bgpd_addr	 addr;
 
-	if (peer->capa_received.mp_v4 == SAFI_NONE &&
-	    peer->capa_received.mp_v6 != SAFI_NONE &&
-	    af == AF_INET)
-		return;
-
-	if (peer->capa_received.mp_v6 == SAFI_NONE &&
-	    af == AF_INET6)
+	if (peer->capa.mp[aid] == 0)
 		return;
 
 	asp = path_get();
@@ -471,7 +479,7 @@ up_generate_default(struct filter_head *
 
 	/* filter as usual */
 	bzero(&addr, sizeof(addr));
-	addr.af = af;
+	addr.aid = aid;
 
 	if (rde_filter(peer->ribid, &fasp, rules, peer, asp, &addr, 0, NULL,
 	    DIR_OUT) == ACTION_DENY) {
@@ -491,6 +499,43 @@ up_generate_default(struct filter_head *
 	path_put(asp);
 }
 
+/* generate a EoR marker in the update list. This is a horrible hack. */
+int
+up_generate_marker(struct rde_peer *peer, u_int8_t aid)
+{
+	struct update_attr	*ua;
+	struct update_attr	*na = NULL;
+	struct uplist_attr	*upl = NULL;
+
+	ua = calloc(1, sizeof(struct update_attr));
+	if (ua == NULL)
+		fatal("up_generate_marker");
+
+	upl = &peer->updates[aid];
+
+	/* 1. search for attr */
+	if ((na = RB_FIND(uptree_attr, &peer->up_attrs, ua)) == NULL) {
+		/* 1.1 if not found -> add */
+		TAILQ_INIT(&ua->prefix_h);
+		if (RB_INSERT(uptree_attr, &peer->up_attrs, ua) != NULL) {
+			log_warnx("uptree_attr insert failed");
+			/* cleanup */
+			free(ua);
+			return (-1);
+		}
+		TAILQ_INSERT_TAIL(upl, ua, attr_l);
+		peer->up_acnt++;
+	} else {
+		/* 1.2 if found -> use that, free ua */
+		free(ua);
+		ua = na;
+		/* move to end of update queue */
+		TAILQ_REMOVE(upl, ua, attr_l);
+		TAILQ_INSERT_TAIL(upl, ua, attr_l);
+	}
+	return (0);
+}
+
 u_char	up_attr_buf[4096];
 
 /* only for IPv4 */
@@ -551,28 +596,41 @@ up_get_nexthop(struct rde_peer *peer, st
 
 int
 up_generate_mp_reach(struct rde_peer *peer, struct update_attr *upa,
-    struct rde_aspath *a, sa_family_t af)
+    struct rde_aspath *a, u_int8_t aid)
 {
 	u_int16_t	tmp;
 
-	switch (af) {
-	case AF_INET6:
+	switch (aid) {
+	case AID_INET6:
 		upa->mpattr_len = 21; /* AFI + SAFI + NH LEN + NH + Reserved */
 		upa->mpattr = malloc(upa->mpattr_len);
 		if (upa->mpattr == NULL)
 			fatal("up_generate_mp_reach");
-		tmp = htons(AFI_IPv6);
+		if (aid2afi(aid, &tmp, &upa->mpattr[2]))
+			fatalx("up_generate_mp_reachi: bad AID");
+		tmp = htons(tmp);
 		memcpy(upa->mpattr, &tmp, sizeof(tmp));
-		upa->mpattr[2] = SAFI_UNICAST;
 		upa->mpattr[3] = sizeof(struct in6_addr);
 		upa->mpattr[20] = 0; /* Reserved must be 0 */
 
 		/* nexthop dance see also up_get_nexthop() */
-		if (peer->conf.ebgp == 0) {
+		if (a->flags & F_NEXTHOP_NOMODIFY) {
+			/* no modify flag set */
+			if (a->nexthop == NULL)
+				memcpy(&upa->mpattr[4], &peer->local_v6_addr.v6,
+				    sizeof(struct in6_addr));
+			else
+				memcpy(&upa->mpattr[4],
+				    &a->nexthop->exit_nexthop.v6,
+				    sizeof(struct in6_addr));
+		} else if (a->flags & F_NEXTHOP_SELF)
+			memcpy(&upa->mpattr[4], &peer->local_v6_addr.v6,
+			    sizeof(struct in6_addr));
+		else if (!peer->conf.ebgp) {
 			/* ibgp */
 			if (a->nexthop == NULL ||
-			    (a->nexthop->exit_nexthop.af == AF_INET6 &&
-			    memcmp(&a->nexthop->exit_nexthop.v6,
+			    (a->nexthop->exit_nexthop.aid == AID_INET6 &&
+			    !memcmp(&a->nexthop->exit_nexthop.v6,
 			    &peer->remote_addr.v6, sizeof(struct in6_addr))))
 				memcpy(&upa->mpattr[4], &peer->local_v6_addr.v6,
 				    sizeof(struct in6_addr));
@@ -603,6 +661,68 @@ up_generate_mp_reach(struct rde_peer *pe
 			memcpy(&upa->mpattr[4], &peer->local_v6_addr.v6,
 			    sizeof(struct in6_addr));
 		return (0);
+	case AID_VPN_IPv4:
+		upa->mpattr_len = 17; /* AFI + SAFI + NH LEN + NH + Reserved */
+		upa->mpattr = calloc(upa->mpattr_len, 1);
+		if (upa->mpattr == NULL)
+			fatal("up_generate_mp_reach");
+		if (aid2afi(aid, &tmp, &upa->mpattr[2]))
+			fatalx("up_generate_mp_reachi: bad AID");
+		tmp = htons(tmp);
+		memcpy(upa->mpattr, &tmp, sizeof(tmp));
+		upa->mpattr[3] = sizeof(u_int64_t) + sizeof(struct in_addr);
+
+		/* nexthop dance see also up_get_nexthop() */
+		if (a->flags & F_NEXTHOP_NOMODIFY) {
+			/* no modify flag set */
+			if (a->nexthop == NULL)
+				memcpy(&upa->mpattr[12],
+				    &peer->local_v4_addr.v4,
+				    sizeof(struct in_addr));
+			else
+				/* nexthops are stored as IPv4 addrs */
+				memcpy(&upa->mpattr[12],
+				    &a->nexthop->exit_nexthop.v4,
+				    sizeof(struct in_addr));
+		} else if (a->flags & F_NEXTHOP_SELF)
+			memcpy(&upa->mpattr[12], &peer->local_v4_addr.v4,
+			    sizeof(struct in_addr));
+		else if (!peer->conf.ebgp) {
+			/* ibgp */
+			if (a->nexthop == NULL ||
+			    (a->nexthop->exit_nexthop.aid == AID_INET &&
+			    !memcmp(&a->nexthop->exit_nexthop.v4,
+			    &peer->remote_addr.v4, sizeof(struct in_addr))))
+				memcpy(&upa->mpattr[12],
+				    &peer->local_v4_addr.v4,
+				    sizeof(struct in_addr));
+			else
+				memcpy(&upa->mpattr[12],
+				    &a->nexthop->exit_nexthop.v4,
+				    sizeof(struct in_addr));
+		} else if (peer->conf.distance == 1) {
+			/* ebgp directly connected */
+			if (a->nexthop != NULL &&
+			    a->nexthop->flags & NEXTHOP_CONNECTED)
+				if (prefix_compare(&peer->remote_addr,
+				    &a->nexthop->nexthop_net,
+				    a->nexthop->nexthop_netlen) == 0) {
+					/*
+					 * nexthop and peer are in the same
+					 * subnet
+					 */
+					memcpy(&upa->mpattr[12],
+					    &a->nexthop->exit_nexthop.v4,
+					    sizeof(struct in_addr));
+					return (0);
+				}
+			memcpy(&upa->mpattr[12], &peer->local_v4_addr.v4,
+			    sizeof(struct in_addr));
+		} else
+			/* ebgp multihop */
+			memcpy(&upa->mpattr[12], &peer->local_v4_addr.v4,
+			    sizeof(struct in_addr));
+		return (0);
 	default:
 		break;
 	}
@@ -611,7 +731,7 @@ up_generate_mp_reach(struct rde_peer *pe
 
 int
 up_generate_attr(struct rde_peer *peer, struct update_attr *upa,
-    struct rde_aspath *a, sa_family_t af)
+    struct rde_aspath *a, u_int8_t aid)
 {
 	struct attr	*oa, *newaggr = NULL;
 	u_char		*pdata;
@@ -643,8 +763,8 @@ up_generate_attr(struct rde_peer *peer, 
 	wlen += r; len -= r;
 	free(pdata);
 
-	switch (af) {
-	case AF_INET:
+	switch (aid) {
+	case AID_INET:
 		nexthop = up_get_nexthop(peer, a);
 		if ((r = attr_write(up_attr_buf + wlen, len, ATTR_WELL_KNOWN,
 		    ATTR_NEXTHOP, &nexthop, 4)) == -1)
@@ -659,9 +779,11 @@ up_generate_attr(struct rde_peer *peer, 
 	/*
 	 * The old MED from other peers MUST not be announced to others
 	 * unless the MED is originating from us or the peer is an IBGP one.
+	 * Only exception are routers with "transparent-as yes" set.
 	 */
-	if (a->flags & F_ATTR_MED && (peer->conf.ebgp == 0 ||
-	    a->flags & F_ATTR_MED_ANNOUNCE)) {
+	if (a->flags & F_ATTR_MED && (!peer->conf.ebgp ||
+	    a->flags & F_ATTR_MED_ANNOUNCE ||
+	    peer->conf.flags & PEERFLAG_TRANS_AS)) {
 		tmp32 = htonl(a->med);
 		if ((r = attr_write(up_attr_buf + wlen, len, ATTR_OPTIONAL,
 		    ATTR_MED, &tmp32, 4)) == -1)
@@ -669,7 +791,7 @@ up_generate_attr(struct rde_peer *peer, 
 		wlen += r; len -= r;
 	}
 
-	if (peer->conf.ebgp == 0) {
+	if (!peer->conf.ebgp) {
 		/* local preference, only valid for ibgp */
 		tmp32 = htonl(a->lpref);
 		if ((r = attr_write(up_attr_buf + wlen, len, ATTR_WELL_KNOWN,
@@ -704,7 +826,7 @@ up_generate_attr(struct rde_peer *peer, 
 				u_int16_t	tas;
 
 				if ((!(oa->flags & ATTR_TRANSITIVE)) &&
-				    peer->conf.ebgp != 0) {
+				    peer->conf.ebgp) {
 					r = 0;
 					break;
 				}
@@ -730,7 +852,7 @@ up_generate_attr(struct rde_peer *peer, 
 		case ATTR_ORIGINATOR_ID:
 		case ATTR_CLUSTER_LIST:
 			if ((!(oa->flags & ATTR_TRANSITIVE)) &&
-			    peer->conf.ebgp != 0) {
+			    peer->conf.ebgp) {
 				r = 0;
 				break;
 			}
@@ -791,7 +913,7 @@ up_generate_attr(struct rde_peer *peer, 
 
 	/* write mp attribute to different buffer */
 	if (ismp)
-		if (up_generate_mp_reach(peer, upa, a, AF_INET6) == -1)
+		if (up_generate_mp_reach(peer, upa, a, aid) == -1)
 			return (-1);
 
 	/* the bgp path attributes are now stored in the global buf */
@@ -810,6 +932,7 @@ up_dump_prefix(u_char *buf, int len, str
 {
 	struct update_prefix	*upp;
 	int			 r, wpos = 0;
+	u_int8_t		 i;
 
 	while ((upp = TAILQ_FIRST(prefix_head)) != NULL) {
 		if ((r = prefix_write(buf + wpos, len - wpos,
@@ -820,13 +943,14 @@ up_dump_prefix(u_char *buf, int len, str
 			log_warnx("dequeuing update failed.");
 		TAILQ_REMOVE(upp->prefix_h, upp, prefix_l);
 		peer->up_pcnt--;
-		if (upp->prefix_h == &peer->withdraws ||
-		    upp->prefix_h == &peer->withdraws6) {
-			peer->up_wcnt--;
-			peer->prefix_sent_withdraw++;
-		} else {
-			peer->up_nlricnt--;
-			peer->prefix_sent_update++;
+		for (i = 0; i < AID_MAX; i++) {
+			if (upp->prefix_h == &peer->withdraws[i]) {
+				peer->up_wcnt--;
+				peer->prefix_sent_withdraw++;
+			} else {
+				peer->up_nlricnt--;
+				peer->prefix_sent_update++;
+			}
 		}
 		free(upp);
 	}
@@ -844,16 +968,21 @@ up_dump_attrnlri(u_char *buf, int len, s
 	 * It is possible that a queued path attribute has no nlri prefix.
 	 * Ignore and remove those path attributes.
 	 */
-	while ((upa = TAILQ_FIRST(&peer->updates)) != NULL)
+	while ((upa = TAILQ_FIRST(&peer->updates[AID_INET])) != NULL)
 		if (TAILQ_EMPTY(&upa->prefix_h)) {
+			attr_len = upa->attr_len;
 			if (RB_REMOVE(uptree_attr, &peer->up_attrs,
 			    upa) == NULL)
 				log_warnx("dequeuing update failed.");
-			TAILQ_REMOVE(&peer->updates, upa, attr_l);
+			TAILQ_REMOVE(&peer->updates[AID_INET], upa, attr_l);
 			free(upa->attr);
 			free(upa->mpattr);
 			free(upa);
 			peer->up_acnt--;
+			/* XXX horrible hack,
+			 * if attr_len is 0, it is a EoR marker */
+			if (attr_len == 0)
+				return (-1);
 		} else
 			break;
 
@@ -884,7 +1013,7 @@ up_dump_attrnlri(u_char *buf, int len, s
 	if (TAILQ_EMPTY(&upa->prefix_h)) {
 		if (RB_REMOVE(uptree_attr, &peer->up_attrs, upa) == NULL)
 			log_warnx("dequeuing update failed.");
-		TAILQ_REMOVE(&peer->updates, upa, attr_l);
+		TAILQ_REMOVE(&peer->updates[AID_INET], upa, attr_l);
 		free(upa->attr);
 		free(upa->mpattr);
 		free(upa);
@@ -895,12 +1024,13 @@ up_dump_attrnlri(u_char *buf, int len, s
 }
 
 u_char *
-up_dump_mp_unreach(u_char *buf, u_int16_t *len, struct rde_peer *peer)
+up_dump_mp_unreach(u_char *buf, u_int16_t *len, struct rde_peer *peer,
+    u_int8_t aid)
 {
 	int		wpos;
 	u_int16_t	datalen, tmp;
 	u_int16_t	attrlen = 2;	/* attribute header (without len) */
-	u_int8_t	flags = ATTR_OPTIONAL;
+	u_int8_t	flags = ATTR_OPTIONAL, safi;
 
 	/*
 	 * reserve space for withdraw len, attr len, the attribute header
@@ -912,7 +1042,7 @@ up_dump_mp_unreach(u_char *buf, u_int16_
 		return (NULL);
 
 	datalen = up_dump_prefix(buf + wpos, *len - wpos,
-	    &peer->withdraws6, peer);
+	    &peer->withdraws[aid], peer);
 	if (datalen == 0)
 		return (NULL);
 
@@ -920,9 +1050,11 @@ up_dump_mp_unreach(u_char *buf, u_int16_
 
 	/* prepend header, need to do it reverse */
 	/* safi & afi */
-	buf[--wpos] = SAFI_UNICAST;
+	if (aid2afi(aid, &tmp, &safi))
+		fatalx("up_dump_mp_unreach: bad AID");
+	buf[--wpos] = safi;
 	wpos -= sizeof(u_int16_t);
-	tmp = htons(AFI_IPv6);
+	tmp = htons(tmp);
 	memcpy(buf + wpos, &tmp, sizeof(u_int16_t));
 
 	/* attribute length */
@@ -959,33 +1091,39 @@ up_dump_mp_unreach(u_char *buf, u_int16_
 	return (buf + wpos);
 }
 
-u_char *
-up_dump_mp_reach(u_char *buf, u_int16_t *len, struct rde_peer *peer)
+int
+up_dump_mp_reach(u_char *buf, u_int16_t *len, struct rde_peer *peer,
+    u_int8_t aid)
 {
 	struct update_attr	*upa;
 	int			wpos;
-	u_int16_t		datalen, tmp;
+	u_int16_t		attr_len, datalen, tmp;
 	u_int8_t		flags = ATTR_OPTIONAL;
 
 	/*
 	 * It is possible that a queued path attribute has no nlri prefix.
 	 * Ignore and remove those path attributes.
 	 */
-	while ((upa = TAILQ_FIRST(&peer->updates6)) != NULL)
+	while ((upa = TAILQ_FIRST(&peer->updates[aid])) != NULL)
 		if (TAILQ_EMPTY(&upa->prefix_h)) {
+			attr_len = upa->attr_len;
 			if (RB_REMOVE(uptree_attr, &peer->up_attrs,
 			    upa) == NULL)
 				log_warnx("dequeuing update failed.");
-			TAILQ_REMOVE(&peer->updates6, upa, attr_l);
+			TAILQ_REMOVE(&peer->updates[aid], upa, attr_l);
 			free(upa->attr);
 			free(upa->mpattr);
 			free(upa);
 			peer->up_acnt--;
+			/* XXX horrible hack,
+			 * if attr_len is 0, it is a EoR marker */
+			if (attr_len == 0)
+				return (-1);
 		} else
 			break;
 
 	if (upa == NULL)
-		return (NULL);
+		return (-2);
 
 	/*
 	 * reserve space for attr len, the attributes, the
@@ -993,12 +1131,12 @@ up_dump_mp_reach(u_char *buf, u_int16_t 
 	 */
 	wpos = 2 + 2 + upa->attr_len + 4 + upa->mpattr_len;
 	if (*len < wpos)
-		return (NULL);
+		return (-2);
 
 	datalen = up_dump_prefix(buf + wpos, *len - wpos,
 	    &upa->prefix_h, peer);
 	if (datalen == 0)
-		return (NULL);
+		return (-2);
 
 	if (upa->mpattr_len == 0 || upa->mpattr == NULL)
 		fatalx("mulitprotocol update without MP attrs");
@@ -1038,7 +1176,7 @@ up_dump_mp_reach(u_char *buf, u_int16_t 
 	if (TAILQ_EMPTY(&upa->prefix_h)) {
 		if (RB_REMOVE(uptree_attr, &peer->up_attrs, upa) == NULL)
 			log_warnx("dequeuing update failed.");
-		TAILQ_REMOVE(&peer->updates6, upa, attr_l);
+		TAILQ_REMOVE(&peer->updates[aid], upa, attr_l);
 		free(upa->attr);
 		free(upa->mpattr);
 		free(upa);
@@ -1046,6 +1184,5 @@ up_dump_mp_reach(u_char *buf, u_int16_t 
 	}
 
 	*len = datalen + 4;
-	return (buf + wpos);
+	return (wpos);
 }
-
