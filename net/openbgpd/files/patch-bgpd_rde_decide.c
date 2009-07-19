Index: bgpd/rde_decide.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/rde_decide.c,v
retrieving revision 1.1.1.1
retrieving revision 1.1.1.2
diff -u -p -r1.1.1.1 -r1.1.1.2
--- bgpd/rde_decide.c	30 Jun 2009 05:46:15 -0000	1.1.1.1
+++ bgpd/rde_decide.c	9 Jul 2009 16:49:54 -0000	1.1.1.2
@@ -1,4 +1,4 @@
-/*	$OpenBSD: rde_decide.c,v 1.51 2008/05/08 09:51:46 henning Exp $ */
+/*	$OpenBSD: rde_decide.c,v 1.58 2009/06/29 14:10:13 claudio Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Claudio Jeker <claudio@openbsd.org>
@@ -115,12 +115,6 @@ prefix_cmp(struct prefix *p1, struct pre
 	if (p2 == NULL)
 		return (1);
 
-	/* only prefixes in the Local-RIB are eligible */
-	if (!(p1->flags & F_LOCAL))
-		return (-1);
-	if (!(p2->flags & F_LOCAL))
-		return (1);
-
 	asp1 = p1->aspath;
 	asp2 = p2->aspath;
 
@@ -201,9 +195,16 @@ prefix_cmp(struct prefix *p1, struct pre
 		    &p2->aspath->peer->remote_addr,
 		    sizeof(p1->aspath->peer->remote_addr)));
 
+	/* 12. for announced prefixes prefer dynamic routes */
+	if ((asp1->flags & F_ANN_DYNAMIC) != (asp2->flags & F_ANN_DYNAMIC)) {
+		if (asp1->flags & F_ANN_DYNAMIC)
+			return (1);
+		else
+			return (-1);
+	}
+
 	fatalx("Uh, oh a politician in the decision process");
 	/* NOTREACHED */
-	return (0);
 }
 
 /*
@@ -212,59 +213,59 @@ prefix_cmp(struct prefix *p1, struct pre
  * The to evaluate prefix must not be in the prefix list.
  */
 void
-prefix_evaluate(struct prefix *p, struct pt_entry *pte)
+prefix_evaluate(struct prefix *p, struct rib_entry *re)
 {
 	struct prefix	*xp;
 
-	if (rde_noevaluate()) {
+	if (re->flags & F_RIB_NOEVALUATE || rde_noevaluate()) {
 		/* decision process is turned off */
 		if (p != NULL)
-			LIST_INSERT_HEAD(&pte->prefix_h, p, prefix_l);
-		if (pte->active != NULL) {
-			pte->active->aspath->active_cnt--;
-			pte->active = NULL;
+			LIST_INSERT_HEAD(&re->prefix_h, p, rib_l);
+		if (re->active != NULL) {
+			re->active->aspath->active_cnt--;
+			re->active = NULL;
 		}
 		return;
 	}
 
 	if (p != NULL) {
-		if (LIST_EMPTY(&pte->prefix_h))
-			LIST_INSERT_HEAD(&pte->prefix_h, p, prefix_l);
+		if (LIST_EMPTY(&re->prefix_h))
+			LIST_INSERT_HEAD(&re->prefix_h, p, rib_l);
 		else {
-			LIST_FOREACH(xp, &pte->prefix_h, prefix_l)
+			LIST_FOREACH(xp, &re->prefix_h, rib_l)
 				if (prefix_cmp(p, xp) > 0) {
-					LIST_INSERT_BEFORE(xp, p, prefix_l);
+					LIST_INSERT_BEFORE(xp, p, rib_l);
 					break;
-				} else if (LIST_NEXT(xp, prefix_l) == NULL) {
+				} else if (LIST_NEXT(xp, rib_l) == NULL) {
 					/* if xp last element ... */
-					LIST_INSERT_AFTER(xp, p, prefix_l);
+					LIST_INSERT_AFTER(xp, p, rib_l);
 					break;
 				}
 		}
 	}
 
-	xp = LIST_FIRST(&pte->prefix_h);
-	if (xp == NULL || !(xp->flags & F_LOCAL) ||
-	    xp->aspath->flags & F_ATTR_LOOP ||
+	xp = LIST_FIRST(&re->prefix_h);
+	if (xp == NULL || xp->aspath->flags & F_ATTR_LOOP ||
 	    (xp->aspath->nexthop != NULL &&
 	    xp->aspath->nexthop->state != NEXTHOP_REACH))
 		/* xp is ineligible */
 		xp = NULL;
 
-	if (pte->active != xp) {
+	if (re->active != xp) {
 		/* need to generate an update */
-		if (pte->active != NULL)
-			pte->active->aspath->active_cnt--;
+		if (re->active != NULL)
+			re->active->aspath->active_cnt--;
 
 		/*
-		 * Send update with remove for pte->active and add for xp
+		 * Send update with remove for re->active and add for xp
 		 * but remember that xp may be NULL aka ineligible.
 		 * Additional decision may be made by the called functions.
 		 */
-		rde_generate_updates(xp, pte->active);
-		rde_send_kroute(xp, pte->active);
+		rde_generate_updates(re->ribid, xp, re->active);
+		if ((re->flags & F_RIB_NOFIB) == 0)
+			rde_send_kroute(xp, re->active);
 
-		pte->active = xp;
+		re->active = xp;
 		if (xp != NULL)
 			xp->aspath->active_cnt++;
 	}
