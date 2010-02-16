Index: bgpctl/irr_parser.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpctl/irr_parser.c,v
retrieving revision 1.1.1.5
retrieving revision 1.4
diff -u -p -r1.1.1.5 -r1.4
--- bgpctl/irr_parser.c	14 Feb 2010 20:20:14 -0000	1.1.1.5
+++ bgpctl/irr_parser.c	4 Feb 2010 16:22:26 -0000	1.4
@@ -1,4 +1,4 @@
-/*	$OpenBSD: irr_parser.c,v 1.8 2007/03/05 22:34:08 henning Exp $ */
+/*	$OpenBSD: irr_parser.c,v 1.9 2009/09/08 15:40:25 claudio Exp $ */
 
 /*
  * Copyright (c) 2007 Henning Brauer <henning@openbsd.org>
@@ -81,6 +81,7 @@ parse_response(FILE *f, enum qtype qtype
 				return (-1);
 			break;
 		case QTYPE_ROUTE:
+		case QTYPE_ROUTE6:
 			if ((n = parse_route(key, val)) == -1)
 				return (-1);
 			break;
@@ -281,7 +282,7 @@ parse_policy(char *key, char *val)
 				    !isdigit(tok[2]))
 					errx(1, "peering spec \"%s\": format "
 					    "error, AS expected", tok);
-				pi->peer_as = strtonum(tok + 2, 1, USHRT_MAX,
+				pi->peer_as = strtonum(tok + 2, 1, UINT_MAX,
 				    &errstr);
 				if (errstr)
 					errx(1, "peering spec \"%s\": format "
@@ -407,7 +408,8 @@ parse_asset(char *key, char *val)
 int
 parse_route(char *key, char *val)
 {
-	if (strcmp(key, "route"))	/* ignore everything else */
+	if (strcmp(key, "route") && strcmp(key, "route6"))
+		/* ignore everything else */
 		return (0);
 
 	/* route is single-value, but seen trailing , in the wild */
