Index: bgpd/bgpd.h
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/bgpd.h,v
retrieving revision 1.1.1.8
retrieving revision 1.11
diff -u -p -r1.1.1.8 -r1.11
--- bgpd/bgpd.h	14 Feb 2010 20:19:57 -0000	1.1.1.8
+++ bgpd/bgpd.h	10 Apr 2010 12:16:23 -0000	1.11
@@ -1,4 +1,4 @@
-/*	$OpenBSD: bgpd.h,v 1.241 2009/06/12 16:42:53 claudio Exp $ */
+/*	$OpenBSD: bgpd.h,v 1.255 2010/04/06 13:25:08 claudio Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Henning Brauer <henning@openbsd.org>
@@ -30,11 +30,16 @@
 #include <poll.h>
 #include <stdarg.h>
 
-#include <imsg.h>
+#if defined(__FreeBSD__)	/* compat */
+#include "openbsd-compat.h"
+#endif /* defined(__FreeBSD__) */
+#include "imsg.h"
 
 #define	BGP_VERSION			4
 #define	BGP_PORT			179
+#ifndef CONFFILE
 #define	CONFFILE			"/etc/bgpd.conf"
+#endif /* !CONFFILE */
 #define	BGPD_USER			"_bgpd"
 #define	PEER_DESCR_LEN			32
 #define	PFTABLE_LEN			16
@@ -42,8 +47,6 @@
 #define	IPSEC_ENC_KEY_LEN		32
 #define	IPSEC_AUTH_KEY_LEN		20
 
-#define	ASNUM_MAX			0xffffffff
-
 #define	MAX_PKTSIZE			4096
 #define	MIN_HOLDTIME			3
 #define	READ_BUF_SIZE			65535
@@ -109,18 +112,74 @@ enum reconf_action {
 	RECONF_DELETE
 };
 
+/* Address Family Numbers as per RFC 1700 */
+#define	AFI_UNSPEC	0
+#define	AFI_IPv4	1
+#define	AFI_IPv6	2
+
+/* Subsequent Address Family Identifier as per RFC 4760 */
+#define	SAFI_NONE	0
+#define	SAFI_UNICAST	1
+#define	SAFI_MULTICAST	2
+#define	SAFI_MPLS	4
+#define	SAFI_MPLSVPN	128
+
+struct aid {
+	u_int16_t	 afi;
+	sa_family_t	 af;
+	u_int8_t	 safi;
+	char		*name;
+};
+
+extern const struct aid aid_vals[];
+
+#define	AID_UNSPEC	0
+#define	AID_INET	1
+#define	AID_INET6	2
+#define	AID_VPN_IPv4	3
+#define	AID_MAX		4
+
+#define AID_VALS	{					\
+	/* afi, af, safii, name */				\
+	{ AFI_UNSPEC, AF_UNSPEC, SAFI_NONE, "unspec"},		\
+	{ AFI_IPv4, AF_INET, SAFI_UNICAST, "IPv4 unicast" },	\
+	{ AFI_IPv6, AF_INET6, SAFI_UNICAST, "IPv6 unicast" },	\
+	{ AFI_IPv4, AF_INET, SAFI_MPLSVPN, "IPv4 vpn" }		\
+}
+
+#define AID_PTSIZE	{				\
+	0,						\
+	sizeof(struct pt_entry4), 			\
+	sizeof(struct pt_entry6),			\
+	sizeof(struct pt_entry_vpn4)			\
+}
+
+struct vpn4_addr {
+	u_int64_t	rd;
+	struct in_addr	addr;
+	u_int8_t	labelstack[21];	/* max that makes sense */
+	u_int8_t	labellen;
+	u_int8_t	pad1;
+	u_int8_t	pad2;
+};
+
+#define BGP_MPLS_BOS	0x01
+
 struct bgpd_addr {
-	sa_family_t	af;
 	union {
 		struct in_addr		v4;
 		struct in6_addr		v6;
-		u_int8_t		addr8[16];
-		u_int16_t		addr16[8];
-		u_int32_t		addr32[4];
+		struct vpn4_addr	vpn4;
+		/* maximum size for a prefix is 256 bits */
+		u_int8_t		addr8[32];
+		u_int16_t		addr16[16];
+		u_int32_t		addr32[8];
 	} ba;		    /* 128-bit address */
 	u_int32_t	scope_id;	/* iface scope id for v6 */
+	u_int8_t	aid;
 #define	v4	ba.v4
 #define	v6	ba.v6
+#define	vpn4	ba.vpn4
 #define	addr8	ba.addr8
 #define	addr16	ba.addr16
 #define	addr32	ba.addr32
@@ -205,11 +264,10 @@ struct peer_auth {
 };
 
 struct capabilities {
-	u_int8_t	mp_v4;		/* multiprotocol extensions, RFC 4760 */
-	u_int8_t	mp_v6;
-	u_int8_t	refresh;	/* route refresh, RFC 2918 */
-	u_int8_t	restart;	/* graceful restart, RFC 4724 */
-	u_int8_t	as4byte;	/* draft-ietf-idr-as4bytes-13 */
+	int8_t	mp[AID_MAX];	/* multiprotocol extensions, RFC 4760 */
+	int8_t	refresh;	/* route refresh, RFC 2918 */
+	int8_t	restart;	/* graceful restart, RFC 4724 */
+	int8_t	as4byte;	/* draft-ietf-idr-as4bytes-13 */
 };
 
 struct peer_config {
@@ -248,6 +306,7 @@ struct peer_config {
 	u_int8_t		 ttlsec;	/* TTL security hack */
 	u_int8_t		 flags;
 	u_int8_t		 pad[3];
+	char			 lliface[IFNAMSIZ];
 };
 
 #define PEERFLAG_TRANS_AS	0x01
@@ -292,6 +351,7 @@ enum imsg_type {
 	IMSG_CTL_SHOW_RIB_MEM,
 	IMSG_CTL_SHOW_TERSE,
 	IMSG_CTL_SHOW_TIMER,
+	IMSG_CTL_LOG_VERBOSE,
 	IMSG_NETWORK_ADD,
 	IMSG_NETWORK_REMOVE,
 	IMSG_NETWORK_FLUSH,
@@ -400,14 +460,12 @@ struct kroute6 {
 };
 
 struct kroute_nexthop {
-	union {
-		struct kroute		kr4;
-		struct kroute6		kr6;
-	} kr;
 	struct bgpd_addr	nexthop;
 	struct bgpd_addr	gateway;
+	struct bgpd_addr	net;
 	u_int8_t		valid;
 	u_int8_t		connected;
+	u_int8_t		netlen;
 };
 
 struct kif {
@@ -423,8 +481,7 @@ struct kif {
 struct session_up {
 	struct bgpd_addr	local_addr;
 	struct bgpd_addr	remote_addr;
-	struct capabilities	capa_announced;
-	struct capabilities	capa_received;
+	struct capabilities	capa;
 	u_int32_t		remote_bgpid;
 	u_int16_t		short_as;
 };
@@ -437,8 +494,13 @@ struct pftable_msg {
 
 struct ctl_show_nexthop {
 	struct bgpd_addr	addr;
-	u_int8_t		valid;
 	struct kif		kif;
+	union {
+		struct kroute		kr4;
+		struct kroute6		kr6;
+	} kr;
+	u_int8_t		valid;
+	u_int8_t		krvalid;;
 };
 
 struct ctl_neighbor {
@@ -508,6 +570,28 @@ struct filter_community {
 	int			type;
 };
 
+struct filter_extcommunity {
+	u_int16_t	flags;
+	u_int8_t	type;
+	u_int8_t	subtype;	/* if extended type */
+	union {
+		struct ext_as {
+			u_int16_t	as;
+			u_int32_t	val;
+		}		ext_as;
+		struct ext_as4 {
+			u_int32_t	as4;
+			u_int16_t	val;
+		}		ext_as4;
+		struct ext_ip {
+			struct in_addr	addr;
+			u_int16_t	val;
+		}		ext_ip;
+		u_int64_t	ext_opaq;	/* only 48 bits */
+	}		data;
+};
+
+
 struct ctl_show_rib_request {
 	char			rib[PEER_DESCR_LEN];
 	struct ctl_neighbor	neighbor;
@@ -518,8 +602,8 @@ struct ctl_show_rib_request {
 	pid_t			pid;
 	u_int16_t		flags;
 	enum imsg_type		type;
-	sa_family_t		af;
 	u_int8_t		prefixlen;
+	u_int8_t		aid;
 };
 
 enum filter_actions {
@@ -585,6 +669,28 @@ struct filter_peers {
 #define EXT_COMMUNITY_OSPF_RTR_TYPE	6	/* RFC 4577 */
 #define EXT_COMMUNITY_OSPF_RTR_ID	7	/* RFC 4577 */
 #define EXT_COMMUNITY_BGP_COLLECT	8	/* RFC 4384 */
+/* other handy defines */
+#define EXT_COMMUNITY_OPAQUE_MAX	0xffffffffffffULL
+#define EXT_COMMUNITY_FLAG_VALID	0x01
+
+struct ext_comm_pairs {
+	u_int8_t	type;
+	u_int8_t	subtype;
+	u_int8_t	transitive;	/* transitive bit needs to be set */
+};
+
+#define IANA_EXT_COMMUNITIES	{					\
+	{ EXT_COMMUNITY_TWO_AS, EXT_COMMUNITY_ROUTE_TGT, 0 },		\
+	{ EXT_COMMUNITY_TWO_AS, EXT_CUMMUNITY_ROUTE_ORIG, 0 },		\
+	{ EXT_COMMUNITY_TWO_AS, EXT_COMMUNITY_OSPF_DOM_ID, 0 },		\
+	{ EXT_COMMUNITY_TWO_AS, EXT_COMMUNITY_BGP_COLLECT, 0 },		\
+	{ EXT_COMMUNITY_FOUR_AS, EXT_COMMUNITY_ROUTE_TGT, 0 },		\
+	{ EXT_COMMUNITY_FOUR_AS, EXT_CUMMUNITY_ROUTE_ORIG, 0 },		\
+	{ EXT_COMMUNITY_IPV4, EXT_COMMUNITY_ROUTE_TGT, 0 },		\
+	{ EXT_COMMUNITY_IPV4, EXT_CUMMUNITY_ROUTE_ORIG, 0 },		\
+	{ EXT_COMMUNITY_IPV4, EXT_COMMUNITY_OSPF_RTR_ID, 0 },		\
+	{ EXT_COMMUNITY_OPAQUE, EXT_COMMUNITY_OSPF_RTR_TYPE, 0 }	\
+}
 
 
 struct filter_prefix {
@@ -594,16 +700,17 @@ struct filter_prefix {
 
 struct filter_prefixlen {
 	enum comp_ops		op;
-	sa_family_t		af;
+	u_int8_t		aid;
 	u_int8_t		len_min;
 	u_int8_t		len_max;
 };
 
 struct filter_match {
-	struct filter_prefix	prefix;
-	struct filter_prefixlen	prefixlen;
-	struct filter_as	as;
-	struct filter_community	community;
+	struct filter_prefix		prefix;
+	struct filter_prefixlen		prefixlen;
+	struct filter_as		as;
+	struct filter_community		community;
+	struct filter_extcommunity	ext_community;
 };
 
 TAILQ_HEAD(filter_head, filter_rule);
@@ -635,10 +742,13 @@ enum action_types {
 	ACTION_SET_NEXTHOP_SELF,
 	ACTION_SET_COMMUNITY,
 	ACTION_DEL_COMMUNITY,
+	ACTION_SET_EXT_COMMUNITY,
+	ACTION_DEL_EXT_COMMUNITY,
 	ACTION_PFTABLE,
 	ACTION_PFTABLE_ID,
 	ACTION_RTLABEL,
-	ACTION_RTLABEL_ID
+	ACTION_RTLABEL_ID,
+	ACTION_SET_ORIGIN
 };
 
 struct filter_set {
@@ -650,23 +760,31 @@ struct filter_set {
 		int32_t			relative;
 		struct bgpd_addr	nexthop;
 		struct filter_community	community;
+		struct filter_extcommunity	ext_community;
 		char			pftable[PFTABLE_LEN];
 		char			rtlabel[RTLABEL_LEN];
+		u_int8_t		origin;
 	} action;
 	enum action_types		type;
 };
 
-struct rrefresh {
-	u_int16_t	afi;
-	u_int8_t	safi;
+struct rde_rib {
+	SIMPLEQ_ENTRY(rde_rib)	entry;
+	char			name[PEER_DESCR_LEN];
+	u_int16_t		id;
+	u_int16_t		flags;
 };
+SIMPLEQ_HEAD(rib_names, rde_rib);
+extern struct rib_names ribnames;
+
+/* 4-byte magic AS number */
+#define AS_TRANS	23456
 
 struct rde_memstats {
 	int64_t		path_cnt;
 	int64_t		prefix_cnt;
 	int64_t		rib_cnt;
-	int64_t		pt4_cnt;
-	int64_t		pt6_cnt;
+	int64_t		pt_cnt[AID_MAX];
 	int64_t		nexthop_cnt;
 	int64_t		aspath_cnt;
 	int64_t		aspath_size;
@@ -677,28 +795,17 @@ struct rde_memstats {
 	int64_t		attr_dcnt;
 };
 
-struct rde_rib {
-	SIMPLEQ_ENTRY(rde_rib)	entry;
-	char			name[PEER_DESCR_LEN];
-	u_int16_t		id;
-	u_int16_t		flags;
-};
-SIMPLEQ_HEAD(rib_names, rde_rib);
-extern struct rib_names ribnames;
-
-/* Address Family Numbers as per RFC 1700 */
-#define	AFI_IPv4	1
-#define	AFI_IPv6	2
-#define	AFI_ALL		0xffff
-
-/* Subsequent Address Family Identifier as per RFC 4760 */
-#define	SAFI_NONE	0x00
-#define	SAFI_UNICAST	0x01
-#define	SAFI_MULTICAST	0x02
-#define	SAFI_ALL	0xff
-
-/* 4-byte magic AS number */
-#define AS_TRANS	23456
+/* macros for IPv6 link-local address */
+#if defined(__KAME__) && defined(IPV6_LINKLOCAL_PEER)
+#define IN6_LINKLOCAL_IFINDEX(addr) \
+        ((addr).s6_addr[2] << 8 | (addr).s6_addr[3])
+
+#define SET_IN6_LINKLOCAL_IFINDEX(addr, index) \
+        do { \
+                (addr).s6_addr[2] = ((index) >> 8) & 0xff; \
+                (addr).s6_addr[3] = (index) & 0xff; \
+        } while (0)
+#endif
 
 /* prototypes */
 /* bgpd.c */
@@ -709,6 +816,7 @@ int		 bgpd_filternexthop(struct kroute *
 
 /* log.c */
 void		 log_init(int);
+void		 log_verbose(int);
 void		 vlog(int, const char *, va_list);
 void		 log_peer_warn(const struct peer_config *, const char *, ...);
 void		 log_peer_warnx(const struct peer_config *, const char *, ...);
@@ -779,11 +887,20 @@ const char	*log_addr(const struct bgpd_a
 const char	*log_in6addr(const struct in6_addr *);
 const char	*log_sockaddr(struct sockaddr *);
 const char	*log_as(u_int32_t);
+const char	*log_rd(u_int64_t);
+const char	*log_ext_subtype(u_int8_t);
 int		 aspath_snprint(char *, size_t, void *, u_int16_t);
 int		 aspath_asprint(char **, void *, u_int16_t);
 size_t		 aspath_strlen(void *, u_int16_t);
 in_addr_t	 prefixlen2mask(u_int8_t);
 void		 inet6applymask(struct in6_addr *, const struct in6_addr *,
 		    int);
+const char	*aid2str(u_int8_t);
+int		 aid2afi(u_int8_t, u_int16_t *, u_int8_t *);
+int		 afi2aid(u_int16_t, u_int8_t, u_int8_t *);
+sa_family_t	 aid2af(u_int8_t);
+int		 af2aid(sa_family_t, u_int8_t, u_int8_t *);
+struct sockaddr	*addr2sa(struct bgpd_addr *, u_int16_t);
+void		 sa2addr(struct sockaddr *, struct bgpd_addr *);
 
 #endif /* __BGPD_H__ */
