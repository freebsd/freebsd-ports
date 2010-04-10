Index: bgpd/rde_rib.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/rde_rib.c,v
retrieving revision 1.1.1.7
retrieving revision 1.6
diff -u -p -r1.1.1.7 -r1.6
--- bgpd/rde_rib.c	14 Feb 2010 20:19:57 -0000	1.1.1.7
+++ bgpd/rde_rib.c	10 Apr 2010 12:16:23 -0000	1.6
@@ -1,4 +1,4 @@
-/*	$OpenBSD: rde_rib.c,v 1.116 2009/06/29 14:13:48 claudio Exp $ */
+/*	$OpenBSD: rde_rib.c,v 1.125 2010/04/07 09:44:11 claudio Exp $ */
 
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
+rib_new(char *name, u_int16_t flags)
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
@@ -78,7 +81,7 @@ rib_new(int id, char *name, u_int16_t fl
 	bzero(&ribs[id], sizeof(struct rib));
 	strlcpy(ribs[id].name, name, sizeof(ribs[id].name));
 	RB_INIT(&ribs[id].rib);
-	ribs[id].state = RIB_ACTIVE;
+	ribs[id].state = RECONF_REINIT;
 	ribs[id].id = id;
 	ribs[id].flags = flags;
 
@@ -173,15 +176,16 @@ rib_lookup(struct rib *rib, struct bgpd_
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
@@ -254,7 +258,7 @@ rib_empty(struct rib_entry *re)
 
 void
 rib_dump(struct rib *rib, void (*upcall)(struct rib_entry *, void *),
-    void *arg, sa_family_t af)
+    void *arg, u_int8_t aid)
 {
 	struct rib_context	*ctx;
 
@@ -263,7 +267,7 @@ rib_dump(struct rib *rib, void (*upcall)
 	ctx->ctx_rib = rib;
 	ctx->ctx_upcall = upcall;
 	ctx->ctx_arg = arg;
-	ctx->ctx_af = af;
+	ctx->ctx_aid = aid;
 	rib_dump_r(ctx);
 }
 
@@ -280,7 +284,8 @@ rib_dump_r(struct rib_context *ctx)
 		re = rib_restart(ctx);
 
 	for (i = 0; re != NULL; re = RB_NEXT(rib_tree, unused, re)) {
-		if (ctx->ctx_af != AF_UNSPEC && ctx->ctx_af != re->prefix->af)
+		if (ctx->ctx_aid != AID_UNSPEC &&
+		    ctx->ctx_aid != re->prefix->aid)
 			continue;
 		if (ctx->ctx_count && i++ >= ctx->ctx_count &&
 		    (re->flags & F_RIB_ENTRYLOCK) == 0) {
@@ -308,7 +313,7 @@ rib_restart(struct rib_context *ctx)
 	re->flags &= ~F_RIB_ENTRYLOCK;
 
 	/* find first non empty element */
-	while (rib_empty(re))
+	while (re && rib_empty(re))
 		re = RB_NEXT(rib_tree, unused, re);
 
 	/* free the previously locked rib element if empty */
@@ -632,11 +637,11 @@ prefix_compare(const struct bgpd_addr *a
 	int		i;
 	u_int8_t	m;
 
-	if (a->af != b->af)
-		return (a->af - b->af);
+	if (a->aid != b->aid)
+		return (a->aid - b->aid);
 
-	switch (a->af) {
-	case AF_INET:
+	switch (a->aid) {
+	case AID_INET:
 		if (prefixlen > 32)
 			fatalx("prefix_cmp: bad IPv4 prefixlen");
 		mask = htonl(prefixlen2mask(prefixlen));
@@ -645,7 +650,7 @@ prefix_compare(const struct bgpd_addr *a
 		if (aa != ba)
 			return (aa - ba);
 		return (0);
-	case AF_INET6:
+	case AID_INET6:
 		if (prefixlen > 128)
 			fatalx("prefix_cmp: bad IPv6 prefixlen");
 		for (i = 0; i < prefixlen / 8; i++)
@@ -660,6 +665,24 @@ prefix_compare(const struct bgpd_addr *a
 				    (b->v6.s6_addr[prefixlen / 8] & m));
 		}
 		return (0);
+	case AID_VPN_IPv4:
+		if (prefixlen > 32)
+			fatalx("prefix_cmp: bad IPv4 VPN prefixlen");
+		if (betoh64(a->vpn4.rd) > betoh64(b->vpn4.rd))
+			return (1);
+		if (betoh64(a->vpn4.rd) < betoh64(b->vpn4.rd))
+			return (-1);
+		mask = htonl(prefixlen2mask(prefixlen));
+		aa = ntohl(a->vpn4.addr.s_addr & mask);
+		ba = ntohl(b->vpn4.addr.s_addr & mask);
+		if (aa != ba)
+			return (aa - ba);
+		if (a->vpn4.labellen > b->vpn4.labellen)
+			return (1);
+		if (a->vpn4.labellen < b->vpn4.labellen)
+			return (-1);
+		return (memcmp(a->vpn4.labelstack, b->vpn4.labelstack,
+		    a->vpn4.labellen));
 	default:
 		fatalx("prefix_cmp: unknown af");
 	}
@@ -806,16 +829,33 @@ prefix_write(u_char *buf, int len, struc
 {
 	int	totlen;
 
-	if (prefix->af != AF_INET && prefix->af != AF_INET6)
-		return (-1);
+	switch (prefix->aid) {
+	case AID_INET:
+	case AID_INET6:
+		totlen = PREFIX_SIZE(plen);
 
-	totlen = PREFIX_SIZE(plen);
+		if (totlen > len)
+			return (-1);
+		*buf++ = plen;
+		memcpy(buf, &prefix->ba, totlen - 1);
+		return (totlen);
+	case AID_VPN_IPv4:
+		totlen = PREFIX_SIZE(plen) + sizeof(prefix->vpn4.rd) +
+		    prefix->vpn4.labellen;
+		plen += (sizeof(prefix->vpn4.rd) + prefix->vpn4.labellen) * 8;
 
-	if (totlen > len)
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
-	*buf++ = plen;
-	memcpy(buf, &prefix->ba, totlen - 1);
-	return (totlen);
+	}
 }
 
 /*
@@ -1070,10 +1110,6 @@ nexthop_update(struct kroute_nexthop *ms
 		return;
 	}
 
-	if (nexthop_delete(nh))
-		/* nexthop no longer used */
-		return;
-
 	oldstate = nh->state;
 	if (msg->valid)
 		nh->state = NEXTHOP_REACH;
@@ -1088,21 +1124,13 @@ nexthop_update(struct kroute_nexthop *ms
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
@@ -1118,7 +1146,7 @@ nexthop_update(struct kroute_nexthop *ms
 
 void
 nexthop_modify(struct rde_aspath *asp, struct bgpd_addr *nexthop,
-    enum action_types type, sa_family_t af)
+    enum action_types type, u_int8_t aid)
 {
 	struct nexthop	*nh;
 
@@ -1138,7 +1166,7 @@ nexthop_modify(struct rde_aspath *asp, s
 		asp->flags |= F_NEXTHOP_SELF;
 		return;
 	}
-	if (af != nexthop->af)
+	if (aid != nexthop->aid)
 		return;
 
 	nh = nexthop_get(nexthop);
@@ -1233,17 +1261,17 @@ nexthop_compare(struct nexthop *na, stru
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
@@ -1269,14 +1297,14 @@ nexthop_hash(struct bgpd_addr *nexthop)
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
