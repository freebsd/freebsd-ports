Index: bgpd/rde.h
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/rde.h,v
retrieving revision 1.1.1.1
retrieving revision 1.1.1.2
diff -u -p -r1.1.1.1 -r1.1.1.2
--- bgpd/rde.h	30 Jun 2009 05:46:15 -0000	1.1.1.1
+++ bgpd/rde.h	9 Jul 2009 16:49:54 -0000	1.1.1.2
@@ -1,4 +1,4 @@
-/*	$OpenBSD: rde.h,v 1.102 2008/01/23 08:11:32 claudio Exp $ */
+/*	$OpenBSD: rde.h,v 1.120 2009/06/06 01:10:29 claudio Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Claudio Jeker <claudio@openbsd.org> and
@@ -42,6 +42,7 @@ LIST_HEAD(rde_peer_head, rde_peer);
 LIST_HEAD(aspath_head, rde_aspath);
 RB_HEAD(uptree_prefix, update_prefix);
 RB_HEAD(uptree_attr, update_attr);
+RB_HEAD(rib_tree, rib_entry);
 TAILQ_HEAD(uplist_prefix, update_prefix);
 TAILQ_HEAD(uplist_attr, update_attr);
 
@@ -66,13 +67,13 @@ struct rde_peer {
 	u_int64_t			 prefix_sent_update;
 	u_int64_t			 prefix_sent_withdraw;
 	u_int32_t			 prefix_cnt; /* # of prefixes */
-	u_int32_t			 adjrib_cnt; /* # of p. in Adj-RIB-In */
 	u_int32_t			 remote_bgpid; /* host byte order! */
 	u_int32_t			 up_pcnt;
 	u_int32_t			 up_acnt;
 	u_int32_t			 up_nlricnt;
 	u_int32_t			 up_wcnt;
 	enum peer_state			 state;
+	u_int16_t			 ribid;
 	u_int16_t			 short_as;
 	u_int8_t			 reconf_in;	/* in filter changed */
 	u_int8_t			 reconf_out;	/* out filter changed */
@@ -107,8 +108,8 @@ enum attrtypes {
 	ATTR_MP_REACH_NLRI=14,
 	ATTR_MP_UNREACH_NLRI=15,
 	ATTR_EXT_COMMUNITIES=16,
-	ATTR_NEW_ASPATH=17,
-	ATTR_NEW_AGGREGATOR=18
+	ATTR_AS4_PATH=17,
+	ATTR_AS4_AGGREGATOR=18
 };
 
 /* attribute flags. 4 low order bits reserved */
@@ -154,16 +155,15 @@ LIST_HEAD(prefix_head, prefix);
 #define	F_ATTR_MED_ANNOUNCE	0x00020
 #define	F_ATTR_MP_REACH		0x00040
 #define	F_ATTR_MP_UNREACH	0x00080
-#define	F_ATTR_AS4BYTE_NEW	0x00100	/* NEW_ASPATH or NEW_AGGREGATOR */
+#define	F_ATTR_AS4BYTE_NEW	0x00100	/* AS4_PATH or AS4_AGGREGATOR */
 #define	F_ATTR_LOOP		0x00200 /* path would cause a route loop */
-#define	F_PREFIX_ANNOUNCED	0x01000
+#define	F_PREFIX_ANNOUNCED	0x00400
+#define	F_ANN_DYNAMIC		0x00800
+#define	F_NEXTHOP_SELF		0x01000
 #define	F_NEXTHOP_REJECT	0x02000
 #define	F_NEXTHOP_BLACKHOLE	0x04000
 #define	F_NEXTHOP_NOMODIFY	0x08000
-#define	F_NEXTHOP_SELF		0x10000
 #define	F_ATTR_LINKED		0x20000
-#define	F_LOCAL			0x40000	/* Local-RIB */
-#define	F_ORIGINAL		0x80000	/* Adj-RIB-In */
 
 
 #define ORIGIN_IGP		0
@@ -184,7 +184,6 @@ struct rde_aspath {
 	u_int32_t			 weight;	/* low prio lpref */
 	u_int32_t			 prefix_cnt; /* # of prefixes */
 	u_int32_t			 active_cnt; /* # of active prefixes */
-	u_int32_t			 adjrib_cnt; /* # of p. in Adj-RIB-In */
 	u_int32_t			 flags;		/* internally used */
 	u_int16_t			 rtlabelid;	/* route label id */
 	u_int16_t			 pftableid;	/* pf table id */
@@ -223,53 +222,71 @@ struct pt_entry {
 	RB_ENTRY(pt_entry)		 pt_e;
 	sa_family_t			 af;
 	u_int8_t			 prefixlen;
-	struct prefix_head		 prefix_h;
-	struct prefix			*active; /* for fast access */
+	u_int16_t			 refcnt;
 };
 
 struct pt_entry4 {
 	RB_ENTRY(pt_entry)		 pt_e;
 	sa_family_t			 af;
 	u_int8_t			 prefixlen;
-	struct prefix_head		 prefix_h;
-	struct prefix			*active; /* for fast access */
+	u_int16_t			 refcnt;
 	struct in_addr			 prefix4;
-	/*
-	 * Route Flap Damping structures
-	 * Currently I think they belong into the prefix but for the moment
-	 * we just ignore the dampening at all.
-	 */
 };
 
 struct pt_entry6 {
 	RB_ENTRY(pt_entry)		 pt_e;
 	sa_family_t			 af;
 	u_int8_t			 prefixlen;
-	struct prefix_head		 prefix_h;
-	struct prefix			*active; /* for fast access */
+	u_int16_t			 refcnt;
 	struct in6_addr			 prefix6;
 };
 
-struct pt_context {
-	union {
-		struct pt_entry		p;
-		struct pt_entry4	p4;
-		struct pt_entry6	p6;
-	}			pu;
-#define ctx_p			pu.p
-#define ctx_p4			pu.p4
-#define ctx_p6			pu.p6
-	/* only count and done should be accessed by callers */
-	unsigned int		count;
-	int			done;
-};
+struct rib_context {
+	LIST_ENTRY(rib_context)		 entry;
+	struct rib_entry		*ctx_re;
+	struct rib			*ctx_rib;
+	void		(*ctx_upcall)(struct rib_entry *, void *);
+	void		(*ctx_done)(void *);
+	void		(*ctx_wait)(void *);
+	void				*ctx_arg;
+	unsigned int			 ctx_count;
+	sa_family_t			 ctx_af;
+};
+
+struct rib_entry {
+	RB_ENTRY(rib_entry)	 rib_e;
+	struct prefix_head	 prefix_h;
+	struct prefix		*active; /* for fast access */
+	struct pt_entry		*prefix;
+	u_int16_t		 ribid;
+	u_int16_t		 flags;
+};
+
+enum rib_state {
+	RIB_NONE,
+	RIB_ACTIVE,
+	RIB_DELETE
+};
+
+struct rib {
+	char			name[PEER_DESCR_LEN];
+	struct rib_tree		rib;
+	enum rib_state		state;
+	u_int16_t		flags;
+	u_int16_t		id;
+};
+
+#define F_RIB_ENTRYLOCK		0x0001
+#define F_RIB_NOEVALUATE	0x0002
+#define F_RIB_NOFIB		0x0004
+#define RIB_FAILED		0xffff
 
 struct prefix {
-	LIST_ENTRY(prefix)		 prefix_l, path_l;
+	LIST_ENTRY(prefix)		 rib_l, path_l;
 	struct rde_aspath		*aspath;
 	struct pt_entry			*prefix;
+	struct rib_entry		*rib;	/* NULL for Adj-RIB-In */
 	time_t				 lastchange;
-	u_int32_t			 flags;
 };
 
 extern struct rde_memstats rdemem;
@@ -282,7 +299,8 @@ void		 rde_send_pftable(u_int16_t, struc
 		     u_int8_t, int);
 void		 rde_send_pftable_commit(void);
 
-void		 rde_generate_updates(struct prefix *, struct prefix *);
+void		 rde_generate_updates(u_int16_t, struct prefix *,
+		     struct prefix *);
 u_int32_t	 rde_local_as(void);
 int		 rde_noevaluate(void);
 int		 rde_decisionflags(void);
@@ -291,6 +309,8 @@ int		 rde_as4byte(struct rde_peer *);
 /* rde_attr.c */
 int		 attr_write(void *, u_int16_t, u_int8_t, u_int8_t, void *,
 		     u_int16_t);
+int		 attr_writebuf(struct buf *, u_int8_t, u_int8_t, void *,
+		     u_int16_t);
 void		 attr_init(u_int32_t);
 void		 attr_shutdown(void);
 int		 attr_optadd(struct rde_aspath *, u_int8_t, u_int8_t,
@@ -327,10 +347,24 @@ int		 community_set(struct rde_aspath *,
 void		 community_delete(struct rde_aspath *, int, int);
 
 /* rde_rib.c */
+extern u_int16_t	 rib_size;
+extern struct rib	*ribs;
+
+u_int16_t	 rib_new(int, char *, u_int16_t);
+u_int16_t	 rib_find(char *);
+void		 rib_free(struct rib *);
+struct rib_entry *rib_get(struct rib *, struct bgpd_addr *, int);
+struct rib_entry *rib_lookup(struct rib *, struct bgpd_addr *);
+void		 rib_dump(struct rib *, void (*)(struct rib_entry *, void *),
+		     void *, sa_family_t);
+void		 rib_dump_r(struct rib_context *);
+void		 rib_dump_runner(void);
+int		 rib_dump_pending(void);
+
 void		 path_init(u_int32_t);
 void		 path_shutdown(void);
-void		 path_update(struct rde_peer *, struct rde_aspath *,
-		     struct bgpd_addr *, int, u_int32_t);
+int		 path_update(struct rib *, struct rde_peer *,
+		     struct rde_aspath *, struct bgpd_addr *, int);
 int		 path_compare(struct rde_aspath *, struct rde_aspath *);
 struct rde_aspath *path_lookup(struct rde_aspath *, struct rde_peer *);
 void		 path_remove(struct rde_aspath *);
@@ -343,18 +377,20 @@ void		 path_put(struct rde_aspath *);
 #define	PREFIX_SIZE(x)	(((x) + 7) / 8 + 1)
 int		 prefix_compare(const struct bgpd_addr *,
 		    const struct bgpd_addr *, int);
-struct prefix	*prefix_get(struct rde_peer *, struct bgpd_addr *, int,
-		    u_int32_t);
-struct pt_entry	*prefix_add(struct rde_aspath *, struct bgpd_addr *, int,
-		    u_int32_t);
-struct pt_entry	*prefix_move(struct rde_aspath *, struct prefix *, u_int32_t);
-void		 prefix_remove(struct rde_peer *, struct bgpd_addr *, int,
-		    u_int32_t);
+struct prefix	*prefix_get(struct rib *, struct rde_peer *,
+		    struct bgpd_addr *, int, u_int32_t);
+int		 prefix_add(struct rib *, struct rde_aspath *,
+		    struct bgpd_addr *, int);
+void		 prefix_move(struct rde_aspath *, struct prefix *);
+int		 prefix_remove(struct rib *, struct rde_peer *,
+		    struct bgpd_addr *, int, u_int32_t);
 int		 prefix_write(u_char *, int, struct bgpd_addr *, u_int8_t);
-struct prefix	*prefix_bypeer(struct pt_entry *, struct rde_peer *, u_int32_t);
-void		 prefix_updateall(struct rde_aspath *, enum nexthop_state);
+struct prefix	*prefix_bypeer(struct rib_entry *, struct rde_peer *,
+		     u_int32_t);
+void		 prefix_updateall(struct rde_aspath *, enum nexthop_state,
+		     enum nexthop_state);
 void		 prefix_destroy(struct prefix *);
-void		 prefix_network_clean(struct rde_peer *, time_t);
+void		 prefix_network_clean(struct rde_peer *, time_t, u_int32_t);
 
 void		 nexthop_init(u_int32_t);
 void		 nexthop_shutdown(void);
@@ -368,7 +404,7 @@ struct nexthop	*nexthop_get(struct bgpd_
 int		 nexthop_compare(struct nexthop *, struct nexthop *);
 
 /* rde_decide.c */
-void		 prefix_evaluate(struct prefix *, struct pt_entry *);
+void		 prefix_evaluate(struct prefix *, struct rib_entry *);
 
 /* rde_update.c */
 void		 up_init(struct rde_peer *);
@@ -387,24 +423,34 @@ u_char		*up_dump_mp_unreach(u_char *, u_
 u_char		*up_dump_mp_reach(u_char *, u_int16_t *, struct rde_peer *);
 
 /* rde_prefix.c */
-void		 pt_init(void);
-void		 pt_shutdown(void);
-int		 pt_empty(struct pt_entry *);
-void		 pt_getaddr(struct pt_entry *, struct bgpd_addr *);
+#define pt_empty(pt)	((pt)->refcnt == 0)
+#define pt_ref(pt)	do {				\
+	++(pt)->refcnt;					\
+	if ((pt)->refcnt == 0)				\
+		fatalx("pt_ref: overflow");		\
+} while(0)
+#define pt_unref(pt)	do {				\
+	if ((pt)->refcnt == 0)				\
+		fatalx("pt_unref: underflow");		\
+	--(pt)->refcnt;					\
+} while(0)
+
+void	 pt_init(void);
+void	 pt_shutdown(void);
+void	 pt_getaddr(struct pt_entry *, struct bgpd_addr *);
+struct pt_entry	*pt_fill(struct bgpd_addr *, int);
 struct pt_entry	*pt_get(struct bgpd_addr *, int);
 struct pt_entry *pt_add(struct bgpd_addr *, int);
-void		 pt_remove(struct pt_entry *);
+void	 pt_remove(struct pt_entry *);
 struct pt_entry	*pt_lookup(struct bgpd_addr *);
-void		 pt_dump(void (*)(struct pt_entry *, void *), void *,
-		     sa_family_t);
-void		 pt_dump_r(void (*)(struct pt_entry *, void *), void *,
-		     sa_family_t, struct pt_context *);
+int	 pt_prefix_cmp(const struct pt_entry *, const struct pt_entry *);
+
 
 /* rde_filter.c */
-enum filter_actions rde_filter(struct rde_aspath **, struct filter_head *,
-		     struct rde_peer *, struct rde_aspath *,
-		     struct bgpd_addr *, u_int8_t, struct rde_peer *,
-		     enum directions);
+enum filter_actions rde_filter(u_int16_t, struct rde_aspath **,
+		     struct filter_head *, struct rde_peer *,
+		     struct rde_aspath *, struct bgpd_addr *, u_int8_t,
+		     struct rde_peer *, enum directions);
 void		 rde_apply_set(struct rde_aspath *, struct filter_set_head *,
 		     sa_family_t, struct rde_peer *, struct rde_peer *);
 int		 rde_filter_community(struct rde_aspath *, int, int);
