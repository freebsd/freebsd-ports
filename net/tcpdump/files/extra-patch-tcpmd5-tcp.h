--- tcp.h.orig	Tue Dec 10 23:14:11 2002
+++ tcp.h	Mon Aug  2 18:40:16 2004
@@ -1,4 +1,4 @@
-/* @(#) $Header: /tcpdump/master/tcpdump/tcp.h,v 1.10 2002/12/11 07:14:11 guy Exp $ (LBL) */
+/* @(#) $Header: /tcpdump/master/tcpdump/tcp.h,v 1.11 2004/03/23 07:15:37 guy Exp $ (LBL) */
 /*
  * Copyright (c) 1982, 1986, 1993
  *	The Regents of the University of California.  All rights reserved.
@@ -75,6 +75,10 @@
 #define TCPOPT_CC		11	/* T/TCP CC options (rfc1644) */
 #define TCPOPT_CCNEW		12	/* T/TCP CC options (rfc1644) */
 #define TCPOPT_CCECHO		13	/* T/TCP CC options (rfc1644) */
+#define TCPOPT_SIGNATURE	19	/* Keyed MD5 (rfc2385) */
+#define    TCPOLEN_SIGNATURE		18
+
+#define TCP_SIGLEN 16			/* length of an option 19 digest */
 
 #define TCPOPT_TSTAMP_HDR	\
     (TCPOPT_NOP<<24|TCPOPT_NOP<<16|TCPOPT_TIMESTAMP<<8|TCPOLEN_TIMESTAMP)
