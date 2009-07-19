Index: bgpd/util.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/util.c,v
retrieving revision 1.1.1.1
retrieving revision 1.3
diff -u -p -r1.1.1.1 -r1.3
--- bgpd/util.c	30 Jun 2009 05:46:15 -0000	1.1.1.1
+++ bgpd/util.c	9 Jul 2009 17:22:14 -0000	1.3
@@ -1,4 +1,4 @@
-/*	$OpenBSD: util.c,v 1.4 2008/03/17 20:40:04 henning Exp $ */
+/*	$OpenBSD: util.c,v 1.6 2009/06/12 16:42:53 claudio Exp $ */
 
 /*
  * Copyright (c) 2006 Claudio Jeker <claudio@openbsd.org>
@@ -18,6 +18,9 @@
  */
 #include <sys/types.h>
 #include <sys/socket.h>
+#if defined(__FreeBSD__)	/* sys/limits.h */
+#include <sys/limits.h>
+#endif /* defined(__FreeBSD__) */
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <netdb.h>
@@ -143,7 +146,7 @@ aspath_snprint(char *buf, size_t size, v
 			UPDATE();
 		}
 	}
-	/* ensure that we have a valid C-string especially for emtpy as path */
+	/* ensure that we have a valid C-string especially for empty as path */
 	if (size > 0)
 		*buf = '\0';
 
@@ -250,3 +253,29 @@ aspath_extract(const void *seg, int pos)
 	memcpy(&as, ptr, sizeof(u_int32_t));
 	return (ntohl(as));
 }
+
+in_addr_t
+prefixlen2mask(u_int8_t prefixlen)
+{
+	if (prefixlen == 0)
+		return (0);
+
+	return (0xffffffff << (32 - prefixlen));
+}
+
+void
+inet6applymask(struct in6_addr *dest, const struct in6_addr *src, int prefixlen)
+{
+	struct in6_addr	mask;
+	int		i;
+
+	bzero(&mask, sizeof(mask));
+	for (i = 0; i < prefixlen / 8; i++)
+		mask.s6_addr[i] = 0xff;
+	i = prefixlen % 8;
+	if (i)
+		mask.s6_addr[prefixlen / 8] = 0xff00 >> i;
+
+	for (i = 0; i < 16; i++)
+		dest->s6_addr[i] = src->s6_addr[i] & mask.s6_addr[i];
+}
