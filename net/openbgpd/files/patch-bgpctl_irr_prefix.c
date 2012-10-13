Index: bgpctl/irr_prefix.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpctl/irr_prefix.c,v
retrieving revision 1.1.1.5
retrieving revision 1.1.1.8
diff -u -p -r1.1.1.5 -r1.1.1.8
--- bgpctl/irr_prefix.c	14 Feb 2010 20:20:14 -0000	1.1.1.5
+++ bgpctl/irr_prefix.c	13 Oct 2012 18:22:52 -0000	1.1.1.8
@@ -1,4 +1,4 @@
-/*	$OpenBSD: irr_prefix.c,v 1.15 2007/05/27 18:54:25 henning Exp $ */
+/*	$OpenBSD: irr_prefix.c,v 1.17 2009/09/08 16:11:36 sthen Exp $ */
 
 /*
  * Copyright (c) 2007 Henning Brauer <henning@openbsd.org>
@@ -29,6 +29,7 @@
 #include <arpa/inet.h>
 
 #include "irrfilter.h"
+#include "bgpd.h"
 
 void	 prefixset_aggregate(struct prefix_set *);
 int	 prefix_aggregate(struct irr_prefix *, const struct irr_prefix *);
@@ -63,7 +64,11 @@ prefixset_get(char *as)
 		fflush(stdout);
 	}
 	curpfxs = pfxs;
-	if (whois(as, QTYPE_ROUTE) == -1)
+	if ((irrflags & F_IPV4) && whois(as, QTYPE_ROUTE) == -1)
+		errx(1, "whois error, prefixset_get %s", as);
+	if ((irrflags & F_IPV6) && whois(as, QTYPE_ROUTE6) == -1)
+		errx(1, "whois error, prefixset_get %s", as);
+	if (whois(as, QTYPE_ROUTE6) == -1)
 		errx(1, "whois error, prefixset_get %s", as);
 	curpfxs = NULL;
 	if (irrverbose >= 3)
@@ -80,9 +85,11 @@ prefixset_addmember(char *s)
 	void			*p;
 	u_int			 i;
 	struct irr_prefix	*pfx;
-	int			 len;
+	int			 len, ret;
+	char			*slash;
+	const char		*errstr;
 
-	if (strchr(s, '/') == NULL) {
+	if ((slash = strchr(s, '/')) == NULL) {
 		fprintf(stderr, "%s: prefix %s does not have the len "
 		    "specified, ignoring\n", curpfxs->as, s);
 		return (0);
@@ -92,17 +99,26 @@ prefixset_addmember(char *s)
 		err(1, "prefixset_addmember calloc");
 
 	if ((len = inet_net_pton(AF_INET, s, &pfx->addr.in,
-	    sizeof(pfx->addr.in))) == -1) {
-		if (errno == ENOENT) {
-			fprintf(stderr, "%s: prefix \"%s\": parse error\n",
+	    sizeof(pfx->addr.in))) != -1) {
+		pfx->af = AF_INET;
+	} else {
+		len = strtonum(slash + 1, 0, 128, &errstr);
+		if (errstr)
+			errx(1, "prefixset_addmember %s prefix %s: prefixlen "
+			    "is %s", curpfxs->as, s, errstr);
+		*slash = '\0';
+
+		if ((ret = inet_pton(AF_INET6, s, &pfx->addr.in6)) == -1)
+			err(1, "prefixset_addmember %s prefix \"%s\"",
 			    curpfxs->as, s);
+		else if (ret == 0) {
+			fprintf(stderr, "prefixset_addmember %s prefix \"%s\": "
+			    "No matching address family found", curpfxs->as, s);
+			free(pfx);
 			return (0);
-		} else
-			err(1, "prefixset_addmember %s inet_net_pton \"%s\"",
-			    curpfxs->as, s);
+		}
+		pfx->af = AF_INET6;
 	}
-
-	pfx->af = AF_INET;
 	pfx->len = pfx->maxlen = len;
 
 	/* yes, there are dupes... e. g. from multiple sources */
@@ -175,24 +191,47 @@ prefixset_aggregate(struct prefix_set *p
 int
 prefix_aggregate(struct irr_prefix *a, const struct irr_prefix *b)
 {
-	in_addr_t	mask;
+	in_addr_t	 mask;
+	struct in6_addr	 ma;
+	struct in6_addr	 mb;
 
 	if (a->len == 0)
 		return (1);
 
-	mask = htonl(0xffffffff << (32 - a->len));
+	if (a->af != b->af)
+		/* We cannot aggregate addresses of different families. */
+		return (0);
 
-	if ((a->addr.in.s_addr & mask) == (b->addr.in.s_addr & mask))
-		return (1);
+	if (a->af == AF_INET) {
+		mask = htonl(prefixlen2mask(a->len));
+		if ((a->addr.in.s_addr & mask) == (b->addr.in.s_addr & mask))
+			return (1);
+	} else if (a->af == AF_INET6) {
+		inet6applymask(&ma, &a->addr.in6, a->len);
+		inet6applymask(&mb, &b->addr.in6, a->len);
+		if (IN6_ARE_ADDR_EQUAL(&ma, &mb))
+			return (1);
+	}
 
-	/* see wether we can fold them in one */
+	/* see whether we can fold them in one */
 	if (a->len == b->len && a->len > 1) {
-		mask = htonl(0xffffffff << (32 - (a->len - 1)));
-		if ((a->addr.in.s_addr & mask) ==
-		    (b->addr.in.s_addr & mask)) {
-			a->len--;
-			a->addr.in.s_addr &= mask;
-			return (1);
+		if (a->af == AF_INET) {
+			mask = htonl(prefixlen2mask(a->len - 1));
+			if ((a->addr.in.s_addr & mask) ==
+			    (b->addr.in.s_addr & mask)) {
+				a->len--;
+				a->addr.in.s_addr &= mask;
+				return (1);
+			}
+		} else if (a->af == AF_INET6) {
+			inet6applymask(&ma, &a->addr.in6, a->len - 1);
+			inet6applymask(&mb, &b->addr.in6, a->len - 1);
+
+			if (IN6_ARE_ADDR_EQUAL(&ma, &mb)) {
+				a->len--;
+				memcpy(&a->addr.in6, &ma, sizeof(ma));
+				return (1);
+			}
 		}
 	}
 
@@ -219,6 +258,13 @@ irr_prefix_cmp(const void *a, const void
 		if (ntohl(pa->addr.in.s_addr) >
 		    ntohl(pb->addr.in.s_addr))
 			return (1);
+	} else if (pa->af == AF_INET6) {
+		for (r = 0; r < 16; r++) {
+			if (pa->addr.in6.s6_addr[r] < pb->addr.in6.s6_addr[r])
+				return (-1);
+			if (pa->addr.in6.s6_addr[r] > pb->addr.in6.s6_addr[r])
+				return (1);
+		}
 	} else
 		errx(1, "irr_prefix_cmp unknown af %u", pa->af);
 
