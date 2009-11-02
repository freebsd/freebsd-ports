Index: bgpd/rde_filter.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/rde_filter.c,v
retrieving revision 1.1.1.1
retrieving revision 1.4
diff -u -p -r1.1.1.1 -r1.4
--- bgpd/rde_filter.c	30 Jun 2009 05:46:15 -0000	1.1.1.1
+++ bgpd/rde_filter.c	10 Aug 2009 21:20:05 -0000	1.4
@@ -1,4 +1,4 @@
-/*	$OpenBSD: rde_filter.c,v 1.54 2008/06/15 10:19:21 claudio Exp $ */
+/*	$OpenBSD: rde_filter.c,v 1.57 2009/08/06 08:53:11 claudio Exp $ */
 
 /*
  * Copyright (c) 2004 Claudio Jeker <claudio@openbsd.org>
@@ -30,7 +30,7 @@ int	rde_filter_match(struct filter_rule 
 int	filterset_equal(struct filter_set_head *, struct filter_set_head *);
 
 enum filter_actions
-rde_filter(struct rde_aspath **new, struct filter_head *rules,
+rde_filter(u_int16_t ribid, struct rde_aspath **new, struct filter_head *rules,
     struct rde_peer *peer, struct rde_aspath *asp, struct bgpd_addr *prefix,
     u_int8_t prefixlen, struct rde_peer *from, enum directions dir)
 {
@@ -40,9 +40,18 @@ rde_filter(struct rde_aspath **new, stru
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
+		if (dir == DIR_IN && f->peer.ribid != ribid)
+			continue;
 		if (f->peer.groupid != 0 &&
 		    f->peer.groupid != peer->conf.groupid)
 			continue;
@@ -283,8 +292,11 @@ rde_filter_match(struct filter_rule *f, 
 			return (0);
 	}
 
-	if (f->match.prefix.addr.af != 0 &&
-	    f->match.prefix.addr.af == prefix->af) {
+	if (f->match.prefix.addr.af != 0) {
+		if (f->match.prefix.addr.af != prefix->af)
+			/* don't use IPv4 rules for IPv6 and vice versa */
+			return (0);
+
 		if (prefix_compare(prefix, &f->match.prefix.addr,
 		    f->match.prefix.len))
 			return (0);
@@ -614,4 +626,5 @@ filterset_name(enum action_types type)
 	}
 
 	fatalx("filterset_name: got lost");
+	return (NULL); /* NOT REACHED */
 }
