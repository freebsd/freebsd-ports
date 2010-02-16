Index: bgpd/rde_filter.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/rde_filter.c,v
retrieving revision 1.1.1.7
retrieving revision 1.5
diff -u -p -r1.1.1.7 -r1.5
--- bgpd/rde_filter.c	14 Feb 2010 20:19:57 -0000	1.1.1.7
+++ bgpd/rde_filter.c	4 Feb 2010 16:22:23 -0000	1.5
@@ -1,4 +1,4 @@
-/*	$OpenBSD: rde_filter.c,v 1.56 2009/06/06 01:10:29 claudio Exp $ */
+/*	$OpenBSD: rde_filter.c,v 1.61 2009/12/18 15:51:37 claudio Exp $ */
 
 /*
  * Copyright (c) 2004 Claudio Jeker <claudio@openbsd.org>
@@ -40,6 +40,13 @@ rde_filter(u_int16_t ribid, struct rde_a
 	if (new != NULL)
 		*new = NULL;
 
+	if (asp->flags & F_ATTR_PARSE_ERR)
+		/*
+	 	 * don't try to filter bad updates but let them through
+		 * so they act as implicit withdraws
+		 */
+		return (action);
+
 	TAILQ_FOREACH(f, rules, entry) {
 		if (dir != f->dir)
 			continue;
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
@@ -243,6 +250,17 @@ rde_apply_set(struct rde_aspath *asp, st
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
@@ -281,12 +299,12 @@ rde_filter_match(struct filter_rule *f, 
 			break;
 		}
 
-		if (rde_filter_community(asp, as, type) == 0)
+		if (community_match(asp, as, type) == 0)
 			return (0);
 	}
 
-	if (f->match.prefix.addr.af != 0) {
-		if (f->match.prefix.addr.af != prefix->af)
+	if (f->match.prefix.addr.aid != 0) {
+		if (f->match.prefix.addr.aid != prefix->aid)
 			/* don't use IPv4 rules for IPv6 and vice versa */
 			return (0);
 
@@ -322,7 +340,7 @@ rde_filter_match(struct filter_rule *f, 
 	} else if (f->match.prefixlen.op != OP_NONE) {
 		/* only prefixlen without a prefix */
 
-		if (f->match.prefixlen.af != prefix->af)
+		if (f->match.prefixlen.aid != prefix->aid)
 			/* don't use IPv4 rules for IPv6 and vice versa */
 			return (0);
 
@@ -356,19 +374,6 @@ rde_filter_match(struct filter_rule *f, 
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
@@ -476,6 +481,12 @@ filterset_cmp(struct filter_set *a, stru
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
@@ -483,7 +494,7 @@ filterset_cmp(struct filter_set *a, stru
 		 * reject it at the same time. Allow one IPv4 and one IPv6
 		 * per filter set or only one of the other nexthop modifiers.
 		 */
-		return (a->action.nexthop.af - b->action.nexthop.af);
+		return (a->action.nexthop.aid - b->action.nexthop.aid);
 	}
 
 	/* equal */
@@ -574,6 +585,19 @@ filterset_equal(struct filter_set_head *
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
@@ -616,7 +640,14 @@ filterset_name(enum action_types type)
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
