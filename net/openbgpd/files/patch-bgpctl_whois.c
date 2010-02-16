Index: bgpctl/whois.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpctl/whois.c,v
retrieving revision 1.1.1.5
retrieving revision 1.1.1.6
diff -u -p -r1.1.1.5 -r1.1.1.6
--- bgpctl/whois.c	14 Feb 2010 20:20:14 -0000	1.1.1.5
+++ bgpctl/whois.c	14 Feb 2010 20:27:21 -0000	1.1.1.6
@@ -1,4 +1,4 @@
-/*	$OpenBSD: whois.c,v 1.3 2007/03/05 16:43:24 henning Exp $ */
+/*	$OpenBSD: whois.c,v 1.4 2009/09/08 15:40:25 claudio Exp $ */
 
 /*
  * Copyright (c) 2007 Henning Brauer <henning@openbsd.org>
@@ -68,7 +68,8 @@ char *qtype_opts[] = {
 	"",
 	"-T aut-num",
 	"-K -T as-set",
-	"-K -T route -i origin"
+	"-K -T route -i origin",
+	"-K -T route6 -i origin"
 };
 
 char	*server = "whois.radb.net";
