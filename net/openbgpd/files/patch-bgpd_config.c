Index: bgpd/config.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/config.c,v
retrieving revision 1.1.1.6
retrieving revision 1.1.1.7
diff -u -p -r1.1.1.6 -r1.1.1.7
--- bgpd/config.c	14 Feb 2010 20:19:57 -0000	1.1.1.6
+++ bgpd/config.c	14 Feb 2010 20:27:06 -0000	1.1.1.7
@@ -1,4 +1,4 @@
-/*	$OpenBSD: config.c,v 1.51 2009/01/26 23:10:02 claudio Exp $ */
+/*	$OpenBSD: config.c,v 1.52 2009/12/01 14:28:05 claudio Exp $ */
 
 /*
  * Copyright (c) 2003, 2004, 2005 Henning Brauer <henning@openbsd.org>
@@ -208,7 +208,7 @@ host_v4(const char *s, struct bgpd_addr 
 			return (0);
 	}
 
-	h->af = AF_INET;
+	h->aid = AID_INET;
 	h->v4.s_addr = ina.s_addr;
 	*len = bits;
 
@@ -225,13 +225,7 @@ host_v6(const char *s, struct bgpd_addr 
 	hints.ai_socktype = SOCK_DGRAM; /*dummy*/
 	hints.ai_flags = AI_NUMERICHOST;
 	if (getaddrinfo(s, "0", &hints, &res) == 0) {
-		h->af = AF_INET6;
-		memcpy(&h->v6,
-		    &((struct sockaddr_in6 *)res->ai_addr)->sin6_addr,
-		    sizeof(h->v6));
-		h->scope_id =
-		    ((struct sockaddr_in6 *)res->ai_addr)->sin6_scope_id;
-
+		sa2addr(res->ai_addr, h);
 		freeaddrinfo(res);
 		return (1);
 	}
