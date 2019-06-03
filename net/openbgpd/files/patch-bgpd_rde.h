Index: bgpd/rde.h
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/rde.h,v
retrieving revision 1.1.1.8
retrieving revision 1.1.1.13
diff -u -p -r1.1.1.8 -r1.1.1.13
--- bgpd/rde.h	14 Feb 2010 20:19:57 -0000	1.1.1.8
+++ bgpd/rde.h	8 Dec 2012 10:37:09 -0000	1.1.1.13
@@ -1,8 +1,8 @@
-/*	$OpenBSD: rde.h,v 1.120 2009/06/06 01:10:29 claudio Exp $ */
+/*	$OpenBSD: rde.h,v 1.144 2012/09/12 05:56:22 claudio Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Claudio Jeker <claudio@openbsd.org> and
- *                          Andre Oppermann <oppermann@pipeline.ch>
+ *                          Andre Oppermann <oppermann@networx.ch>
  *
  * Permission to use, copy, modify, and distribute this software for any
  * purpose with or without fee is hereby granted, provided that the above
@@ -56,16 +56,16 @@ struct rde_peer {
 	struct bgpd_addr		 local_v6_addr;
 	struct uptree_prefix		 up_prefix;
 	struct uptree_attr		 up_attrs;
-	struct uplist_attr		 updates;
-	struct uplist_prefix		 withdraws;
-	struct uplist_attr		 updates6;
-	struct uplist_prefix		 withdraws6;
-	struct capabilities		 capa_announced;
-	struct capabilities		 capa_received;
+	struct uplist_attr		 updates[AID_MAX];
+	struct uplist_prefix		 withdraws[AID_MAX];
+	struct capabilities		 capa;
+	time_t				 staletime[AID_MAX];
 	u_int64_t			 prefix_rcvd_update;
 	u_int64_t			 prefix_rcvd_withdraw;
+	u_int64_t			 prefix_rcvd_eor;
 	u_int64_t			 prefix_sent_update;
 	u_int64_t			 prefix_sent_withdraw;
+	u_int64_t			 prefix_sent_eor;
 	u_int32_t			 prefix_cnt; /* # of prefixes */
 	u_int32_t			 remote_bgpid; /* host byte order! */
 	u_int32_t			 up_pcnt;
@@ -75,12 +75,16 @@ struct rde_peer {
 	enum peer_state			 state;
 	u_int16_t			 ribid;
 	u_int16_t			 short_as;
+	u_int16_t			 mrt_idx;
 	u_int8_t			 reconf_in;	/* in filter changed */
 	u_int8_t			 reconf_out;	/* out filter changed */
+	u_int8_t			 reconf_rib;	/* rib changed */
 };
 
 #define AS_SET			1
 #define AS_SEQUENCE		2
+#define AS_CONFED_SEQUENCE	3
+#define AS_CONFED_SET		4
 #define ASPATH_HEADER_SIZE	(sizeof(struct aspath) - sizeof(u_char))
 
 LIST_HEAD(aspath_list, aspath);
@@ -117,6 +121,9 @@ enum attrtypes {
 #define ATTR_PARTIAL		0x20
 #define ATTR_TRANSITIVE		0x40
 #define ATTR_OPTIONAL		0x80
+#define ATTR_RESERVED		0x0f
+/* by default mask the reserved bits and the ext len bit */
+#define ATTR_DEFMASK		(ATTR_RESERVED | ATTR_EXTLEN)
 
 /* default attribute flags for well known attributes */
 #define ATTR_WELL_KNOWN		ATTR_TRANSITIVE
@@ -163,6 +170,8 @@ LIST_HEAD(prefix_head, prefix);
 #define	F_NEXTHOP_REJECT	0x02000
 #define	F_NEXTHOP_BLACKHOLE	0x04000
 #define	F_NEXTHOP_NOMODIFY	0x08000
+#define	F_NEXTHOP_MASK		0x0f000
+#define	F_ATTR_PARSE_ERR	0x10000
 #define	F_ATTR_LINKED		0x20000
 
 
@@ -220,14 +229,14 @@ struct nexthop {
 /* generic entry without address specific part */
 struct pt_entry {
 	RB_ENTRY(pt_entry)		 pt_e;
-	sa_family_t			 af;
+	u_int8_t			 aid;
 	u_int8_t			 prefixlen;
 	u_int16_t			 refcnt;
 };
 
 struct pt_entry4 {
 	RB_ENTRY(pt_entry)		 pt_e;
-	sa_family_t			 af;
+	u_int8_t			 aid;
 	u_int8_t			 prefixlen;
 	u_int16_t			 refcnt;
 	struct in_addr			 prefix4;
@@ -235,12 +244,25 @@ struct pt_entry4 {
 
 struct pt_entry6 {
 	RB_ENTRY(pt_entry)		 pt_e;
-	sa_family_t			 af;
+	u_int8_t			 aid;
 	u_int8_t			 prefixlen;
 	u_int16_t			 refcnt;
 	struct in6_addr			 prefix6;
 };
 
+struct pt_entry_vpn4 {
+	RB_ENTRY(pt_entry)		 pt_e;
+	u_int8_t			 aid;
+	u_int8_t			 prefixlen;
+	u_int16_t			 refcnt;
+	struct in_addr			 prefix4;
+	u_int64_t			 rd;
+	u_int8_t			 labelstack[21];
+	u_int8_t			 labellen;
+	u_int8_t			 pad1;
+	u_int8_t			 pad2;
+};
+
 struct rib_context {
 	LIST_ENTRY(rib_context)		 entry;
 	struct rib_entry		*ctx_re;
@@ -250,7 +272,7 @@ struct rib_context {
 	void		(*ctx_wait)(void *);
 	void				*ctx_arg;
 	unsigned int			 ctx_count;
-	sa_family_t			 ctx_af;
+	u_int8_t			 ctx_aid;
 };
 
 struct rib_entry {
@@ -262,23 +284,15 @@ struct rib_entry {
 	u_int16_t		 flags;
 };
 
-enum rib_state {
-	RIB_NONE,
-	RIB_ACTIVE,
-	RIB_DELETE
-};
-
 struct rib {
 	char			name[PEER_DESCR_LEN];
 	struct rib_tree		rib;
-	enum rib_state		state;
+	u_int			rtableid;
 	u_int16_t		flags;
 	u_int16_t		id;
+	enum reconf_action 	state;
 };
 
-#define F_RIB_ENTRYLOCK		0x0001
-#define F_RIB_NOEVALUATE	0x0002
-#define F_RIB_NOFIB		0x0004
 #define RIB_FAILED		0xffff
 
 struct prefix {
@@ -292,8 +306,14 @@ struct prefix {
 extern struct rde_memstats rdemem;
 
 /* prototypes */
+/* mrt.c */
+int		 mrt_dump_v2_hdr(struct mrt *, struct bgpd_config *,
+		    struct rde_peer_head *);
+void		 mrt_dump_upcall(struct rib_entry *, void *);
+void		 mrt_done(void *);
+
 /* rde.c */
-void		 rde_send_kroute(struct prefix *, struct prefix *);
+void		 rde_send_kroute(struct prefix *, struct prefix *, u_int16_t);
 void		 rde_send_nexthop(struct bgpd_addr *, int);
 void		 rde_send_pftable(u_int16_t, struct bgpd_addr *,
 		     u_int8_t, int);
@@ -309,7 +329,7 @@ int		 rde_as4byte(struct rde_peer *);
 /* rde_attr.c */
 int		 attr_write(void *, u_int16_t, u_int8_t, u_int8_t, void *,
 		     u_int16_t);
-int		 attr_writebuf(struct buf *, u_int8_t, u_int8_t, void *,
+int		 attr_writebuf(struct ibuf *, u_int8_t, u_int8_t, void *,
 		     u_int16_t);
 void		 attr_init(u_int32_t);
 void		 attr_shutdown(void);
@@ -327,6 +347,7 @@ int		 aspath_verify(void *, u_int16_t, i
 #define		 AS_ERR_LEN	-1
 #define		 AS_ERR_TYPE	-2
 #define		 AS_ERR_BAD	-3
+#define		 AS_ERR_SOFT	-4
 void		 aspath_init(u_int32_t);
 void		 aspath_shutdown(void);
 struct aspath	*aspath_get(void *, u_int16_t);
@@ -341,22 +362,66 @@ u_int32_t	 aspath_neighbor(struct aspath
 int		 aspath_loopfree(struct aspath *, u_int32_t);
 int		 aspath_compare(struct aspath *, struct aspath *);
 u_char		*aspath_prepend(struct aspath *, u_int32_t, int, u_int16_t *);
-int		 aspath_match(struct aspath *, enum as_spec, u_int32_t);
-int		 community_match(void *, u_int16_t, int, int);
+int		 aspath_lenmatch(struct aspath *, enum aslen_spec, u_int);
+int		 community_match(struct rde_aspath *, int, int);
 int		 community_set(struct rde_aspath *, int, int);
 void		 community_delete(struct rde_aspath *, int, int);
+int		 community_ext_match(struct rde_aspath *,
+		    struct filter_extcommunity *, u_int16_t);
+int		 community_ext_set(struct rde_aspath *,
+		    struct filter_extcommunity *, u_int16_t);
+void		 community_ext_delete(struct rde_aspath *,
+		    struct filter_extcommunity *, u_int16_t);
+int		 community_ext_conv(struct filter_extcommunity *, u_int16_t,
+		    u_int64_t *);
+
+/* rde_decide.c */
+void		 prefix_evaluate(struct prefix *, struct rib_entry *);
+
+/* rde_filter.c */
+enum filter_actions rde_filter(u_int16_t, struct rde_aspath **,
+		     struct filter_head *, struct rde_peer *,
+		     struct rde_aspath *, struct bgpd_addr *, u_int8_t,
+		     struct rde_peer *, enum directions);
+void		 rde_apply_set(struct rde_aspath *, struct filter_set_head *,
+		     u_int8_t, struct rde_peer *, struct rde_peer *);
+int		 rde_filter_equal(struct filter_head *, struct filter_head *,
+		     struct rde_peer *, enum directions);
+
+/* rde_prefix.c */
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
+struct pt_entry	*pt_get(struct bgpd_addr *, int);
+struct pt_entry *pt_add(struct bgpd_addr *, int);
+void	 pt_remove(struct pt_entry *);
+struct pt_entry	*pt_lookup(struct bgpd_addr *);
+int	 pt_prefix_cmp(const struct pt_entry *, const struct pt_entry *);
 
 /* rde_rib.c */
 extern u_int16_t	 rib_size;
 extern struct rib	*ribs;
 
-u_int16_t	 rib_new(int, char *, u_int16_t);
+u_int16_t	 rib_new(char *, u_int, u_int16_t);
 u_int16_t	 rib_find(char *);
 void		 rib_free(struct rib *);
 struct rib_entry *rib_get(struct rib *, struct bgpd_addr *, int);
 struct rib_entry *rib_lookup(struct rib *, struct bgpd_addr *);
 void		 rib_dump(struct rib *, void (*)(struct rib_entry *, void *),
-		     void *, sa_family_t);
+		     void *, u_int8_t);
 void		 rib_dump_r(struct rib_context *);
 void		 rib_dump_runner(void);
 int		 rib_dump_pending(void);
@@ -368,6 +433,7 @@ int		 path_update(struct rib *, struct r
 int		 path_compare(struct rde_aspath *, struct rde_aspath *);
 struct rde_aspath *path_lookup(struct rde_aspath *, struct rde_peer *);
 void		 path_remove(struct rde_aspath *);
+void		 path_remove_stale(struct rde_aspath *, u_int8_t);
 void		 path_destroy(struct rde_aspath *);
 int		 path_empty(struct rde_aspath *);
 struct rde_aspath *path_copy(struct rde_aspath *);
@@ -375,8 +441,6 @@ struct rde_aspath *path_get(void);
 void		 path_put(struct rde_aspath *);
 
 #define	PREFIX_SIZE(x)	(((x) + 7) / 8 + 1)
-int		 prefix_compare(const struct bgpd_addr *,
-		    const struct bgpd_addr *, int);
 struct prefix	*prefix_get(struct rib *, struct rde_peer *,
 		    struct bgpd_addr *, int, u_int32_t);
 int		 prefix_add(struct rib *, struct rde_aspath *,
@@ -385,6 +449,7 @@ void		 prefix_move(struct rde_aspath *, 
 int		 prefix_remove(struct rib *, struct rde_peer *,
 		    struct bgpd_addr *, int, u_int32_t);
 int		 prefix_write(u_char *, int, struct bgpd_addr *, u_int8_t);
+int		 prefix_writebuf(struct ibuf *, struct bgpd_addr *, u_int8_t);
 struct prefix	*prefix_bypeer(struct rib_entry *, struct rde_peer *,
 		     u_int32_t);
 void		 prefix_updateall(struct rde_aspath *, enum nexthop_state,
@@ -395,7 +460,7 @@ void		 prefix_network_clean(struct rde_p
 void		 nexthop_init(u_int32_t);
 void		 nexthop_shutdown(void);
 void		 nexthop_modify(struct rde_aspath *, struct bgpd_addr *,
-		     enum action_types, sa_family_t);
+		     enum action_types, u_int8_t);
 void		 nexthop_link(struct rde_aspath *);
 void		 nexthop_unlink(struct rde_aspath *);
 int		 nexthop_delete(struct nexthop *);
@@ -403,9 +468,6 @@ void		 nexthop_update(struct kroute_next
 struct nexthop	*nexthop_get(struct bgpd_addr *);
 int		 nexthop_compare(struct nexthop *, struct nexthop *);
 
-/* rde_decide.c */
-void		 prefix_evaluate(struct prefix *, struct rib_entry *);
-
 /* rde_update.c */
 void		 up_init(struct rde_peer *);
 void		 up_down(struct rde_peer *);
@@ -415,49 +477,14 @@ int		 up_generate(struct rde_peer *, str
 void		 up_generate_updates(struct filter_head *, struct rde_peer *,
 		     struct prefix *, struct prefix *);
 void		 up_generate_default(struct filter_head *, struct rde_peer *,
-		     sa_family_t);
+		     u_int8_t);
+int		 up_generate_marker(struct rde_peer *, u_int8_t);
 int		 up_dump_prefix(u_char *, int, struct uplist_prefix *,
 		     struct rde_peer *);
 int		 up_dump_attrnlri(u_char *, int, struct rde_peer *);
-u_char		*up_dump_mp_unreach(u_char *, u_int16_t *, struct rde_peer *);
-u_char		*up_dump_mp_reach(u_char *, u_int16_t *, struct rde_peer *);
-
-/* rde_prefix.c */
-#define pt_empty(pt)	((pt)->refcnt == 0)
-#define pt_ref(pt)	do {				\
-	++(pt)->refcnt;					\
-	if ((pt)->refcnt == 0)				\
-		fatalx("pt_ref: overflow");		\
-} while(0)
-#define pt_unref(pt)	do {				\
-	if ((pt)->refcnt == 0)				\
-		fatalx("pt_unref: underflow");		\
-	--(pt)->refcnt;					\
-} while(0)
-
-void	 pt_init(void);
-void	 pt_shutdown(void);
-void	 pt_getaddr(struct pt_entry *, struct bgpd_addr *);
-struct pt_entry	*pt_fill(struct bgpd_addr *, int);
-struct pt_entry	*pt_get(struct bgpd_addr *, int);
-struct pt_entry *pt_add(struct bgpd_addr *, int);
-void	 pt_remove(struct pt_entry *);
-struct pt_entry	*pt_lookup(struct bgpd_addr *);
-int	 pt_prefix_cmp(const struct pt_entry *, const struct pt_entry *);
-
-
-/* rde_filter.c */
-enum filter_actions rde_filter(u_int16_t, struct rde_aspath **,
-		     struct filter_head *, struct rde_peer *,
-		     struct rde_aspath *, struct bgpd_addr *, u_int8_t,
-		     struct rde_peer *, enum directions);
-void		 rde_apply_set(struct rde_aspath *, struct filter_set_head *,
-		     sa_family_t, struct rde_peer *, struct rde_peer *);
-int		 rde_filter_community(struct rde_aspath *, int, int);
-int		 rde_filter_equal(struct filter_head *, struct filter_head *,
-		     struct rde_peer *, enum directions);
-
-/* util.c */
-u_int32_t	 aspath_extract(const void *, int);
+u_char		*up_dump_mp_unreach(u_char *, u_int16_t *, struct rde_peer *,
+		     u_int8_t);
+int		 up_dump_mp_reach(u_char *, u_int16_t *, struct rde_peer *,
+		     u_int8_t);
 
 #endif /* __RDE_H__ */
