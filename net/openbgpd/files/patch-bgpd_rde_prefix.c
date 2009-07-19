Index: bgpd/rde_prefix.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/rde_prefix.c,v
retrieving revision 1.1.1.1
retrieving revision 1.3
diff -u -p -r1.1.1.1 -r1.3
--- bgpd/rde_prefix.c	30 Jun 2009 05:46:15 -0000	1.1.1.1
+++ bgpd/rde_prefix.c	9 Jul 2009 17:22:14 -0000	1.3
@@ -1,4 +1,4 @@
-/*	$OpenBSD: rde_prefix.c,v 1.25 2007/05/11 11:27:59 claudio Exp $ */
+/*	$OpenBSD: rde_prefix.c,v 1.29 2009/05/30 18:27:17 claudio Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Claudio Jeker <claudio@openbsd.org>
@@ -40,46 +40,30 @@
  * pt_init:   initialize prefix table.
  * pt_alloc?: allocate a AF specific pt_entry. Internal function.
  * pt_free:   free a pt_entry. Internal function.
- * pt_restart used to restart a tree walk at the spot it was aborted earlier.
  */
 
 /* internal prototypes */
 static struct pt_entry4	*pt_alloc4(void);
 static struct pt_entry6	*pt_alloc6(void);
 static void		 pt_free(struct pt_entry *);
-static struct pt_entry	*pt_restart(struct pt_context *);
 
-int	pt_prefix_cmp(const struct pt_entry *, const struct pt_entry *);
-
-#define MIN_PREFIX 0
-#define MAX_PREFIX 32
 RB_HEAD(pt_tree, pt_entry);
 RB_PROTOTYPE(pt_tree, pt_entry, pt_e, pt_prefix_cmp);
 RB_GENERATE(pt_tree, pt_entry, pt_e, pt_prefix_cmp);
 
-struct pt_tree	pttable4;
-struct pt_tree	pttable6;
+struct pt_tree	pttable;
 
 void
 pt_init(void)
 {
-	RB_INIT(&pttable4);
-	RB_INIT(&pttable6);
+	RB_INIT(&pttable);
 }
 
 void
 pt_shutdown(void)
 {
-	if (!RB_EMPTY(&pttable4))
-		log_debug("pt_shutdown: IPv4 tree is not empty.");
-	if (!RB_EMPTY(&pttable6))
-		log_debug("pt_shutdown: IPv6 tree is not empty.");
-}
-
-int
-pt_empty(struct pt_entry *pte)
-{
-	return LIST_EMPTY(&pte->prefix_h);
+	if (!RB_EMPTY(&pttable))
+		log_debug("pt_shutdown: tree is not empty.");
 }
 
 void
@@ -103,14 +87,15 @@ pt_getaddr(struct pt_entry *pte, struct 
 }
 
 struct pt_entry *
-pt_get(struct bgpd_addr *prefix, int prefixlen)
+pt_fill(struct bgpd_addr *prefix, int prefixlen)
 {
-	struct pt_entry4	pte4;
-	struct pt_entry6	pte6;
+	static struct pt_entry4	pte4;
+	static struct pt_entry6	pte6;
 	in_addr_t		addr_hbo;
 
 	switch (prefix->af) {
 	case AF_INET:
+		bzero(&pte4, sizeof(pte4));
 		if (prefixlen > 32)
 			fatalx("pt_get: bad IPv4 prefixlen");
 		pte4.af = AF_INET;
@@ -118,24 +103,33 @@ pt_get(struct bgpd_addr *prefix, int pre
 		pte4.prefix4.s_addr = htonl(addr_hbo &
 		    prefixlen2mask(prefixlen));
 		pte4.prefixlen = prefixlen;
-		return RB_FIND(pt_tree, &pttable4, (struct pt_entry *)&pte4);
+		return ((struct pt_entry *)&pte4);
 	case AF_INET6:
+		bzero(&pte6, sizeof(pte6));
 		if (prefixlen > 128)
 			fatalx("pt_get: bad IPv6 prefixlen");
 		pte6.af = AF_INET6;
 		pte6.prefixlen = prefixlen;
 		inet6applymask(&pte6.prefix6, &prefix->v6, prefixlen);
-		return RB_FIND(pt_tree, &pttable6, (struct pt_entry *)&pte6);
+		return ((struct pt_entry *)&pte6);
 	default:
 		log_warnx("pt_get: unknown af");
+		return (NULL);
 	}
-	return (NULL);
+}
+
+struct pt_entry *
+pt_get(struct bgpd_addr *prefix, int prefixlen)
+{
+	struct pt_entry	*pte;
+
+	pte = pt_fill(prefix, prefixlen);
+	return RB_FIND(pt_tree, &pttable, pte);
 }
 
 struct pt_entry *
 pt_add(struct bgpd_addr *prefix, int prefixlen)
 {
-	struct pt_tree		*tree = NULL;
 	struct pt_entry		*p = NULL;
 	struct pt_entry4	*p4;
 	struct pt_entry6	*p6;
@@ -152,7 +146,6 @@ pt_add(struct bgpd_addr *prefix, int pre
 		p4->prefix4.s_addr = htonl(addr_hbo &
 		    prefixlen2mask(prefixlen));
 		p = (struct pt_entry *)p4;
-		tree = &pttable4;
 		break;
 	case AF_INET6:
 		p6 = pt_alloc6();
@@ -162,15 +155,13 @@ pt_add(struct bgpd_addr *prefix, int pre
 		p6->prefixlen = prefixlen;
 		inet6applymask(&p6->prefix6, &prefix->v6, prefixlen);
 		p = (struct pt_entry *)p6;
-		tree = &pttable6;
 		break;
 	default:
 		fatalx("pt_add: unknown af");
 	}
-	LIST_INIT(&p->prefix_h);
 
-	if (RB_INSERT(pt_tree, tree, p) != NULL) {
-		log_warnx("prefix_add: insert failed");
+	if (RB_INSERT(pt_tree, &pttable, p) != NULL) {
+		log_warnx("pt_add: insert failed");
 		return (NULL);
 	}
 
@@ -181,101 +172,35 @@ void
 pt_remove(struct pt_entry *pte)
 {
 	if (!pt_empty(pte))
-		fatalx("pt_remove: entry not empty");
-
-	switch (pte->af) {
-	case AF_INET:
-		if (RB_REMOVE(pt_tree, &pttable4, pte) == NULL)
-			log_warnx("pt_remove: remove failed.");
-		break;
-	case AF_INET6:
-		if (RB_REMOVE(pt_tree, &pttable6, pte) == NULL)
-			log_warnx("pt_remove: remove failed.");
-		break;
-	default:
-		fatalx("pt_remove: unknown af");
-	}
+		fatalx("pt_remove: entry still holds references");
 
+	if (RB_REMOVE(pt_tree, &pttable, pte) == NULL)
+		log_warnx("pt_remove: remove failed.");
 	pt_free(pte);
 }
 
 struct pt_entry *
-pt_lookup(struct bgpd_addr *prefix)
+pt_lookup(struct bgpd_addr *addr)
 {
 	struct pt_entry	*p;
 	int		 i;
 
-	switch (prefix->af) {
+	switch (addr->af) {
 	case AF_INET:
-		for (i = 32; i >= 0; i--) {
-			p = pt_get(prefix, i);
-			if (p != NULL)
-				return (p);
-		}
+		i = 32;
 		break;
 	case AF_INET6:
-		for (i = 128; i >= 0; i--) {
-			p = pt_get(prefix, i);
-			if (p != NULL)
-				return (p);
-		}
+		i = 128;
 		break;
 	default:
 		fatalx("pt_lookup: unknown af");
 	}
-	return (NULL);
-}
-
-void
-pt_dump(void (*upcall)(struct pt_entry *, void *), void *arg, sa_family_t af)
-{
-	if (af == AF_INET || af == AF_UNSPEC)
-		pt_dump_r(upcall, arg, AF_INET, NULL);
-	if (af == AF_INET6 || af == AF_UNSPEC)
-		pt_dump_r(upcall, arg, AF_INET6, NULL);
-}
-
-void
-pt_dump_r(void (*upcall)(struct pt_entry *, void *), void *arg,
-    sa_family_t af, struct pt_context *ctx)
-{
-	struct pt_entry	*p;
-	unsigned int	 i;
-
-	if (ctx == NULL || ctx->ctx_p.af != af) {
-		switch (af) {
-		case AF_INET:
-			p = RB_MIN(pt_tree, &pttable4);
-			break;
-		case AF_INET6:
-			p = RB_MIN(pt_tree, &pttable6);
-			break;
-		default:
-			return;
-		}
-	} else
-		p = pt_restart(ctx);
-
-	for (i = 0; p != NULL; p = RB_NEXT(pt_tree, unused, p)) {
-		if (ctx && i++ >= ctx->count) {
-			/* store next start point */
-			switch (p->af) {
-			case AF_INET:
-				ctx->ctx_p4 = *(struct pt_entry4 *)p;
-				break;
-			case AF_INET6:
-				ctx->ctx_p6 = *(struct pt_entry6 *)p;
-				break;
-			default:
-				fatalx("pt_dump_r: unknown af");
-			}
-			return;
-		}
-		upcall(p, arg);
+	for (; i >= 0; i--) {
+		p = pt_get(addr, i);
+		if (p != NULL)
+			return (p);
 	}
-
-	if (ctx)
-		ctx->done = 1;
+	return (NULL);
 }
 
 int
@@ -285,8 +210,10 @@ pt_prefix_cmp(const struct pt_entry *a, 
 	const struct pt_entry6	*a6, *b6;
 	int			 i;
 
-	if (a->af != b->af)
-		fatalx("king bula sez: comparing pears with apples");
+	if (a->af > b->af)
+		return (1);
+	if (a->af < b->af)
+		return (-1);
 
 	switch (a->af) {
 	case AF_INET:
@@ -361,56 +288,3 @@ pt_free(struct pt_entry *pte)
 	}
 	free(pte);
 }
-
-static struct pt_entry *
-pt_restart(struct pt_context *ctx)
-{
-	struct pt_entry *tmp, *prev = NULL;
-	int comp;
-
-	/* first select correct tree */
-	switch (ctx->ctx_p.af) {
-	case AF_INET:
-		tmp = RB_ROOT(&pttable4);
-		break;
-	case AF_INET6:
-		tmp = RB_ROOT(&pttable6);
-		break;
-	default:
-		fatalx("pt_restart: unknown af");
-	}
-
-	/* then try to find the element */
-	while (tmp) {
-		prev = tmp;
-		comp = pt_prefix_cmp(&ctx->ctx_p, tmp);
-		if (comp < 0)
-			tmp = RB_LEFT(tmp, pt_e);
-		else if (comp > 0)
-			tmp = RB_RIGHT(tmp, pt_e);
-		else
-			return (tmp);
-	}
-
-	/* no match, empty tree */
-	if (prev == NULL)
-		return (NULL);
-
-	/*
-	 * no perfect match
-	 * if last element was bigger use that as new start point
-	 */
-	if (comp < 0)
-		return (prev);
-
-	/* backtrack until parent is bigger */
-	do {
-		prev = RB_PARENT(prev, pt_e);
-		if (prev == NULL)
-			/* all elements in the tree are smaler */
-			return (NULL);
-		comp = pt_prefix_cmp(&ctx->ctx_p, prev);
-	} while (comp > 0);
-
-	return (prev);
-}
