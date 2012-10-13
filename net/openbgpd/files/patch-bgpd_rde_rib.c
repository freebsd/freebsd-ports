Index: bgpd/rde_rib.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/rde_rib.c,v
retrieving revision 1.1.1.7
retrieving revision 1.8
diff -u -p -r1.1.1.7 -r1.8
--- bgpd/rde_rib.c	14 Feb 2010 20:19:57 -0000	1.1.1.7
+++ bgpd/rde_rib.c	13 Oct 2012 18:36:00 -0000	1.8
@@ -1,4 +1,4 @@
-/*	$OpenBSD: rde_rib.c,v 1.116 2009/06/29 14:13:48 claudio Exp $ */
+/*	$OpenBSD: rde_rib.c,v 1.133 2012/07/01 11:55:13 sthen Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Claudio Jeker <claudio@openbsd.org>
@@ -18,7 +18,11 @@
 
 #include <sys/types.h>
 #include <sys/queue.h>
+#if defined(__FreeBSD__)	/* sys/hash.h */
+#include "hash.h"
+#else
 #include <sys/hash.h>
+#endif /* defined(__FreeBSD__) */
 
 #include <stdlib.h>
 #include <string.h>
@@ -50,16 +54,15 @@ RB_GENERATE(rib_tree, rib_entry, rib_e, 
 
 /* RIB specific functions */
 u_int16_t
-rib_new(int id, char *name, u_int16_t flags)
+rib_new(char *name, u_int rtableid, u_int16_t flags)
 {
 	struct rib	*xribs;
 	size_t		newsize;
+	u_int16_t	id;
 
-	if (id < 0) {
-		for (id = 0; id < rib_size; id++) {
-			if (*ribs[id].name == '\0')
-				break;
-		}
+	for (id = 0; id < rib_size; id++) {
+		if (*ribs[id].name == '\0')
+			break;
 	}
 
 	if (id == RIB_FAILED)
@@ -78,9 +81,10 @@ rib_new(int id, char *name, u_int16_t fl
 	bzero(&ribs[id], sizeof(struct rib));
 	strlcpy(ribs[id].name, name, sizeof(ribs[id].name));
 	RB_INIT(&ribs[id].rib);
-	ribs[id].state = RIB_ACTIVE;
+	ribs[id].state = RECONF_REINIT;
 	ribs[id].id = id;
 	ribs[id].flags = flags;
+	ribs[id].rtableid = rtableid;
 
 	return (id);
 }
@@ -173,15 +177,16 @@ rib_lookup(struct rib *rib, struct bgpd_
 	struct rib_entry *re;
 	int		 i;
 
-	switch (addr->af) {
-	case AF_INET:
+	switch (addr->aid) {
+	case AID_INET:
+	case AID_VPN_IPv4:
 		for (i = 32; i >= 0; i--) {
 			re = rib_get(rib, addr, i);
 			if (re != NULL)
 				return (re);
 		}
 		break;
-	case AF_INET6:
+	case AID_INET6:
 		for (i = 128; i >= 0; i--) {
 			re = rib_get(rib, addr, i);
 			if (re != NULL)
@@ -215,6 +220,7 @@ rib_add(struct rib *rib, struct bgpd_add
 
         if (RB_INSERT(rib_tree, &rib->rib, re) != NULL) {
 		log_warnx("rib_add: insert failed");
+		free(re);
 		return (NULL);
 	}
 
@@ -254,7 +260,7 @@ rib_empty(struct rib_entry *re)
 
 void
 rib_dump(struct rib *rib, void (*upcall)(struct rib_entry *, void *),
-    void *arg, sa_family_t af)
+    void *arg, u_int8_t aid)
 {
 	struct rib_context	*ctx;
 
@@ -263,7 +269,7 @@ rib_dump(struct rib *rib, void (*upcall)
 	ctx->ctx_rib = rib;
 	ctx->ctx_upcall = upcall;
 	ctx->ctx_arg = arg;
-	ctx->ctx_af = af;
+	ctx->ctx_aid = aid;
 	rib_dump_r(ctx);
 }
 
@@ -280,7 +286,8 @@ rib_dump_r(struct rib_context *ctx)
 		re = rib_restart(ctx);
 
 	for (i = 0; re != NULL; re = RB_NEXT(rib_tree, unused, re)) {
-		if (ctx->ctx_af != AF_UNSPEC && ctx->ctx_af != re->prefix->af)
+		if (ctx->ctx_aid != AID_UNSPEC &&
+		    ctx->ctx_aid != re->prefix->aid)
 			continue;
 		if (ctx->ctx_count && i++ >= ctx->ctx_count &&
 		    (re->flags & F_RIB_ENTRYLOCK) == 0) {
@@ -308,7 +315,7 @@ rib_restart(struct rib_context *ctx)
 	re->flags &= ~F_RIB_ENTRYLOCK;
 
 	/* find first non empty element */
-	while (rib_empty(re))
+	while (re && rib_empty(re))
 		re = RB_NEXT(rib_tree, unused, re);
 
 	/* free the previously locked rib element if empty */
@@ -502,6 +509,36 @@ path_remove(struct rde_aspath *asp)
 	}
 }
 
+/* remove all stale routes or if staletime is 0 remove all routes for
+   a specified AID. */
+void
+path_remove_stale(struct rde_aspath *asp, u_int8_t aid)
+{
+	struct prefix	*p, *np;
+	time_t		 staletime;
+
+	staletime = asp->peer->staletime[aid];
+	for (p = LIST_FIRST(&asp->prefix_h); p != NULL; p = np) {
+		np = LIST_NEXT(p, path_l);
+		if (p->prefix->aid != aid)
+			continue;
+
+		if (staletime && p->lastchange > staletime)
+			continue;
+
+		if (asp->pftableid) {
+			struct bgpd_addr addr;
+
+			pt_getaddr(p->prefix, &addr);
+			/* Commit is done in peer_flush() */
+			rde_send_pftable(p->aspath->pftableid, &addr,
+			    p->prefix->prefixlen, 1);
+		}
+		prefix_destroy(p);
+	}
+}
+
+
 /* this function is only called by prefix_remove and path_remove */
 void
 path_destroy(struct rde_aspath *asp)
@@ -624,48 +661,6 @@ static void		 prefix_link(struct prefix 
 			     struct rde_aspath *);
 static void		 prefix_unlink(struct prefix *);
 
-int
-prefix_compare(const struct bgpd_addr *a, const struct bgpd_addr *b,
-    int prefixlen)
-{
-	in_addr_t	mask, aa, ba;
-	int		i;
-	u_int8_t	m;
-
-	if (a->af != b->af)
-		return (a->af - b->af);
-
-	switch (a->af) {
-	case AF_INET:
-		if (prefixlen > 32)
-			fatalx("prefix_cmp: bad IPv4 prefixlen");
-		mask = htonl(prefixlen2mask(prefixlen));
-		aa = ntohl(a->v4.s_addr & mask);
-		ba = ntohl(b->v4.s_addr & mask);
-		if (aa != ba)
-			return (aa - ba);
-		return (0);
-	case AF_INET6:
-		if (prefixlen > 128)
-			fatalx("prefix_cmp: bad IPv6 prefixlen");
-		for (i = 0; i < prefixlen / 8; i++)
-			if (a->v6.s6_addr[i] != b->v6.s6_addr[i])
-				return (a->v6.s6_addr[i] - b->v6.s6_addr[i]);
-		i = prefixlen % 8;
-		if (i) {
-			m = 0xff00 >> i;
-			if ((a->v6.s6_addr[prefixlen / 8] & m) !=
-			    (b->v6.s6_addr[prefixlen / 8] & m))
-				return ((a->v6.s6_addr[prefixlen / 8] & m) -
-				    (b->v6.s6_addr[prefixlen / 8] & m));
-		}
-		return (0);
-	default:
-		fatalx("prefix_cmp: unknown af");
-	}
-	return (-1);
-}
-
 /*
  * search for specified prefix of a peer. Returns NULL if not found.
  */
@@ -806,16 +801,58 @@ prefix_write(u_char *buf, int len, struc
 {
 	int	totlen;
 
-	if (prefix->af != AF_INET && prefix->af != AF_INET6)
+	switch (prefix->aid) {
+	case AID_INET:
+	case AID_INET6:
+		totlen = PREFIX_SIZE(plen);
+
+		if (totlen > len)
+			return (-1);
+		*buf++ = plen;
+		memcpy(buf, &prefix->ba, totlen - 1);
+		return (totlen);
+	case AID_VPN_IPv4:
+		totlen = PREFIX_SIZE(plen) + sizeof(prefix->vpn4.rd) +
+		    prefix->vpn4.labellen;
+		plen += (sizeof(prefix->vpn4.rd) + prefix->vpn4.labellen) * 8;
+
+		if (totlen > len)
+			return (-1);
+		*buf++ = plen;
+		memcpy(buf, &prefix->vpn4.labelstack, prefix->vpn4.labellen);
+		buf += prefix->vpn4.labellen;
+		memcpy(buf, &prefix->vpn4.rd, sizeof(prefix->vpn4.rd));
+		buf += sizeof(prefix->vpn4.rd);
+		memcpy(buf, &prefix->vpn4.addr, PREFIX_SIZE(plen) - 1);
+		return (totlen);
+	default:
 		return (-1);
+	}
+}
 
-	totlen = PREFIX_SIZE(plen);
+int
+prefix_writebuf(struct ibuf *buf, struct bgpd_addr *prefix, u_int8_t plen)
+{
+	int	 totlen;
+	void	*bptr;
 
-	if (totlen > len)
+	switch (prefix->aid) {
+	case AID_INET:
+	case AID_INET6:
+		totlen = PREFIX_SIZE(plen);
+		break;
+	case AID_VPN_IPv4:
+		totlen = PREFIX_SIZE(plen) + sizeof(prefix->vpn4.rd) +
+		    prefix->vpn4.labellen;
+	default:
 		return (-1);
-	*buf++ = plen;
-	memcpy(buf, &prefix->ba, totlen - 1);
-	return (totlen);
+	}
+
+	if ((bptr = ibuf_reserve(buf, totlen)) == NULL)
+		return (-1);
+	if (prefix_write(bptr, totlen, prefix, plen) == -1)
+		return (-1);
+	return (0);
 }
 
 /*
@@ -861,7 +898,7 @@ prefix_updateall(struct rde_aspath *asp,
 			 */
 			if ((p->rib->flags & F_RIB_NOFIB) == 0 &&
 			    p == p->rib->active)
-				rde_send_kroute(p, NULL);
+				rde_send_kroute(p, NULL, p->rib->ribid);
 			continue;
 		}
 
@@ -871,7 +908,7 @@ prefix_updateall(struct rde_aspath *asp,
 		 * If the prefix is the active one remove it first,
 		 * this has to be done because we can not detect when
 		 * the active prefix changes its state. In this case
-		 * we know that this is a withdrawl and so the second
+		 * we know that this is a withdrawal and so the second
 		 * prefix_evaluate() will generate no update because
 		 * the nexthop is unreachable or ineligible.
 		 */
@@ -885,16 +922,12 @@ prefix_updateall(struct rde_aspath *asp,
 void
 prefix_destroy(struct prefix *p)
 {
-	struct rib_entry	*re;
 	struct rde_aspath	*asp;
 
-	re = p->rib;
 	asp = p->aspath;
 	prefix_unlink(p);
 	prefix_free(p);
 
-	if (rib_empty(re))
-		rib_remove(re);
 	if (path_empty(asp))
 		path_destroy(asp);
 }
@@ -907,21 +940,16 @@ prefix_network_clean(struct rde_peer *pe
 {
 	struct rde_aspath	*asp, *xasp;
 	struct prefix		*p, *xp;
-	struct pt_entry		*pte;
 
 	for (asp = LIST_FIRST(&peer->path_h); asp != NULL; asp = xasp) {
 		xasp = LIST_NEXT(asp, peer_l);
-		if ((asp->flags & F_ANN_DYNAMIC) == flags)
+		if ((asp->flags & F_ANN_DYNAMIC) != flags)
 			continue;
 		for (p = LIST_FIRST(&asp->prefix_h); p != NULL; p = xp) {
 			xp = LIST_NEXT(p, path_l);
 			if (reloadtime > p->lastchange) {
-				pte = p->prefix;
 				prefix_unlink(p);
 				prefix_free(p);
-
-				if (pt_empty(pte))
-					pt_remove(pte);
 			}
 		}
 		if (path_empty(asp))
@@ -954,11 +982,11 @@ prefix_link(struct prefix *pref, struct 
 static void
 prefix_unlink(struct prefix *pref)
 {
-	if (pref->rib) {
-		/* make route decision */
-		LIST_REMOVE(pref, rib_l);
-		prefix_evaluate(NULL, pref->rib);
-	}
+	struct rib_entry	*re = pref->rib;
+
+	/* make route decision */
+	LIST_REMOVE(pref, rib_l);
+	prefix_evaluate(NULL, re);
 
 	LIST_REMOVE(pref, path_l);
 	PREFIX_COUNT(pref->aspath, -1);
@@ -966,6 +994,8 @@ prefix_unlink(struct prefix *pref)
 	pt_unref(pref->prefix);
 	if (pt_empty(pref->prefix))
 		pt_remove(pref->prefix);
+	if (rib_empty(re))
+		rib_remove(re);
 
 	/* destroy all references to other objects */
 	pref->aspath = NULL;
@@ -973,8 +1003,8 @@ prefix_unlink(struct prefix *pref)
 	pref->rib = NULL;
 
 	/*
-	 * It's the caller's duty to remove empty aspath respectively pt_entry
-	 * structures. Also freeing the unlinked prefix is the caller's duty.
+	 * It's the caller's duty to remove empty aspath structures.
+	 * Also freeing the unlinked prefix is the caller's duty.
 	 */
 }
 
@@ -1070,10 +1100,6 @@ nexthop_update(struct kroute_nexthop *ms
 		return;
 	}
 
-	if (nexthop_delete(nh))
-		/* nexthop no longer used */
-		return;
-
 	oldstate = nh->state;
 	if (msg->valid)
 		nh->state = NEXTHOP_REACH;
@@ -1088,21 +1114,13 @@ nexthop_update(struct kroute_nexthop *ms
 		memcpy(&nh->true_nexthop, &msg->gateway,
 		    sizeof(nh->true_nexthop));
 
-	switch (msg->nexthop.af) {
-	case AF_INET:
-		nh->nexthop_netlen = msg->kr.kr4.prefixlen;
-		nh->nexthop_net.af = AF_INET;
-		nh->nexthop_net.v4.s_addr = msg->kr.kr4.prefix.s_addr;
-		break;
-	case AF_INET6:
-		nh->nexthop_netlen = msg->kr.kr6.prefixlen;
-		nh->nexthop_net.af = AF_INET6;
-		memcpy(&nh->nexthop_net.v6, &msg->kr.kr6.prefix,
-		    sizeof(struct in6_addr));
-		break;
-	default:
-		fatalx("nexthop_update: unknown af");
-	}
+	memcpy(&nh->nexthop_net, &msg->net,
+	    sizeof(nh->nexthop_net));
+	nh->nexthop_netlen = msg->netlen;
+
+	if (nexthop_delete(nh))
+		/* nexthop no longer used */
+		return;
 
 	if (rde_noevaluate())
 		/*
@@ -1118,35 +1136,38 @@ nexthop_update(struct kroute_nexthop *ms
 
 void
 nexthop_modify(struct rde_aspath *asp, struct bgpd_addr *nexthop,
-    enum action_types type, sa_family_t af)
+    enum action_types type, u_int8_t aid)
 {
 	struct nexthop	*nh;
 
-	if (type == ACTION_SET_NEXTHOP_REJECT) {
-		asp->flags |= F_NEXTHOP_REJECT;
+	if (type == ACTION_SET_NEXTHOP && aid != nexthop->aid)
 		return;
-	}
-	if (type  == ACTION_SET_NEXTHOP_BLACKHOLE) {
+
+	asp->flags &= ~F_NEXTHOP_MASK;
+	switch (type) {
+	case ACTION_SET_NEXTHOP_REJECT:
+		asp->flags |= F_NEXTHOP_REJECT;
+		break;
+	case ACTION_SET_NEXTHOP_BLACKHOLE:
 		asp->flags |= F_NEXTHOP_BLACKHOLE;
-		return;
-	}
-	if (type == ACTION_SET_NEXTHOP_NOMODIFY) {
+		break;
+	case ACTION_SET_NEXTHOP_NOMODIFY:
 		asp->flags |= F_NEXTHOP_NOMODIFY;
-		return;
-	}
-	if (type == ACTION_SET_NEXTHOP_SELF) {
+		break;
+	case ACTION_SET_NEXTHOP_SELF:
 		asp->flags |= F_NEXTHOP_SELF;
-		return;
+		break;
+	case ACTION_SET_NEXTHOP:
+		nh = nexthop_get(nexthop);
+		if (asp->flags & F_ATTR_LINKED)
+			nexthop_unlink(asp);
+		asp->nexthop = nh;
+		if (asp->flags & F_ATTR_LINKED)
+			nexthop_link(asp);
+		break;
+	default:
+		break;
 	}
-	if (af != nexthop->af)
-		return;
-
-	nh = nexthop_get(nexthop);
-	if (asp->flags & F_ATTR_LINKED)
-		nexthop_unlink(asp);
-	asp->nexthop = nh;
-	if (asp->flags & F_ATTR_LINKED)
-		nexthop_link(asp);
 }
 
 void
@@ -1233,17 +1254,17 @@ nexthop_compare(struct nexthop *na, stru
 	a = &na->exit_nexthop;
 	b = &nb->exit_nexthop;
 
-	if (a->af != b->af)
-		return (a->af - b->af);
+	if (a->aid != b->aid)
+		return (a->aid - b->aid);
 
-	switch (a->af) {
-	case AF_INET:
+	switch (a->aid) {
+	case AID_INET:
 		if (ntohl(a->v4.s_addr) > ntohl(b->v4.s_addr))
 			return (1);
 		if (ntohl(a->v4.s_addr) < ntohl(b->v4.s_addr))
 			return (-1);
 		return (0);
-	case AF_INET6:
+	case AID_INET6:
 		return (memcmp(&a->v6, &b->v6, sizeof(struct in6_addr)));
 	default:
 		fatalx("nexthop_cmp: unknown af");
@@ -1269,14 +1290,14 @@ nexthop_hash(struct bgpd_addr *nexthop)
 {
 	u_int32_t	 h = 0;
 
-	switch (nexthop->af) {
-	case AF_INET:
+	switch (nexthop->aid) {
+	case AID_INET:
 		h = (AF_INET ^ ntohl(nexthop->v4.s_addr) ^
 		    ntohl(nexthop->v4.s_addr) >> 13) &
 		    nexthoptable.nexthop_hashmask;
 		break;
-	case AF_INET6:
-		h = hash32_buf(nexthop->v6.s6_addr, sizeof(struct in6_addr),
+	case AID_INET6:
+		h = hash32_buf(&nexthop->v6, sizeof(struct in6_addr),
 		    HASHINIT) & nexthoptable.nexthop_hashmask;
 		break;
 	default:
