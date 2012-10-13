Index: bgpd/rde_prefix.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/rde_prefix.c,v
retrieving revision 1.1.1.6
retrieving revision 1.6
diff -u -p -r1.1.1.6 -r1.6
--- bgpd/rde_prefix.c	14 Feb 2010 20:19:57 -0000	1.1.1.6
+++ bgpd/rde_prefix.c	13 Oct 2012 18:36:00 -0000	1.6
@@ -1,4 +1,4 @@
-/*	$OpenBSD: rde_prefix.c,v 1.29 2009/05/30 18:27:17 claudio Exp $ */
+/*	$OpenBSD: rde_prefix.c,v 1.31 2010/01/13 06:02:37 claudio Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Claudio Jeker <claudio@openbsd.org>
@@ -38,15 +38,16 @@
  * pt_lookup: lookup a IP in the prefix table. Mainly for "show ip bgp".
  * pt_empty:  returns true if there is no bgp prefix linked to the pt_entry.
  * pt_init:   initialize prefix table.
- * pt_alloc?: allocate a AF specific pt_entry. Internal function.
+ * pt_alloc: allocate a AF specific pt_entry. Internal function.
  * pt_free:   free a pt_entry. Internal function.
  */
 
 /* internal prototypes */
-static struct pt_entry4	*pt_alloc4(void);
-static struct pt_entry6	*pt_alloc6(void);
+static struct pt_entry	*pt_alloc(struct pt_entry *);
 static void		 pt_free(struct pt_entry *);
 
+size_t	pt_sizes[AID_MAX] = AID_PTSIZE;
+
 RB_HEAD(pt_tree, pt_entry);
 RB_PROTOTYPE(pt_tree, pt_entry, pt_e, pt_prefix_cmp);
 RB_GENERATE(pt_tree, pt_entry, pt_e, pt_prefix_cmp);
@@ -70,17 +71,24 @@ void
 pt_getaddr(struct pt_entry *pte, struct bgpd_addr *addr)
 {
 	bzero(addr, sizeof(struct bgpd_addr));
-	switch (pte->af) {
-	case AF_INET:
-		addr->af = pte->af;
+	addr->aid = pte->aid;
+	switch (addr->aid) {
+	case AID_INET:
 		addr->v4 = ((struct pt_entry4 *)pte)->prefix4;
 		break;
-	case AF_INET6:
-		addr->af = pte->af;
+	case AID_INET6:
 		memcpy(&addr->v6, &((struct pt_entry6 *)pte)->prefix6,
 		    sizeof(addr->v6));
 		/* XXX scope_id ??? */
 		break;
+	case AID_VPN_IPv4:
+		addr->vpn4.addr = ((struct pt_entry_vpn4 *)pte)->prefix4;
+		addr->vpn4.rd = ((struct pt_entry_vpn4 *)pte)->rd;
+		addr->vpn4.labellen = ((struct pt_entry_vpn4 *)pte)->labellen;
+		memcpy(addr->vpn4.labelstack,
+		    ((struct pt_entry_vpn4 *)pte)->labelstack,
+		    addr->vpn4.labellen);
+		break;
 	default:
 		fatalx("pt_getaddr: unknown af");
 	}
@@ -89,33 +97,49 @@ pt_getaddr(struct pt_entry *pte, struct 
 struct pt_entry *
 pt_fill(struct bgpd_addr *prefix, int prefixlen)
 {
-	static struct pt_entry4	pte4;
-	static struct pt_entry6	pte6;
-	in_addr_t		addr_hbo;
+	static struct pt_entry4		pte4;
+	static struct pt_entry6		pte6;
+	static struct pt_entry_vpn4	pte_vpn4;
+	in_addr_t			addr_hbo;
 
-	switch (prefix->af) {
-	case AF_INET:
+	switch (prefix->aid) {
+	case AID_INET:
 		bzero(&pte4, sizeof(pte4));
+		pte4.aid = prefix->aid;
 		if (prefixlen > 32)
-			fatalx("pt_get: bad IPv4 prefixlen");
-		pte4.af = AF_INET;
+			fatalx("pt_fill: bad IPv4 prefixlen");
 		addr_hbo = ntohl(prefix->v4.s_addr);
 		pte4.prefix4.s_addr = htonl(addr_hbo &
 		    prefixlen2mask(prefixlen));
 		pte4.prefixlen = prefixlen;
 		return ((struct pt_entry *)&pte4);
-	case AF_INET6:
+	case AID_INET6:
 		bzero(&pte6, sizeof(pte6));
+		pte6.aid = prefix->aid;
 		if (prefixlen > 128)
 			fatalx("pt_get: bad IPv6 prefixlen");
-		pte6.af = AF_INET6;
 		pte6.prefixlen = prefixlen;
 		inet6applymask(&pte6.prefix6, &prefix->v6, prefixlen);
 		return ((struct pt_entry *)&pte6);
+	case AID_VPN_IPv4:
+		bzero(&pte_vpn4, sizeof(pte_vpn4));
+		pte_vpn4.aid = prefix->aid;
+		if (prefixlen > 32)
+			fatalx("pt_fill: bad IPv4 prefixlen");
+		addr_hbo = ntohl(prefix->vpn4.addr.s_addr);
+		pte_vpn4.prefix4.s_addr = htonl(addr_hbo &
+		    prefixlen2mask(prefixlen));
+		pte_vpn4.prefixlen = prefixlen;
+		pte_vpn4.rd = prefix->vpn4.rd;
+		pte_vpn4.labellen = prefix->vpn4.labellen;
+		memcpy(pte_vpn4.labelstack, prefix->vpn4.labelstack,
+		    prefix->vpn4.labellen);
+		return ((struct pt_entry *)&pte_vpn4);
 	default:
-		log_warnx("pt_get: unknown af");
-		return (NULL);
+		fatalx("pt_fill: unknown af");
 	}
+	/* NOT REACHED */
+	return (NULL);
 }
 
 struct pt_entry *
@@ -131,39 +155,12 @@ struct pt_entry *
 pt_add(struct bgpd_addr *prefix, int prefixlen)
 {
 	struct pt_entry		*p = NULL;
-	struct pt_entry4	*p4;
-	struct pt_entry6	*p6;
-	in_addr_t		 addr_hbo;
-
-	switch (prefix->af) {
-	case AF_INET:
-		p4 = pt_alloc4();
-		if (prefixlen > 32)
-			fatalx("pt_add: bad IPv4 prefixlen");
-		p4->af = AF_INET;
-		p4->prefixlen = prefixlen;
-		addr_hbo = ntohl(prefix->v4.s_addr);
-		p4->prefix4.s_addr = htonl(addr_hbo &
-		    prefixlen2mask(prefixlen));
-		p = (struct pt_entry *)p4;
-		break;
-	case AF_INET6:
-		p6 = pt_alloc6();
-		if (prefixlen > 128)
-			fatalx("pt_add: bad IPv6 prefixlen");
-		p6->af = AF_INET6;
-		p6->prefixlen = prefixlen;
-		inet6applymask(&p6->prefix6, &prefix->v6, prefixlen);
-		p = (struct pt_entry *)p6;
-		break;
-	default:
-		fatalx("pt_add: unknown af");
-	}
 
-	if (RB_INSERT(pt_tree, &pttable, p) != NULL) {
-		log_warnx("pt_add: insert failed");
-		return (NULL);
-	}
+	p = pt_fill(prefix, prefixlen);
+	p = pt_alloc(p);
+
+	if (RB_INSERT(pt_tree, &pttable, p) != NULL)
+		fatalx("pt_add: insert failed");
 
 	return (p);
 }
@@ -183,13 +180,14 @@ struct pt_entry *
 pt_lookup(struct bgpd_addr *addr)
 {
 	struct pt_entry	*p;
-	int		 i;
+	int		 i = 0;
 
-	switch (addr->af) {
-	case AF_INET:
+	switch (addr->aid) {
+	case AID_INET:
+	case AID_VPN_IPv4:
 		i = 32;
 		break;
-	case AF_INET6:
+	case AID_INET6:
 		i = 128;
 		break;
 	default:
@@ -206,17 +204,18 @@ pt_lookup(struct bgpd_addr *addr)
 int
 pt_prefix_cmp(const struct pt_entry *a, const struct pt_entry *b)
 {
-	const struct pt_entry4	*a4, *b4;
-	const struct pt_entry6	*a6, *b6;
-	int			 i;
+	const struct pt_entry4		*a4, *b4;
+	const struct pt_entry6		*a6, *b6;
+	const struct pt_entry_vpn4	*va4, *vb4;
+	int				 i;
 
-	if (a->af > b->af)
+	if (a->aid > b->aid)
 		return (1);
-	if (a->af < b->af)
+	if (a->aid < b->aid)
 		return (-1);
 
-	switch (a->af) {
-	case AF_INET:
+	switch (a->aid) {
+	case AID_INET:
 		a4 = (const struct pt_entry4 *)a;
 		b4 = (const struct pt_entry4 *)b;
 		if (ntohl(a4->prefix4.s_addr) > ntohl(b4->prefix4.s_addr))
@@ -228,7 +227,7 @@ pt_prefix_cmp(const struct pt_entry *a, 
 		if (a4->prefixlen < b4->prefixlen)
 			return (-1);
 		return (0);
-	case AF_INET6:
+	case AID_INET6:
 		a6 = (const struct pt_entry6 *)a;
 		b6 = (const struct pt_entry6 *)b;
 
@@ -242,49 +241,49 @@ pt_prefix_cmp(const struct pt_entry *a, 
 		if (a6->prefixlen > b6->prefixlen)
 			return (1);
 		return (0);
+	case AID_VPN_IPv4:
+		va4 = (const struct pt_entry_vpn4 *)a;
+		vb4 = (const struct pt_entry_vpn4 *)b;
+		if (ntohl(va4->prefix4.s_addr) > ntohl(vb4->prefix4.s_addr))
+			return (1);
+		if (ntohl(va4->prefix4.s_addr) < ntohl(vb4->prefix4.s_addr))
+			return (-1);
+		if (va4->prefixlen > vb4->prefixlen)
+			return (1);
+		if (va4->prefixlen < vb4->prefixlen)
+			return (-1);
+		if (betoh64(va4->rd) > betoh64(vb4->rd))
+			return (1);
+		if (betoh64(va4->rd) < betoh64(vb4->rd))
+			return (-1);
+		return (0);
 	default:
 		fatalx("pt_prefix_cmp: unknown af");
 	}
 	return (-1);
 }
 
-/* returns a zeroed pt_entry function may not return on fail */
-static struct pt_entry4 *
-pt_alloc4(void)
+/*
+ * Returns a pt_entry cloned from the one passed in.
+ * Function may not return on failure.
+ */
+static struct pt_entry *
+pt_alloc(struct pt_entry *op)
 {
-	struct pt_entry4	*p;
+	struct pt_entry		*p;
 
-	p = calloc(1, sizeof(*p));
+	p = malloc(pt_sizes[op->aid]);
 	if (p == NULL)
 		fatal("pt_alloc");
-	rdemem.pt4_cnt++;
-	return (p);
-}
+	rdemem.pt_cnt[op->aid]++;
+	memcpy(p, op, pt_sizes[op->aid]);
 
-static struct pt_entry6 *
-pt_alloc6(void)
-{
-	struct pt_entry6	*p;
-
-	p = calloc(1, sizeof(*p));
-	if (p == NULL)
-		fatal("pt_alloc");
-	rdemem.pt6_cnt++;
 	return (p);
 }
 
 static void
 pt_free(struct pt_entry *pte)
 {
-	switch (pte->af) {
-	case AF_INET:
-		rdemem.pt4_cnt--;
-		break;
-	case AF_INET6:
-		rdemem.pt6_cnt--;
-		break;
-	default:
-		break;
-	}
+	rdemem.pt_cnt[pte->aid]--;
 	free(pte);
 }
