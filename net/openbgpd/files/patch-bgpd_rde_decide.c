Index: bgpd/rde_decide.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/rde_decide.c,v
retrieving revision 1.1.1.6
retrieving revision 1.4
diff -u -p -r1.1.1.6 -r1.4
--- bgpd/rde_decide.c	14 Feb 2010 20:19:57 -0000	1.1.1.6
+++ bgpd/rde_decide.c	13 Oct 2012 18:36:00 -0000	1.4
@@ -1,4 +1,4 @@
-/*	$OpenBSD: rde_decide.c,v 1.58 2009/06/29 14:10:13 claudio Exp $ */
+/*	$OpenBSD: rde_decide.c,v 1.61 2012/04/12 17:31:05 claudio Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Claudio Jeker <claudio@openbsd.org>
@@ -109,6 +109,9 @@ int
 prefix_cmp(struct prefix *p1, struct prefix *p2)
 {
 	struct rde_aspath	*asp1, *asp2;
+	struct attr		*a;
+	u_int32_t		 p1id, p2id;
+	int			 p1cnt, p2cnt;
 
 	if (p1 == NULL)
 		return (-1);
@@ -118,6 +121,12 @@ prefix_cmp(struct prefix *p1, struct pre
 	asp1 = p1->aspath;
 	asp2 = p2->aspath;
 
+	/* pathes with errors are not eligible */
+	if (asp1->flags & F_ATTR_PARSE_ERR)
+		return (-1);
+	if (asp2->flags & F_ATTR_PARSE_ERR)
+		return (1);
+
 	/* only loop free pathes are eligible */
 	if (asp1->flags & F_ATTR_LOOP)
 		return (-1);
@@ -130,7 +139,7 @@ prefix_cmp(struct prefix *p1, struct pre
 	if (asp1->nexthop != NULL && asp1->nexthop->state != NEXTHOP_REACH)
 		return (-1);
 
-	/* 2. preference of prefix, bigger is better */
+	/* 2. local preference of prefix, bigger is better */
 	if ((asp1->lpref - asp2->lpref) != 0)
 		return (asp1->lpref - asp2->lpref);
 
@@ -154,10 +163,10 @@ prefix_cmp(struct prefix *p1, struct pre
 	 * It is absolutely important that the ebgp value in peer_config.ebgp
 	 * is bigger than all other ones (IBGP, confederations)
 	 */
-	if ((asp1->peer->conf.ebgp - asp2->peer->conf.ebgp) != 0) {
-		if (asp1->peer->conf.ebgp == 1) /* p1 is EBGP other is lower */
+	if (asp1->peer->conf.ebgp != asp2->peer->conf.ebgp) {
+		if (asp1->peer->conf.ebgp) /* p1 is EBGP other is lower */
 			return 1;
-		else if (asp2->peer->conf.ebgp == 1) /* p2 is EBGP */
+		else if (asp2->peer->conf.ebgp) /* p2 is EBGP */
 			return -1;
 	}
 
@@ -181,13 +190,30 @@ prefix_cmp(struct prefix *p1, struct pre
 		if ((p2->lastchange - p1->lastchange) != 0)
 			return (p2->lastchange - p1->lastchange);
 
-	/* 10. lowest BGP Id wins */
-	if ((p2->aspath->peer->remote_bgpid -
-	    p1->aspath->peer->remote_bgpid) != 0)
-		return (p2->aspath->peer->remote_bgpid -
-		    p1->aspath->peer->remote_bgpid);
+	/* 10. lowest BGP Id wins, use ORIGINATOR_ID if present */
+	if ((a = attr_optget(asp1, ATTR_ORIGINATOR_ID)) != NULL) {
+		memcpy(&p1id, a->data, sizeof(p1id));
+		p1id = ntohl(p1id);
+	} else
+		p1id = asp1->peer->remote_bgpid;
+	if ((a = attr_optget(asp2, ATTR_ORIGINATOR_ID)) != NULL) {
+		memcpy(&p2id, a->data, sizeof(p2id));
+		p2id = ntohl(p2id);
+	} else
+		p2id = asp2->peer->remote_bgpid;
+	if ((p2id - p1id) != 0)
+		return (p2id - p1id);
+
+	/* 11. compare CLUSTER_LIST length, shorter is better */
+	p1cnt = p2cnt = 0;
+	if ((a = attr_optget(asp1, ATTR_CLUSTER_LIST)) != NULL)
+		p1cnt = a->len / sizeof(u_int32_t);
+	if ((a = attr_optget(asp2, ATTR_CLUSTER_LIST)) != NULL)
+		p2cnt = a->len / sizeof(u_int32_t);
+	if ((p2cnt - p1cnt) != 0)
+		return (p2cnt - p1cnt);
 
-	/* 11. lowest peer address wins (IPv4 is better than IPv6) */
+	/* 12. lowest peer address wins (IPv4 is better than IPv6) */
 	if (memcmp(&p1->aspath->peer->remote_addr,
 	    &p2->aspath->peer->remote_addr,
 	    sizeof(p1->aspath->peer->remote_addr)) != 0)
@@ -195,7 +221,7 @@ prefix_cmp(struct prefix *p1, struct pre
 		    &p2->aspath->peer->remote_addr,
 		    sizeof(p1->aspath->peer->remote_addr)));
 
-	/* 12. for announced prefixes prefer dynamic routes */
+	/* 13. for announced prefixes prefer dynamic routes */
 	if ((asp1->flags & F_ANN_DYNAMIC) != (asp2->flags & F_ANN_DYNAMIC)) {
 		if (asp1->flags & F_ANN_DYNAMIC)
 			return (1);
@@ -204,7 +230,7 @@ prefix_cmp(struct prefix *p1, struct pre
 	}
 
 	fatalx("Uh, oh a politician in the decision process");
-	/* NOTREACHED */
+	return(0);	/* NOTREACHED */
 }
 
 /*
@@ -245,7 +271,7 @@ prefix_evaluate(struct prefix *p, struct
 	}
 
 	xp = LIST_FIRST(&re->prefix_h);
-	if (xp == NULL || xp->aspath->flags & F_ATTR_LOOP ||
+	if (xp == NULL || xp->aspath->flags & (F_ATTR_LOOP|F_ATTR_PARSE_ERR) ||
 	    (xp->aspath->nexthop != NULL &&
 	    xp->aspath->nexthop->state != NEXTHOP_REACH))
 		/* xp is ineligible */
@@ -263,7 +289,7 @@ prefix_evaluate(struct prefix *p, struct
 		 */
 		rde_generate_updates(re->ribid, xp, re->active);
 		if ((re->flags & F_RIB_NOFIB) == 0)
-			rde_send_kroute(xp, re->active);
+			rde_send_kroute(xp, re->active, re->ribid);
 
 		re->active = xp;
 		if (xp != NULL)
