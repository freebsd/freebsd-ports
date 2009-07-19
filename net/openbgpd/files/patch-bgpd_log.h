Index: bgpd/log.h
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/log.h,v
retrieving revision 1.1.1.1
retrieving revision 1.1.1.2
diff -u -p -r1.1.1.1 -r1.1.1.2
--- bgpd/log.h	30 Jun 2009 05:46:15 -0000	1.1.1.1
+++ bgpd/log.h	9 Jul 2009 16:49:54 -0000	1.1.1.2
@@ -1,4 +1,4 @@
-/*	$OpenBSD: log.h,v 1.10 2007/12/23 18:26:13 henning Exp $ */
+/*	$OpenBSD: log.h,v 1.11 2008/09/11 14:49:58 henning Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Henning Brauer <henning@openbsd.org>
@@ -119,5 +119,6 @@ static const char * const timernames[] =
 	"HoldTimer",
 	"IdleHoldTimer",
 	"IdleHoldResetTimer",
+	"CarpUndemoteTimer",
 	""
 };
