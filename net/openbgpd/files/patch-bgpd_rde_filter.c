Index: bgpd/rde_filter.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/rde_filter.c,v
retrieving revision 1.1.1.7
retrieving revision 1.9
diff -u -p -r1.1.1.7 -r1.9
--- bgpd/rde_filter.c	14 Feb 2010 20:19:57 -0000	1.1.1.7
+++ bgpd/rde_filter.c	8 Dec 2012 20:17:59 -0000	1.9
@@ -1,4 +1,4 @@
-/*	$OpenBSD: rde_filter.c,v 1.56 2009/06/06 01:10:29 claudio Exp $ */
+/*	$OpenBSD: rde_filter.c,v 1.67 2011/09/20 21:19:06 claudio Exp $ */
 
 /*
  * Copyright (c) 2004 Claudio Jeker <claudio@openbsd.org>
@@ -26,7 +26,7 @@
 #include "rde.h"
 
 int	rde_filter_match(struct filter_rule *, struct rde_aspath *,
-	    struct bgpd_addr *, u_int8_t, struct rde_peer *);
+	    struct bgpd_addr *, u_int8_t, struct rde_peer *, struct rde_peer *);
 int	filterset_equal(struct filter_set_head *, struct filter_set_head *);
 
 enum filter_actions
@@ -40,6 +40,13 @@ rde_filter(u_int16_t ribid, struct rde_a
 	if (new != NULL)
 		*new = NULL;
 
+	if (asp->flags & F_ATTR_PARSE_ERR)
+		/*
+	 	 * don't try to filter bad updates just deny them
+		 * so they act as implicit withdraws
+		 */
+		return (ACTION_DENY);
+
 	TAILQ_FOREACH(f, rules, entry) {
 		if (dir != f->dir)
 			continue;
@@ -51,7 +58,7 @@ rde_filter(u_int16_t ribid, struct rde_a
 		if (f->peer.peerid != 0 &&
 		    f->peer.peerid != peer->conf.id)
 			continue;
-		if (rde_filter_match(f, asp, prefix, prefixlen, peer)) {
+		if (rde_filter_match(f, asp, prefix, prefixlen, peer, from)) {
 			if (asp != NULL && new != NULL) {
 				/* asp may get modified so create a copy */
 				if (*new == NULL) {
@@ -59,7 +66,7 @@ rde_filter(u_int16_t ribid, struct rde_a
 					/* ... and use the copy from now on */
 					asp = *new;
 				}
-				rde_apply_set(asp, &f->set, prefix->af,
+				rde_apply_set(asp, &f->set, prefix->aid,
 				    from, peer);
 			}
 			if (f->action != ACTION_NONE)
@@ -73,7 +80,7 @@ rde_filter(u_int16_t ribid, struct rde_a
 
 void
 rde_apply_set(struct rde_aspath *asp, struct filter_set_head *sh,
-    sa_family_t af, struct rde_peer *from, struct rde_peer *peer)
+    u_int8_t aid, struct rde_peer *from, struct rde_peer *peer)
 {
 	struct filter_set	*set;
 	u_char			*np;
@@ -167,7 +174,7 @@ rde_apply_set(struct rde_aspath *asp, st
 		case ACTION_SET_NEXTHOP_NOMODIFY:
 		case ACTION_SET_NEXTHOP_SELF:
 			nexthop_modify(asp, &set->action.nexthop, set->type,
-			    af);
+			    aid);
 			break;
 		case ACTION_SET_COMMUNITY:
 			switch (set->action.community.as) {
@@ -243,19 +250,42 @@ rde_apply_set(struct rde_aspath *asp, st
 			asp->rtlabelid = set->action.id;
 			rtlabel_ref(asp->rtlabelid);
 			break;
+		case ACTION_SET_ORIGIN:
+			asp->origin = set->action.origin;
+			break;
+		case ACTION_SET_EXT_COMMUNITY:
+			community_ext_set(asp, &set->action.ext_community,
+			    peer->conf.remote_as);
+			break;
+		case ACTION_DEL_EXT_COMMUNITY:
+			community_ext_delete(asp, &set->action.ext_community,
+			    peer->conf.remote_as);
+			break;
 		}
 	}
 }
 
 int
 rde_filter_match(struct filter_rule *f, struct rde_aspath *asp,
-    struct bgpd_addr *prefix, u_int8_t plen, struct rde_peer *peer)
+    struct bgpd_addr *prefix, u_int8_t plen, struct rde_peer *peer,
+    struct rde_peer *from)
 {
-	int	as, type;
+	u_int32_t	pas;
+	int		cas, type;
 
-	if (asp != NULL && f->match.as.type != AS_NONE)
-		if (aspath_match(asp->aspath, f->match.as.type,
-		    f->match.as.as) == 0)
+	if (asp != NULL && f->match.as.type != AS_NONE) {
+		if (f->match.as.flags & AS_FLAG_NEIGHBORAS)
+			pas = peer->conf.remote_as;
+		else
+			pas = f->match.as.as;
+		if (aspath_match(asp->aspath->data, asp->aspath->len,
+		    f->match.as.type, pas) == 0)
+			return (0);
+	}
+
+	if (asp != NULL && f->match.aslen.type != ASLEN_NONE)
+		if (aspath_lenmatch(asp->aspath, f->match.aslen.type,
+		    f->match.aslen.aslen) == 0)
 			return (0);
 
 	if (asp != NULL && f->match.community.as != COMMUNITY_UNSET) {
@@ -263,10 +293,10 @@ rde_filter_match(struct filter_rule *f, 
 		case COMMUNITY_ERROR:
 			fatalx("rde_apply_set bad community string");
 		case COMMUNITY_NEIGHBOR_AS:
-			as = peer->conf.remote_as;
+			cas = peer->conf.remote_as;
 			break;
 		default:
-			as = f->match.community.as;
+			cas = f->match.community.as;
 			break;
 		}
 
@@ -281,12 +311,17 @@ rde_filter_match(struct filter_rule *f, 
 			break;
 		}
 
-		if (rde_filter_community(asp, as, type) == 0)
+		if (community_match(asp, cas, type) == 0)
 			return (0);
 	}
+	if (asp != NULL &&
+	    (f->match.ext_community.flags & EXT_COMMUNITY_FLAG_VALID))
+		if (community_ext_match(asp, &f->match.ext_community,
+		    peer->conf.remote_as) == 0)
+			return (0);
 
-	if (f->match.prefix.addr.af != 0) {
-		if (f->match.prefix.addr.af != prefix->af)
+	if (f->match.prefix.addr.aid != 0) {
+		if (f->match.prefix.addr.aid != prefix->aid)
 			/* don't use IPv4 rules for IPv6 and vice versa */
 			return (0);
 
@@ -322,7 +357,7 @@ rde_filter_match(struct filter_rule *f, 
 	} else if (f->match.prefixlen.op != OP_NONE) {
 		/* only prefixlen without a prefix */
 
-		if (f->match.prefixlen.af != prefix->af)
+		if (f->match.prefixlen.aid != prefix->aid)
 			/* don't use IPv4 rules for IPv6 and vice versa */
 			return (0);
 
@@ -350,25 +385,40 @@ rde_filter_match(struct filter_rule *f, 
 		}
 		/* NOTREACHED */
 	}
+	if (f->match.nexthop.flags != 0) {
+		struct bgpd_addr *nexthop, *cmpaddr;
+		if (asp->nexthop == NULL)
+			/* no nexthop, skip */
+			return (0);
+		nexthop = &asp->nexthop->exit_nexthop;
+		if (f->match.nexthop.flags == FILTER_NEXTHOP_ADDR)
+			cmpaddr = &f->match.nexthop.addr;
+		else
+			cmpaddr = &from->remote_addr;
+		if (cmpaddr->aid != nexthop->aid)
+			/* don't use IPv4 rules for IPv6 and vice versa */
+			return (0);
+
+		switch (cmpaddr->aid) {
+		case AID_INET:
+			if (cmpaddr->v4.s_addr != nexthop->v4.s_addr)
+				return (0);
+			break;
+		case AID_INET6:
+			if (memcmp(&cmpaddr->v6, &nexthop->v6,
+			    sizeof(struct in6_addr)))
+				return (0);
+			break;
+		default:
+			fatalx("King Bula lost in address space");
+		}
+	}
 
 	/* matched somewhen or is anymatch rule  */
 	return (1);
 }
 
 int
-rde_filter_community(struct rde_aspath *asp, int as, int type)
-{
-	struct attr	*a;
-
-	a = attr_optget(asp, ATTR_COMMUNITIES);
-	if (a == NULL)
-		/* no communities, no match */
-		return (0);
-
-	return (community_match(a->data, a->len, as, type));
-}
-
-int
 rde_filter_equal(struct filter_head *a, struct filter_head *b,
     struct rde_peer *peer, enum directions dir)
 {
@@ -476,6 +526,12 @@ filterset_cmp(struct filter_set *a, stru
 		return (a->action.community.type - b->action.community.type);
 	}
 
+	if (a->type == ACTION_SET_EXT_COMMUNITY ||
+	    a->type == ACTION_DEL_EXT_COMMUNITY) {	/* a->type == b->type */
+		return (memcmp(&a->action.ext_community,
+		    &b->action.ext_community, sizeof(a->action.ext_community)));
+	}
+
 	if (a->type == ACTION_SET_NEXTHOP && b->type == ACTION_SET_NEXTHOP) {
 		/*
 		 * This is the only interesting case, all others are considered
@@ -483,13 +539,29 @@ filterset_cmp(struct filter_set *a, stru
 		 * reject it at the same time. Allow one IPv4 and one IPv6
 		 * per filter set or only one of the other nexthop modifiers.
 		 */
-		return (a->action.nexthop.af - b->action.nexthop.af);
+		return (a->action.nexthop.aid - b->action.nexthop.aid);
 	}
 
 	/* equal */
 	return (0);
 }
 
+void
+filterset_move(struct filter_set_head *source, struct filter_set_head *dest)
+{
+	struct filter_set	*s;
+
+	TAILQ_INIT(dest);
+
+	if (source == NULL)
+		return;
+
+	while ((s = TAILQ_FIRST(source)) != NULL) {
+		TAILQ_REMOVE(source, s, entry);
+		TAILQ_INSERT_TAIL(dest, s, entry);
+	}
+}
+
 int
 filterset_equal(struct filter_set_head *ah, struct filter_set_head *bh)
 {
@@ -574,6 +646,19 @@ filterset_equal(struct filter_set_head *
 			if (strcmp(as, bs) == 0)
 				continue;
 			break;
+		case ACTION_SET_ORIGIN:
+			if (a->type == b->type &&
+			    a->action.origin == b->action.origin)
+				continue;
+			break;
+		case ACTION_SET_EXT_COMMUNITY:
+		case ACTION_DEL_EXT_COMMUNITY:
+			if (a->type == b->type && memcmp(
+			    &a->action.ext_community,
+			    &b->action.ext_community,
+			    sizeof(a->action.ext_community)) == 0)
+				continue;
+			break;
 		}
 		/* compare failed */
 		return (0);
@@ -616,7 +701,14 @@ filterset_name(enum action_types type)
 	case ACTION_RTLABEL:
 	case ACTION_RTLABEL_ID:
 		return ("rtlabel");
+	case ACTION_SET_ORIGIN:
+		return ("origin");
+	case ACTION_SET_EXT_COMMUNITY:
+		return ("ext-community");
+	case ACTION_DEL_EXT_COMMUNITY:
+		return ("ext-community delete");
 	}
 
 	fatalx("filterset_name: got lost");
+	return (NULL); /* NOT REACHED */
 }
