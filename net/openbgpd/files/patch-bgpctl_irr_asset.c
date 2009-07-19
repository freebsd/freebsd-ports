Index: bgpctl/irr_asset.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpctl/irr_asset.c,v
retrieving revision 1.1.1.1
retrieving revision 1.1.1.2
diff -u -p -r1.1.1.1 -r1.1.1.2
--- bgpctl/irr_asset.c	30 Jun 2009 05:46:15 -0000	1.1.1.1
+++ bgpctl/irr_asset.c	9 Jul 2009 16:49:55 -0000	1.1.1.2
@@ -1,4 +1,4 @@
-/*	$OpenBSD: irr_asset.c,v 1.7 2007/03/31 12:46:55 henning Exp $ */
+/*	$OpenBSD: irr_asset.c,v 1.8 2009/04/14 21:10:54 jj Exp $ */
 
 /*
  * Copyright (c) 2007 Henning Brauer <henning@openbsd.org>
@@ -105,7 +105,7 @@ asset_get(char *name)
 		break;
 	case T_AUTNUM:
 		/*
-		 * make a dummy as-set with the the AS both as name
+		 * make a dummy as-set with the AS both as name
 		 * and its only member
 		 */
 		asset_add_as(ass, name);
