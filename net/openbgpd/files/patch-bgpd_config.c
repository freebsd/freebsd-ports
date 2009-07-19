Index: bgpd/config.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/config.c,v
retrieving revision 1.1.1.1
retrieving revision 1.1.1.2
diff -u -p -r1.1.1.1 -r1.1.1.2
--- bgpd/config.c	30 Jun 2009 05:46:15 -0000	1.1.1.1
+++ bgpd/config.c	9 Jul 2009 16:49:54 -0000	1.1.1.2
@@ -1,4 +1,4 @@
-/*	$OpenBSD: config.c,v 1.50 2007/10/13 16:35:20 deraadt Exp $ */
+/*	$OpenBSD: config.c,v 1.51 2009/01/26 23:10:02 claudio Exp $ */
 
 /*
  * Copyright (c) 2003, 2004, 2005 Henning Brauer <henning@openbsd.org>
@@ -145,7 +145,7 @@ get_bgpid(void)
 		cur = ((struct sockaddr_in *)ifa->ifa_addr)->sin_addr.s_addr;
 		if ((cur & localnet) == localnet)	/* skip 127/8 */
 			continue;
-		if (cur > ip)
+		if (ntohl(cur) > ntohl(ip))
 			ip = cur;
 	}
 	freeifaddrs(ifap);
