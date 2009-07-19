Index: bgpctl/parser.h
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpctl/parser.h,v
retrieving revision 1.1.1.1
retrieving revision 1.1.1.2
diff -u -p -r1.1.1.1 -r1.1.1.2
--- bgpctl/parser.h	30 Jun 2009 05:46:15 -0000	1.1.1.1
+++ bgpctl/parser.h	9 Jul 2009 16:49:55 -0000	1.1.1.2
@@ -1,4 +1,4 @@
-/*	$OpenBSD: parser.h,v 1.18 2008/06/07 18:14:41 henning Exp $ */
+/*	$OpenBSD: parser.h,v 1.19 2009/06/06 06:05:41 claudio Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Henning Brauer <henning@openbsd.org>
@@ -56,6 +56,7 @@ struct parse_result {
 	struct filter_set_head	 set;
 	struct filter_community  community;
 	char			 peerdesc[PEER_DESCR_LEN];
+	char			 rib[PEER_DESCR_LEN];
 	char			*irr_outdir;
 	int			 flags;
 	enum actions		action;
