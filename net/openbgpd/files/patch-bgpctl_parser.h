Index: bgpctl/parser.h
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpctl/parser.h,v
retrieving revision 1.1.1.6
retrieving revision 1.1.1.7
diff -u -p -r1.1.1.6 -r1.1.1.7
--- bgpctl/parser.h	14 Feb 2010 20:20:14 -0000	1.1.1.6
+++ bgpctl/parser.h	14 Feb 2010 20:27:21 -0000	1.1.1.7
@@ -1,4 +1,4 @@
-/*	$OpenBSD: parser.h,v 1.19 2009/06/06 06:05:41 claudio Exp $ */
+/*	$OpenBSD: parser.h,v 1.21 2010/01/10 00:16:23 claudio Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Henning Brauer <henning@openbsd.org>
@@ -37,6 +37,8 @@ enum actions {
 	FIB,
 	FIB_COUPLE,
 	FIB_DECOUPLE,
+	LOG_VERBOSE,
+	LOG_BRIEF,
 	NEIGHBOR,
 	NEIGHBOR_UP,
 	NEIGHBOR_DOWN,
@@ -61,7 +63,7 @@ struct parse_result {
 	int			 flags;
 	enum actions		action;
 	u_int8_t		 prefixlen;
-	sa_family_t		 af;
+	u_int8_t		 aid;
 };
 
 __dead void		 usage(void);
