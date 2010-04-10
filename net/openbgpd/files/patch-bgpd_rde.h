Index: bgpd/rde.h
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/rde.h,v
retrieving revision 1.1.1.8
retrieving revision 1.1.1.10
diff -u -p -r1.1.1.8 -r1.1.1.10
--- bgpd/rde.h	14 Feb 2010 20:19:57 -0000	1.1.1.8
+++ bgpd/rde.h	10 Apr 2010 12:13:05 -0000	1.1.1.10
@@ -1,4 +1,4 @@
-/*	$OpenBSD: rde.h,v 1.120 2009/06/06 01:10:29 claudio Exp $ */
+/*	$OpenBSD: rde.h,v 1.133 2010/03/29 09:24:07 claudio Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Claudio Jeker <claudio@openbsd.org> and
@@ -56,12 +56,9 @@ struct rde_peer {
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
 	u_int64_t			 prefix_rcvd_update;
 	u_int64_t			 prefix_rcvd_withdraw;
 	u_int64_t			 prefix_sent_update;
@@ -163,6 +160,7 @@ LIST_HEAD(prefix_head, prefix);
 #define	F_NEXTHOP_REJECT	0x02000
 #define	F_NEXTHOP_BLACKHOLE	0x04000
 #define	F_NEXTHOP_NOMODIFY	0x08000
+#define	F_ATTR_PARSE_ERR	0x10000
 #define	F_ATTR_LINKED		0x20000
 
 
@@ -220,14 +218,14 @@ struct nexthop {
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
@@ -235,12 +233,25 @@ struct pt_entry4 {
 
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
@@ -250,7 +261,7 @@ struct rib_context {
 	void		(*ctx_wait)(void *);
 	void				*ctx_arg;
 	unsigned int			 ctx_count;
-	sa_family_t			 ctx_af;
+	u_int8_t			 ctx_aid;
 };
 
 struct rib_entry {
@@ -262,16 +273,10 @@ struct rib_entry {
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
+	enum reconf_action 	state;
 	u_int16_t		flags;
 	u_int16_t		id;
 };
@@ -342,21 +347,29 @@ int		 aspath_loopfree(struct aspath *, u
 int		 aspath_compare(struct aspath *, struct aspath *);
 u_char		*aspath_prepend(struct aspath *, u_int32_t, int, u_int16_t *);
 int		 aspath_match(struct aspath *, enum as_spec, u_int32_t);
-int		 community_match(void *, u_int16_t, int, int);
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
 
 /* rde_rib.c */
 extern u_int16_t	 rib_size;
 extern struct rib	*ribs;
 
-u_int16_t	 rib_new(int, char *, u_int16_t);
+u_int16_t	 rib_new(char *, u_int16_t);
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
@@ -395,7 +408,7 @@ void		 prefix_network_clean(struct rde_p
 void		 nexthop_init(u_int32_t);
 void		 nexthop_shutdown(void);
 void		 nexthop_modify(struct rde_aspath *, struct bgpd_addr *,
-		     enum action_types, sa_family_t);
+		     enum action_types, u_int8_t);
 void		 nexthop_link(struct rde_aspath *);
 void		 nexthop_unlink(struct rde_aspath *);
 int		 nexthop_delete(struct nexthop *);
@@ -415,12 +428,15 @@ int		 up_generate(struct rde_peer *, str
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
+u_char		*up_dump_mp_unreach(u_char *, u_int16_t *, struct rde_peer *,
+		     u_int8_t);
+int		 up_dump_mp_reach(u_char *, u_int16_t *, struct rde_peer *,
+		     u_int8_t);
 
 /* rde_prefix.c */
 #define pt_empty(pt)	((pt)->refcnt == 0)
@@ -452,8 +468,7 @@ enum filter_actions rde_filter(u_int16_t
 		     struct rde_aspath *, struct bgpd_addr *, u_int8_t,
 		     struct rde_peer *, enum directions);
 void		 rde_apply_set(struct rde_aspath *, struct filter_set_head *,
-		     sa_family_t, struct rde_peer *, struct rde_peer *);
-int		 rde_filter_community(struct rde_aspath *, int, int);
+		     u_int8_t, struct rde_peer *, struct rde_peer *);
 int		 rde_filter_equal(struct filter_head *, struct filter_head *,
 		     struct rde_peer *, enum directions);
 
