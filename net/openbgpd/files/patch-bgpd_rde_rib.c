Index: bgpd/rde_rib.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/rde_rib.c,v
retrieving revision 1.1.1.1
retrieving revision 1.3
diff -u -p -r1.1.1.1 -r1.3
--- bgpd/rde_rib.c	30 Jun 2009 05:46:15 -0000	1.1.1.1
+++ bgpd/rde_rib.c	9 Jul 2009 17:22:14 -0000	1.3
@@ -1,4 +1,4 @@
-/*	$OpenBSD: rde_rib.c,v 1.96 2007/06/01 04:17:30 claudio Exp $ */
+/*	$OpenBSD: rde_rib.c,v 1.116 2009/06/29 14:13:48 claudio Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Claudio Jeker <claudio@openbsd.org>
@@ -18,7 +18,11 @@
 
 #include <sys/types.h>
 #include <sys/queue.h>
+#if defined(__FreeBSD__)	/* sys/hash.h */
+#include "hash.h"
+#else
 #include <sys/hash.h>
+#endif /* defined(__FreeBSD__) */
 
 #include <stdlib.h>
 #include <string.h>
@@ -33,14 +37,312 @@
  * Therefore one thing needs to be absolutely avoided, long table walks.
  * This is achieved by heavily linking the different parts together.
  */
+u_int16_t rib_size;
+struct rib *ribs;
+
+LIST_HEAD(, rib_context) rib_dump_h = LIST_HEAD_INITIALIZER(rib_dump_h);
+
+struct rib_entry *rib_add(struct rib *, struct bgpd_addr *, int);
+int rib_compare(const struct rib_entry *, const struct rib_entry *);
+void rib_remove(struct rib_entry *);
+int rib_empty(struct rib_entry *);
+struct rib_entry *rib_restart(struct rib_context *);
+
+RB_PROTOTYPE(rib_tree, rib_entry, rib_e, rib_compare);
+RB_GENERATE(rib_tree, rib_entry, rib_e, rib_compare);
+
+
+/* RIB specific functions */
+u_int16_t
+rib_new(int id, char *name, u_int16_t flags)
+{
+	struct rib	*xribs;
+	size_t		newsize;
+
+	if (id < 0) {
+		for (id = 0; id < rib_size; id++) {
+			if (*ribs[id].name == '\0')
+				break;
+		}
+	}
+
+	if (id == RIB_FAILED)
+		fatalx("rib_new: trying to use reserved id");
+
+	if (id >= rib_size) {
+		newsize = sizeof(struct rib) * (id + 1);
+		if ((xribs = realloc(ribs, newsize)) == NULL) {
+			/* XXX this is not clever */
+			fatal("rib_add");
+		}
+		ribs = xribs;
+		rib_size = id + 1;
+	}
+
+	bzero(&ribs[id], sizeof(struct rib));
+	strlcpy(ribs[id].name, name, sizeof(ribs[id].name));
+	RB_INIT(&ribs[id].rib);
+	ribs[id].state = RIB_ACTIVE;
+	ribs[id].id = id;
+	ribs[id].flags = flags;
+
+	return (id);
+}
+
+u_int16_t
+rib_find(char *name)
+{
+	u_int16_t id;
+
+	if (name == NULL || *name == '\0')
+		return (1);	/* XXX */
+
+	for (id = 0; id < rib_size; id++) {
+		if (!strcmp(ribs[id].name, name))
+			return (id);
+	}
+
+	return (RIB_FAILED);
+}
+
+void
+rib_free(struct rib *rib)
+{
+	struct rib_context *ctx, *next;
+	struct rib_entry *re, *xre;
+	struct prefix *p, *np;
+
+	for (ctx = LIST_FIRST(&rib_dump_h); ctx != NULL; ctx = next) {
+		next = LIST_NEXT(ctx, entry);
+		if (ctx->ctx_rib == rib) {
+			re = ctx->ctx_re;
+			re->flags &= ~F_RIB_ENTRYLOCK;
+			LIST_REMOVE(ctx, entry);
+			if (ctx->ctx_done)
+				ctx->ctx_done(ctx->ctx_arg);
+			else
+				free(ctx);
+		}
+	}
+
+	for (re = RB_MIN(rib_tree, &rib->rib); re != NULL; re = xre) {
+		xre = RB_NEXT(rib_tree,  &rib->rib, re);
+
+		/*
+		 * Removing the prefixes is tricky because the last one
+		 * will remove the rib_entry as well and at because we do
+		 * a empty check in prefix_destroy() it is not possible to
+		 * use the default for loop.
+		 */
+		while ((p = LIST_FIRST(&re->prefix_h))) {
+			np = LIST_NEXT(p, rib_l);
+			if (p->aspath->pftableid) {
+				struct bgpd_addr addr;
+
+				pt_getaddr(p->prefix, &addr);
+				/* Commit is done in peer_down() */
+				rde_send_pftable(p->aspath->pftableid, &addr,
+				    p->prefix->prefixlen, 1);
+			}
+			prefix_destroy(p);
+			if (np == NULL)
+				break;
+		}
+	}
+	bzero(rib, sizeof(struct rib));
+}
+
+int
+rib_compare(const struct rib_entry *a, const struct rib_entry *b)
+{
+	return (pt_prefix_cmp(a->prefix, b->prefix));
+}
+
+struct rib_entry *
+rib_get(struct rib *rib, struct bgpd_addr *prefix, int prefixlen)
+{
+	struct rib_entry xre;
+	struct pt_entry	*pte;
+
+	pte = pt_fill(prefix, prefixlen);
+	bzero(&xre, sizeof(xre));
+	xre.prefix = pte;
+
+	return (RB_FIND(rib_tree, &rib->rib, &xre));
+}
+
+struct rib_entry *
+rib_lookup(struct rib *rib, struct bgpd_addr *addr)
+{
+	struct rib_entry *re;
+	int		 i;
+
+	switch (addr->af) {
+	case AF_INET:
+		for (i = 32; i >= 0; i--) {
+			re = rib_get(rib, addr, i);
+			if (re != NULL)
+				return (re);
+		}
+		break;
+	case AF_INET6:
+		for (i = 128; i >= 0; i--) {
+			re = rib_get(rib, addr, i);
+			if (re != NULL)
+				return (re);
+		}
+		break;
+	default:
+		fatalx("rib_lookup: unknown af");
+	}
+	return (NULL);
+}
+
+
+struct rib_entry *
+rib_add(struct rib *rib, struct bgpd_addr *prefix, int prefixlen)
+{
+	struct pt_entry	*pte;
+	struct rib_entry *re;
+
+	pte = pt_get(prefix, prefixlen);
+	if (pte == NULL)
+		pte = pt_add(prefix, prefixlen);
+
+	if ((re = calloc(1, sizeof(*re))) == NULL)
+		fatal("rib_add");
+
+	LIST_INIT(&re->prefix_h);
+	re->prefix = pte;
+	re->flags = rib->flags;
+	re->ribid = rib->id;
+
+        if (RB_INSERT(rib_tree, &rib->rib, re) != NULL) {
+		log_warnx("rib_add: insert failed");
+		return (NULL);
+	}
+
+	pt_ref(pte);
+
+	rdemem.rib_cnt++;
+
+	return (re);
+}
+
+void
+rib_remove(struct rib_entry *re)
+{
+	if (!rib_empty(re))
+		fatalx("rib_remove: entry not empty");
+
+	if (re->flags & F_RIB_ENTRYLOCK)
+		/* entry is locked, don't free it. */
+		return;
+
+	pt_unref(re->prefix);
+	if (pt_empty(re->prefix))
+		pt_remove(re->prefix);
+
+	if (RB_REMOVE(rib_tree, &ribs[re->ribid].rib, re) == NULL)
+		log_warnx("rib_remove: remove failed.");
+
+	free(re);
+	rdemem.rib_cnt--;
+}
+
+int
+rib_empty(struct rib_entry *re)
+{
+	return LIST_EMPTY(&re->prefix_h);
+}
+
+void
+rib_dump(struct rib *rib, void (*upcall)(struct rib_entry *, void *),
+    void *arg, sa_family_t af)
+{
+	struct rib_context	*ctx;
+
+	if ((ctx = calloc(1, sizeof(*ctx))) == NULL)
+		fatal("rib_dump");
+	ctx->ctx_rib = rib;
+	ctx->ctx_upcall = upcall;
+	ctx->ctx_arg = arg;
+	ctx->ctx_af = af;
+	rib_dump_r(ctx);
+}
+
+void
+rib_dump_r(struct rib_context *ctx)
+{
+	struct rib_entry	*re;
+	unsigned int		 i;
+
+	if (ctx->ctx_re == NULL) {
+		re = RB_MIN(rib_tree, &ctx->ctx_rib->rib);
+		LIST_INSERT_HEAD(&rib_dump_h, ctx, entry);
+	} else
+		re = rib_restart(ctx);
+
+	for (i = 0; re != NULL; re = RB_NEXT(rib_tree, unused, re)) {
+		if (ctx->ctx_af != AF_UNSPEC && ctx->ctx_af != re->prefix->af)
+			continue;
+		if (ctx->ctx_count && i++ >= ctx->ctx_count &&
+		    (re->flags & F_RIB_ENTRYLOCK) == 0) {
+			/* store and lock last element */
+			ctx->ctx_re = re;
+			re->flags |= F_RIB_ENTRYLOCK;
+			return;
+		}
+		ctx->ctx_upcall(re, ctx->ctx_arg);
+	}
+
+	LIST_REMOVE(ctx, entry);
+	if (ctx->ctx_done)
+		ctx->ctx_done(ctx->ctx_arg);
+	else
+		free(ctx);
+}
+
+struct rib_entry *
+rib_restart(struct rib_context *ctx)
+{
+	struct rib_entry *re;
+
+	re = ctx->ctx_re;
+	re->flags &= ~F_RIB_ENTRYLOCK;
+
+	/* find first non empty element */
+	while (rib_empty(re))
+		re = RB_NEXT(rib_tree, unused, re);
+
+	/* free the previously locked rib element if empty */
+	if (rib_empty(ctx->ctx_re))
+		rib_remove(ctx->ctx_re);
+	ctx->ctx_re = NULL;
+	return (re);
+}
+
+void
+rib_dump_runner(void)
+{
+	struct rib_context	*ctx, *next;
+
+	for (ctx = LIST_FIRST(&rib_dump_h); ctx != NULL; ctx = next) {
+		next = LIST_NEXT(ctx, entry);
+		rib_dump_r(ctx);
+	}
+}
+
+int
+rib_dump_pending(void)
+{
+	return (!LIST_EMPTY(&rib_dump_h));
+}
 
 /* used to bump correct prefix counters */
-#define PREFIX_COUNT(x, f, op)				\
-	do {						\
-		if (f & F_LOCAL)			\
-			(x)->prefix_cnt += (op);	\
-		if (f & F_ORIGINAL)			\
-			(x)->adjrib_cnt += (op);	\
+#define PREFIX_COUNT(x, op)			\
+	do {					\
+		(x)->prefix_cnt += (op);	\
 	} while (0)
 
 /* path specific functions */
@@ -83,62 +385,29 @@ path_shutdown(void)
 	free(pathtable.path_hashtbl);
 }
 
-void
-path_update(struct rde_peer *peer, struct rde_aspath *nasp,
-    struct bgpd_addr *prefix, int prefixlen, u_int32_t flags)
+int
+path_update(struct rib *rib, struct rde_peer *peer, struct rde_aspath *nasp,
+    struct bgpd_addr *prefix, int prefixlen)
 {
 	struct rde_aspath	*asp;
-	struct prefix		*p, *oldp = NULL;
+	struct prefix		*p;
 
-	if (flags & F_LOCAL) {
+	if (nasp->pftableid) {
 		rde_send_pftable(nasp->pftableid, prefix, prefixlen, 0);
 		rde_send_pftable_commit();
 	}
 
 	/*
-	 * First try to find a prefix in the specified RIB or in the
-	 * Adj-RIB-In. This works because Local-RIB has precedence over the
-	 * Adj-RIB-In. In the end this saves use some additional lookups.
+	 * First try to find a prefix in the specified RIB.
 	 */
-	if ((p = prefix_get(peer, prefix, prefixlen, flags | F_ORIGINAL)) !=
-	    NULL) {
-		do {
-			if (path_compare(nasp, p->aspath) == 0) {
-				if ((p->flags & flags) == 0) {
-					if (oldp != NULL) {
-						asp = oldp->aspath;
-						prefix_destroy(oldp);
-						if (path_empty(asp))
-							path_destroy(asp);
-					}
-					p->flags |= flags;
-					PREFIX_COUNT(p->aspath, flags, 1);
-					PREFIX_COUNT(peer, flags, 1);
-
-					/* re-evaluate prefix */
-					LIST_REMOVE(p, prefix_l);
-					prefix_evaluate(p, p->prefix);
-				}
-				/* update last change */
-				p->lastchange = time(NULL);
-				return;
-			}
-			/*
-			 * If the prefix is not already part of the Adj-RIB-In
-			 * do a lookup in there. But keep the original prefix
-			 * around so that it can be removed later.
-			 */
-			if (p->flags & F_ORIGINAL)
-				break;
-			oldp = p;
-			p = prefix_get(peer, prefix, prefixlen, F_ORIGINAL);
-		} while (p != NULL);
+	if ((p = prefix_get(rib, peer, prefix, prefixlen, 0)) != NULL) {
+		if (path_compare(nasp, p->aspath) == 0) {
+			/* no change, update last change */
+			p->lastchange = time(NULL);
+			return (0);
+		}
 	}
 
-	/* Do not try to move a prefix that is in the wrong RIB. */
-	if (p == NULL || (p->flags & flags) == 0)
-		p = oldp;
-
 	/*
 	 * Either the prefix does not exist or the path changed.
 	 * In both cases lookup the new aspath to make sure it is not
@@ -152,9 +421,10 @@ path_update(struct rde_peer *peer, struc
 
 	/* If the prefix was found move it else add it to the aspath. */
 	if (p != NULL)
-		prefix_move(asp, p, flags);
+		prefix_move(asp, p);
 	else
-		prefix_add(asp, prefix, prefixlen, flags);
+		return (prefix_add(rib, asp, prefix, prefixlen));
+	return (0);
 }
 
 int
@@ -220,19 +490,20 @@ path_lookup(struct rde_aspath *aspath, s
 void
 path_remove(struct rde_aspath *asp)
 {
-	struct prefix	*p;
-	struct bgpd_addr addr;
+	struct prefix	*p, *np;
 
-	while ((p = LIST_FIRST(&asp->prefix_h)) != NULL) {
-		/* Commit is done in peer_down() */
-		pt_getaddr(p->prefix, &addr);
-		if (p->flags & F_LOCAL)
+	for (p = LIST_FIRST(&asp->prefix_h); p != NULL; p = np) {
+		np = LIST_NEXT(p, path_l);
+		if (asp->pftableid) {
+			struct bgpd_addr addr;
+
+			pt_getaddr(p->prefix, &addr);
+			/* Commit is done in peer_down() */
 			rde_send_pftable(p->aspath->pftableid, &addr,
 			    p->prefix->prefixlen, 1);
-
+		}
 		prefix_destroy(p);
 	}
-	path_destroy(asp);
 }
 
 /* this function is only called by prefix_remove and path_remove */
@@ -240,8 +511,7 @@ void
 path_destroy(struct rde_aspath *asp)
 {
 	/* path_destroy can only unlink and free empty rde_aspath */
-	if (asp->prefix_cnt != 0 || asp->active_cnt != 0 ||
-	    asp->adjrib_cnt != 0)
+	if (asp->prefix_cnt != 0 || asp->active_cnt != 0)
 		log_warnx("path_destroy: prefix count out of sync");
 
 	nexthop_unlink(asp);
@@ -354,8 +624,8 @@ path_put(struct rde_aspath *asp)
 
 static struct prefix	*prefix_alloc(void);
 static void		 prefix_free(struct prefix *);
-static void		 prefix_link(struct prefix *, struct pt_entry *,
-			     struct rde_aspath *, u_int32_t);
+static void		 prefix_link(struct prefix *, struct rib_entry *,
+			     struct rde_aspath *);
 static void		 prefix_unlink(struct prefix *);
 
 int
@@ -404,51 +674,52 @@ prefix_compare(const struct bgpd_addr *a
  * search for specified prefix of a peer. Returns NULL if not found.
  */
 struct prefix *
-prefix_get(struct rde_peer *peer, struct bgpd_addr *prefix, int prefixlen,
-    u_int32_t flags)
+prefix_get(struct rib *rib, struct rde_peer *peer, struct bgpd_addr *prefix,
+    int prefixlen, u_int32_t flags)
 {
-	struct pt_entry	*pte;
+	struct rib_entry	*re;
 
-	pte = pt_get(prefix, prefixlen);
-	if (pte == NULL)
+	re = rib_get(rib, prefix, prefixlen);
+	if (re == NULL)
 		return (NULL);
-	return (prefix_bypeer(pte, peer, flags));
+	return (prefix_bypeer(re, peer, flags));
 }
 
 /*
  * Adds or updates a prefix.
  */
-struct pt_entry *
-prefix_add(struct rde_aspath *asp, struct bgpd_addr *prefix, int prefixlen,
-    u_int32_t flags)
+int
+prefix_add(struct rib *rib, struct rde_aspath *asp, struct bgpd_addr *prefix,
+    int prefixlen)
 
 {
-	struct prefix	*p;
-	struct pt_entry	*pte;
+	struct prefix		*p;
+	struct rib_entry	*re;
 
-	pte = pt_get(prefix, prefixlen);
-	if (pte == NULL)
-		pte = pt_add(prefix, prefixlen);
+	re = rib_get(rib, prefix, prefixlen);
+	if (re == NULL)
+		re = rib_add(rib, prefix, prefixlen);
 
-	p = prefix_bypeer(pte, asp->peer, flags);
+	p = prefix_bypeer(re, asp->peer, asp->flags);
 	if (p == NULL) {
 		p = prefix_alloc();
-		prefix_link(p, pte, asp, flags);
+		prefix_link(p, re, asp);
+		return (1);
 	} else {
-		if (p->aspath != asp)
+		if (p->aspath != asp) {
 			/* prefix belongs to a different aspath so move */
-			return (prefix_move(asp, p, flags));
-		p->lastchange = time(NULL);
+			prefix_move(asp, p);
+		} else
+			p->lastchange = time(NULL);
+		return (0);
 	}
-
-	return (pte);
 }
 
 /*
  * Move the prefix to the specified as path, removes the old asp if needed.
  */
-struct pt_entry *
-prefix_move(struct rde_aspath *asp, struct prefix *p, u_int32_t flags)
+void
+prefix_move(struct rde_aspath *asp, struct prefix *p)
 {
 	struct prefix		*np;
 	struct rde_aspath	*oasp;
@@ -461,45 +732,18 @@ prefix_move(struct rde_aspath *asp, stru
 	np->aspath = asp;
 	/* peer and prefix pointers are still equal */
 	np->prefix = p->prefix;
+	np->rib = p->rib;
 	np->lastchange = time(NULL);
-	np->flags = flags;
 
 	/* add to new as path */
 	LIST_INSERT_HEAD(&asp->prefix_h, np, path_l);
-	PREFIX_COUNT(asp, flags, 1);
+	PREFIX_COUNT(asp, 1);
 	/*
 	 * no need to update the peer prefix count because we are only moving
 	 * the prefix without changing the peer.
 	 */
 
 	/*
-	 * fiddle around with the flags. If the p->flags is not equal
-	 * to flags the old prefix p may not be removed but instead p->flags
-	 * needs to be adjusted.
-	 */
-	if (p->flags != flags) {
-		if ((p->flags & flags) == 0)
-			fatalx("prefix_move: "
-			    "prefix is not part of desired RIB");
-
-		p->flags &= ~flags;
-		PREFIX_COUNT(p->aspath, flags, -1);
-		/* as before peer count needs no update because of move */
-
-		/* redo the route decision for p */
-		LIST_REMOVE(p, prefix_l);
-		/* If the prefix is the active one remove it first. */
-		if (p == p->prefix->active)
-			prefix_evaluate(NULL, p->prefix);
-		prefix_evaluate(p, p->prefix);
-
-		/* and now for np */
-		prefix_evaluate(np, np->prefix);
-
-		return (np->prefix);
-	}
-
-	/*
 	 * First kick the old prefix node out of the prefix list,
 	 * afterwards run the route decision for new prefix node.
 	 * Because of this only one update is generated if the prefix
@@ -507,78 +751,57 @@ prefix_move(struct rde_aspath *asp, stru
 	 * This is save because we create a new prefix and so the change
 	 * is noticed by prefix_evaluate().
 	 */
-	LIST_REMOVE(p, prefix_l);
-	prefix_evaluate(np, np->prefix);
+	LIST_REMOVE(p, rib_l);
+	prefix_evaluate(np, np->rib);
 
 	/* remove old prefix node */
 	oasp = p->aspath;
 	LIST_REMOVE(p, path_l);
-	PREFIX_COUNT(oasp, flags, -1);
+	PREFIX_COUNT(oasp, -1);
 	/* as before peer count needs no update because of move */
 
 	/* destroy all references to other objects and free the old prefix */
 	p->aspath = NULL;
 	p->prefix = NULL;
+	p->rib = NULL;
 	prefix_free(p);
 
 	/* destroy old path if empty */
 	if (path_empty(oasp))
 		path_destroy(oasp);
-
-	return (np->prefix);
 }
 
 /*
  * Removes a prefix from all lists. If the parent objects -- path or
  * pt_entry -- become empty remove them too.
  */
-void
-prefix_remove(struct rde_peer *peer, struct bgpd_addr *prefix, int prefixlen,
-    u_int32_t flags)
+int
+prefix_remove(struct rib *rib, struct rde_peer *peer, struct bgpd_addr *prefix,
+    int prefixlen, u_int32_t flags)
 {
 	struct prefix		*p;
-	struct pt_entry		*pte;
+	struct rib_entry	*re;
 	struct rde_aspath	*asp;
 
-	pte = pt_get(prefix, prefixlen);
-	if (pte == NULL)	/* Got a dummy withdrawn request */
-		return;
+	re = rib_get(rib, prefix, prefixlen);
+	if (re == NULL)	/* Got a dummy withdrawn request */
+		return (0);
 
-	p = prefix_bypeer(pte, peer, flags);
+	p = prefix_bypeer(re, peer, flags);
 	if (p == NULL)		/* Got a dummy withdrawn request. */
-		return;
+		return (0);
 
 	asp = p->aspath;
 
-	if (p->flags & F_LOCAL) {
+	if (asp->pftableid) {
 		/* only prefixes in the local RIB were pushed into pf */
 		rde_send_pftable(asp->pftableid, prefix, prefixlen, 1);
 		rde_send_pftable_commit();
 	}
 
-	/* if prefix belongs to more than one RIB just remove one instance */
-	if (p->flags != flags) {
-		p->flags &= ~flags;
-
-		PREFIX_COUNT(p->aspath, flags, -1);
-		PREFIX_COUNT(peer, flags, -1);
-
-		/* redo the route decision for p */
-		LIST_REMOVE(p, prefix_l);
-		/* If the prefix is the active one remove it first. */
-		if (p == p->prefix->active)
-			prefix_evaluate(NULL, p->prefix);
-		prefix_evaluate(p, p->prefix);
-		return;
-	}
-
-	prefix_unlink(p);
-	prefix_free(p);
+	prefix_destroy(p);
 
-	if (pt_empty(pte))
-		pt_remove(pte);
-	if (path_empty(asp))
-		path_destroy(asp);
+	return (1);
 }
 
 /* dump a prefix into specified buffer */
@@ -604,36 +827,50 @@ prefix_write(u_char *buf, int len, struc
  * belonging to the peer peer. Returns NULL if no match found.
  */
 struct prefix *
-prefix_bypeer(struct pt_entry *pte, struct rde_peer *peer, u_int32_t flags)
+prefix_bypeer(struct rib_entry *re, struct rde_peer *peer, u_int32_t flags)
 {
 	struct prefix	*p;
 
-	LIST_FOREACH(p, &pte->prefix_h, prefix_l) {
-		if (p->aspath->peer == peer && p->flags & flags)
-			return (p);
+	LIST_FOREACH(p, &re->prefix_h, rib_l) {
+		if (p->aspath->peer != peer)
+			continue;
+		if (p->aspath->flags & flags &&
+		    (flags & F_ANN_DYNAMIC) !=
+		    (p->aspath->flags & F_ANN_DYNAMIC))
+			continue;
+		return (p);
 	}
 	return (NULL);
 }
 
 void
-prefix_updateall(struct rde_aspath *asp, enum nexthop_state state)
+prefix_updateall(struct rde_aspath *asp, enum nexthop_state state,
+    enum nexthop_state oldstate)
 {
 	struct prefix	*p;
 
-	if (rde_noevaluate())
-		/* if the decision process is turned off this is a no-op */
-		return;
-
 	LIST_FOREACH(p, &asp->prefix_h, path_l) {
 		/*
-		 * skip non local-RIB nodes, only local-RIB prefixes are
-		 * eligible. Both F_LOCAL and F_ORIGINAL may be set.
+		 * skip non local-RIBs or RIBs that are flagged as noeval.
 		 */
-		if (!(p->flags & F_LOCAL))
+		if (p->rib->flags & F_RIB_NOEVALUATE)
 			continue;
 
+		if (oldstate == state && state == NEXTHOP_REACH) {
+			/*
+			 * The state of the nexthop did not change. The only
+			 * thing that may have changed is the true_nexthop
+			 * or other internal infos. This will not change
+			 * the routing decision so shortcut here.
+			 */
+			if ((p->rib->flags & F_RIB_NOFIB) == 0 &&
+			    p == p->rib->active)
+				rde_send_kroute(p, NULL);
+			continue;
+		}
+
 		/* redo the route decision */
-		LIST_REMOVE(p, prefix_l);
+		LIST_REMOVE(p, rib_l);
 		/*
 		 * If the prefix is the active one remove it first,
 		 * this has to be done because we can not detect when
@@ -642,31 +879,35 @@ prefix_updateall(struct rde_aspath *asp,
 		 * prefix_evaluate() will generate no update because
 		 * the nexthop is unreachable or ineligible.
 		 */
-		if (p == p->prefix->active)
-			prefix_evaluate(NULL, p->prefix);
-		prefix_evaluate(p, p->prefix);
+		if (p == p->rib->active)
+			prefix_evaluate(NULL, p->rib);
+		prefix_evaluate(p, p->rib);
 	}
 }
 
-/* kill a prefix. Only called by path_remove and path_update. */
+/* kill a prefix. */
 void
 prefix_destroy(struct prefix *p)
 {
-	struct pt_entry		*pte;
+	struct rib_entry	*re;
+	struct rde_aspath	*asp;
 
-	pte = p->prefix;
+	re = p->rib;
+	asp = p->aspath;
 	prefix_unlink(p);
 	prefix_free(p);
 
-	if (pt_empty(pte))
-		pt_remove(pte);
+	if (rib_empty(re))
+		rib_remove(re);
+	if (path_empty(asp))
+		path_destroy(asp);
 }
 
 /*
  * helper function to clean up the connected networks after a reload
  */
 void
-prefix_network_clean(struct rde_peer *peer, time_t reloadtime)
+prefix_network_clean(struct rde_peer *peer, time_t reloadtime, u_int32_t flags)
 {
 	struct rde_aspath	*asp, *xasp;
 	struct prefix		*p, *xp;
@@ -674,6 +915,8 @@ prefix_network_clean(struct rde_peer *pe
 
 	for (asp = LIST_FIRST(&peer->path_h); asp != NULL; asp = xasp) {
 		xasp = LIST_NEXT(asp, peer_l);
+		if ((asp->flags & F_ANN_DYNAMIC) == flags)
+			continue;
 		for (p = LIST_FIRST(&asp->prefix_h); p != NULL; p = xp) {
 			xp = LIST_NEXT(p, path_l);
 			if (reloadtime > p->lastchange) {
@@ -694,20 +937,19 @@ prefix_network_clean(struct rde_peer *pe
  * Link a prefix into the different parent objects.
  */
 static void
-prefix_link(struct prefix *pref, struct pt_entry *pte, struct rde_aspath *asp,
-    u_int32_t flags)
+prefix_link(struct prefix *pref, struct rib_entry *re, struct rde_aspath *asp)
 {
 	LIST_INSERT_HEAD(&asp->prefix_h, pref, path_l);
-	PREFIX_COUNT(asp, flags, 1);
-	PREFIX_COUNT(asp->peer, flags, 1);
+	PREFIX_COUNT(asp, 1);
 
 	pref->aspath = asp;
-	pref->prefix = pte;
+	pref->rib = re;
+	pref->prefix = re->prefix;
+	pt_ref(pref->prefix);
 	pref->lastchange = time(NULL);
-	pref->flags = flags;
 
 	/* make route decision */
-	prefix_evaluate(pref, pte);
+	prefix_evaluate(pref, re);
 }
 
 /*
@@ -716,17 +958,23 @@ prefix_link(struct prefix *pref, struct 
 static void
 prefix_unlink(struct prefix *pref)
 {
-	/* make route decision */
-	LIST_REMOVE(pref, prefix_l);
-	prefix_evaluate(NULL, pref->prefix);
+	if (pref->rib) {
+		/* make route decision */
+		LIST_REMOVE(pref, rib_l);
+		prefix_evaluate(NULL, pref->rib);
+	}
 
 	LIST_REMOVE(pref, path_l);
-	PREFIX_COUNT(pref->aspath, pref->flags, -1);
-	PREFIX_COUNT(pref->aspath->peer, pref->flags, -1);
+	PREFIX_COUNT(pref->aspath, -1);
+
+	pt_unref(pref->prefix);
+	if (pt_empty(pref->prefix))
+		pt_remove(pref->prefix);
 
 	/* destroy all references to other objects */
 	pref->aspath = NULL;
 	pref->prefix = NULL;
+	pref->rib = NULL;
 
 	/*
 	 * It's the caller's duty to remove empty aspath respectively pt_entry
@@ -817,6 +1065,7 @@ nexthop_update(struct kroute_nexthop *ms
 {
 	struct nexthop		*nh;
 	struct rde_aspath	*asp;
+	enum nexthop_state	 oldstate;
 
 	nh = nexthop_lookup(&msg->nexthop);
 	if (nh == NULL) {
@@ -825,15 +1074,16 @@ nexthop_update(struct kroute_nexthop *ms
 		return;
 	}
 
+	if (nexthop_delete(nh))
+		/* nexthop no longer used */
+		return;
+
+	oldstate = nh->state;
 	if (msg->valid)
 		nh->state = NEXTHOP_REACH;
 	else
 		nh->state = NEXTHOP_UNREACH;
 
-	if (nexthop_delete(nh))
-		/* nexthop no longer used */
-		return;
-
 	if (msg->connected) {
 		nh->flags |= NEXTHOP_CONNECTED;
 		memcpy(&nh->true_nexthop, &nh->exit_nexthop,
@@ -866,7 +1116,7 @@ nexthop_update(struct kroute_nexthop *ms
 		return;
 
 	LIST_FOREACH(asp, &nh->path_h, nexthop_l) {
-		prefix_updateall(asp, nh->state);
+		prefix_updateall(asp, nh->state, oldstate);
 	}
 }
 
