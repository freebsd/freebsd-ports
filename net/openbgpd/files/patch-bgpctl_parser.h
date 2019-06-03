Index: bgpctl/parser.h
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpctl/parser.h,v
retrieving revision 1.1.1.6
retrieving revision 1.1.1.9
diff -u -p -r1.1.1.6 -r1.1.1.9
--- bgpctl/parser.h	14 Feb 2010 20:20:14 -0000	1.1.1.6
+++ bgpctl/parser.h	13 Oct 2012 18:22:53 -0000	1.1.1.9
@@ -1,4 +1,4 @@
-/*	$OpenBSD: parser.h,v 1.19 2009/06/06 06:05:41 claudio Exp $ */
+/*	$OpenBSD: parser.h,v 1.23 2011/09/21 10:37:51 claudio Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Henning Brauer <henning@openbsd.org>
@@ -29,7 +29,9 @@ enum actions {
 	SHOW_NEIGHBOR_TIMERS,
 	SHOW_NEIGHBOR_TERSE,
 	SHOW_FIB,
+	SHOW_FIB_TABLES,
 	SHOW_RIB,
+	SHOW_MRT,
 	SHOW_RIB_MEM,
 	SHOW_NEXTHOP,
 	SHOW_INTERFACE,
@@ -37,6 +39,8 @@ enum actions {
 	FIB,
 	FIB_COUPLE,
 	FIB_DECOUPLE,
+	LOG_VERBOSE,
+	LOG_BRIEF,
 	NEIGHBOR,
 	NEIGHBOR_UP,
 	NEIGHBOR_DOWN,
@@ -46,6 +50,7 @@ enum actions {
 	NETWORK_REMOVE,
 	NETWORK_FLUSH,
 	NETWORK_SHOW,
+	NETWORK_MRT,
 	IRRFILTER
 };
 
@@ -59,9 +64,11 @@ struct parse_result {
 	char			 rib[PEER_DESCR_LEN];
 	char			*irr_outdir;
 	int			 flags;
-	enum actions		action;
+	u_int			 rtableid;
+	enum actions		 action;
 	u_int8_t		 prefixlen;
-	sa_family_t		 af;
+	u_int8_t		 aid;
+	int			 mrtfd;
 };
 
 __dead void		 usage(void);
