Index: bgpd/rde_decide.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/rde_decide.c,v
retrieving revision 1.1.1.6
retrieving revision 1.2
diff -u -p -r1.1.1.6 -r1.2
--- bgpd/rde_decide.c	14 Feb 2010 20:19:57 -0000	1.1.1.6
+++ bgpd/rde_decide.c	22 Oct 2009 15:12:21 -0000	1.2
@@ -1,4 +1,4 @@
-/*	$OpenBSD: rde_decide.c,v 1.58 2009/06/29 14:10:13 claudio Exp $ */
+/*	$OpenBSD: rde_decide.c,v 1.59 2009/08/06 08:53:11 claudio Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Claudio Jeker <claudio@openbsd.org>
@@ -118,6 +118,12 @@ prefix_cmp(struct prefix *p1, struct pre
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
@@ -204,7 +210,7 @@ prefix_cmp(struct prefix *p1, struct pre
 	}
 
 	fatalx("Uh, oh a politician in the decision process");
-	/* NOTREACHED */
+	return(0);	/* NOTREACHED */
 }
 
 /*
@@ -245,7 +251,7 @@ prefix_evaluate(struct prefix *p, struct
 	}
 
 	xp = LIST_FIRST(&re->prefix_h);
-	if (xp == NULL || xp->aspath->flags & F_ATTR_LOOP ||
+	if (xp == NULL || xp->aspath->flags & (F_ATTR_LOOP|F_ATTR_PARSE_ERR) ||
 	    (xp->aspath->nexthop != NULL &&
 	    xp->aspath->nexthop->state != NEXTHOP_REACH))
 		/* xp is ineligible */
