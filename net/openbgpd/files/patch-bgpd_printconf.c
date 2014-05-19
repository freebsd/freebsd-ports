Index: bgpd/printconf.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/printconf.c,v
retrieving revision 1.1.1.7
retrieving revision 1.11
diff -u -p -r1.1.1.7 -r1.11
--- bgpd/printconf.c	14 Feb 2010 20:19:57 -0000	1.1.1.7
+++ bgpd/printconf.c	16 May 2014 00:36:26 -0000	1.11
@@ -1,4 +1,4 @@
-/*	$OpenBSD: printconf.c,v 1.70 2009/06/06 01:10:29 claudio Exp $	*/
+/*	$OpenBSD: printconf.c,v 1.88 2012/09/23 09:39:18 claudio Exp $	*/
 
 /*
  * Copyright (c) 2003, 2004 Henning Brauer <henning@openbsd.org>
@@ -16,9 +16,13 @@
  * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
  */
 
+#include <limits.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#if defined(__FreeBSD__)	/* limits.h */
+#include <limits.h>
+#endif
 
 #include "bgpd.h"
 #include "mrt.h"
@@ -27,14 +31,19 @@
 
 void		 print_op(enum comp_ops);
 void		 print_community(int, int);
+void		 print_extcommunity(struct filter_extcommunity *);
+void		 print_origin(u_int8_t);
 void		 print_set(struct filter_set_head *);
 void		 print_mainconf(struct bgpd_config *);
+void		 print_rdomain_targets(struct filter_set_head *, const char *);
+void		 print_rdomain(struct rdomain *);
+const char	*print_af(u_int8_t);
 void		 print_network(struct network_config *);
 void		 print_peer(struct peer_config *, struct bgpd_config *,
 		    const char *);
 const char	*print_auth_alg(u_int8_t);
 const char	*print_enc_alg(u_int8_t);
-const char	*print_safi(u_int8_t);
+void		 print_announce(struct peer_config *, const char *);
 void		 print_rule(struct peer *, struct filter_rule *);
 const char *	 mrt_type(enum mrt_type);
 void		 print_mrt(u_int32_t, u_int32_t, const char *, const char *);
@@ -94,6 +103,45 @@ print_community(int as, int type)
 }
 
 void
+print_extcommunity(struct filter_extcommunity *c)
+{
+	switch (c->type & EXT_COMMUNITY_VALUE) {
+	case EXT_COMMUNITY_TWO_AS:
+		printf("%s %i:%i ", log_ext_subtype(c->subtype),
+		    c->data.ext_as.as, c->data.ext_as.val);
+		break;
+	case EXT_COMMUNITY_IPV4:
+		printf("%s %s:%i ", log_ext_subtype(c->subtype),
+		    inet_ntoa(c->data.ext_ip.addr), c->data.ext_ip.val);
+		break;
+	case EXT_COMMUNITY_FOUR_AS:
+		printf("%s %s:%i ", log_ext_subtype(c->subtype),
+		    log_as(c->data.ext_as4.as4), c->data.ext_as.val);
+		break;
+	case EXT_COMMUNITY_OPAQUE:
+		printf("%s 0x%llx ", log_ext_subtype(c->subtype),
+		    (long long unsigned int)c->data.ext_opaq);
+		break;
+	default:
+		printf("0x%x 0x%llx ", c->type, (long long unsigned int)c->data.ext_opaq);
+		break;
+	}
+}
+
+void
+print_origin(u_int8_t o)
+{
+	if (o == ORIGIN_IGP)
+		printf("igp ");
+	else if (o == ORIGIN_EGP)
+		printf("egp ");
+	else if (o == ORIGIN_INCOMPLETE)
+		printf("incomplete ");
+	else
+		printf("%u ", o);
+}
+
+void
 print_set(struct filter_set_head *set)
 {
 	struct filter_set	*s;
@@ -161,11 +209,23 @@ print_set(struct filter_set_head *set)
 		case ACTION_RTLABEL:
 			printf("rtlabel %s ", s->action.rtlabel);
 			break;
+		case ACTION_SET_ORIGIN:
+			printf("origin ");
+			print_origin(s->action.origin);
+			break;
 		case ACTION_RTLABEL_ID:
 		case ACTION_PFTABLE_ID:
 			/* not possible */
 			printf("king bula saiz: config broken");
 			break;
+		case ACTION_SET_EXT_COMMUNITY:
+			printf("ext-community ");
+			print_extcommunity(&s->action.ext_community);
+			break;
+		case ACTION_DEL_EXT_COMMUNITY:
+			printf("ext-community delete ");
+			print_extcommunity(&s->action.ext_community);
+			break;
 		}
 	}
 	printf("}");
@@ -182,6 +242,10 @@ print_mainconf(struct bgpd_config *conf)
 		printf(" %u", conf->short_as);
 	ina.s_addr = conf->bgpid;
 	printf("\nrouter-id %s\n", inet_ntoa(ina));
+
+	printf("socket \"%s\"\n", conf->csock);
+	if (conf->rcsock)
+		printf("socket \"%s\" restricted\n", conf->rcsock);
 	if (conf->holdtime)
 		printf("holdtime %u\n", conf->holdtime);
 	if (conf->min_holdtime)
@@ -189,11 +253,6 @@ print_mainconf(struct bgpd_config *conf)
 	if (conf->connectretry)
 		printf("connect-retry %u\n", conf->connectretry);
 
-	if (conf->flags & BGPD_FLAG_NO_FIB_UPDATE)
-		printf("fib-update no\n");
-	else
-		printf("fib-update yes\n");
-
 	if (conf->flags & BGPD_FLAG_NO_EVALUATE)
 		printf("route-collector yes\n");
 
@@ -214,43 +273,67 @@ print_mainconf(struct bgpd_config *conf)
 		printf("nexthop qualify via bgp\n");
 	if (conf->flags & BGPD_FLAG_NEXTHOP_DEFAULT)
 		printf("nexthop qualify via default\n");
+}
 
-	if (conf->flags & BGPD_FLAG_REDIST_CONNECTED) {
-		printf("network inet connected");
-		if (!TAILQ_EMPTY(&conf->connectset))
-			printf(" ");
-		print_set(&conf->connectset);
-		printf("\n");
-	}
-	if (conf->flags & BGPD_FLAG_REDIST_STATIC) {
-		printf("network inet static");
-		if (!TAILQ_EMPTY(&conf->staticset))
-			printf(" ");
-		print_set(&conf->staticset);
-		printf("\n");
-	}
-	if (conf->flags & BGPD_FLAG_REDIST6_CONNECTED) {
-		printf("network inet6 connected");
-		if (!TAILQ_EMPTY(&conf->connectset6))
-			printf(" ");
-		print_set(&conf->connectset6);
-		printf("\n");
-	}
-	if (conf->flags & BGPD_FLAG_REDIST_STATIC) {
-		printf("network inet6 static");
-		if (!TAILQ_EMPTY(&conf->staticset6))
-			printf(" ");
-		print_set(&conf->staticset6);
+void
+print_rdomain_targets(struct filter_set_head *set, const char *tgt)
+{
+	struct filter_set	*s;
+	TAILQ_FOREACH(s, set, entry) {
+		printf("\t%s ", tgt);
+		print_extcommunity(&s->action.ext_community);
 		printf("\n");
 	}
-	if (conf->rtableid)
-		printf("rtable %u\n", conf->rtableid);
+}
+
+void
+print_rdomain(struct rdomain *r)
+{
+	printf("rdomain %u {\n", r->rtableid);
+	printf("\tdescr \"%s\"\n", r->descr);
+	if (r->flags & F_RIB_NOFIBSYNC)
+		printf("\tfib-update no\n");
+	else
+		printf("\tfib-update yes\n");
+	printf("\tdepend on %s\n", r->ifmpe);
+
+	printf("\n\t%s\n", log_rd(r->rd));
+
+	print_rdomain_targets(&r->export, "export-target");
+	print_rdomain_targets(&r->import, "import-target");
+
+	printf("}\n");
+}
+
+const char *
+print_af(u_int8_t aid)
+{
+	/*
+	 * Hack around the fact that aid2str() will return "IPv4 unicast"
+	 * for AID_INET. AID_INET and AID_INET6 need special handling and
+	 * the other AID should never end up here (at least for now).
+	 */
+	if (aid == AID_INET)
+		return ("inet");
+	if (aid == AID_INET6)
+		return ("inet6");
+	return (aid2str(aid));
 }
 
 void
 print_network(struct network_config *n)
 {
-	printf("network %s/%u", log_addr(&n->prefix), n->prefixlen);
+	switch (n->type) {
+	case NETWORK_STATIC:
+		printf("network %s static", print_af(n->prefix.aid));
+		break;
+	case NETWORK_CONNECTED:
+		printf("network %s connected", print_af(n->prefix.aid));
+		break;
+	default:
+		printf("network %s/%u", log_addr(&n->prefix), n->prefixlen);
+		break;
+	}
 	if (!TAILQ_EMPTY(&n->attrset))
 		printf(" ");
 	print_set(&n->attrset);
@@ -263,8 +346,8 @@ print_peer(struct peer_config *p, struct
 	char		*method;
 	struct in_addr	 ina;
 
-	if ((p->remote_addr.af == AF_INET && p->remote_masklen != 32) ||
-	    (p->remote_addr.af == AF_INET6 && p->remote_masklen != 128))
+	if ((p->remote_addr.aid == AID_INET && p->remote_masklen != 32) ||
+	    (p->remote_addr.aid == AID_INET6 && p->remote_masklen != 128))
 		printf("%sneighbor %s/%u {\n", c, log_addr(&p->remote_addr),
 		    p->remote_masklen);
 	else
@@ -281,7 +364,7 @@ print_peer(struct peer_config *p, struct
 		printf("%s\tmultihop %u\n", c, p->distance);
 	if (p->passive)
 		printf("%s\tpassive\n", c);
-	if (p->local_addr.af)
+	if (p->local_addr.aid)
 		printf("%s\tlocal-address %s\n", c, log_addr(&p->local_addr));
 	if (p->max_prefix) {
 		printf("%s\tmax-prefix %u", c, p->max_prefix);
@@ -295,6 +378,12 @@ print_peer(struct peer_config *p, struct
 		printf("%s\tholdtime min %u\n", c, p->min_holdtime);
 	if (p->announce_capa == 0)
 		printf("%s\tannounce capabilities no\n", c);
+	if (p->capabilities.refresh == 0)
+		printf("%s\tannounce refresh no\n", c);
+	if (p->capabilities.grestart.restart == 0)
+		printf("%s\tannounce restart no\n", c);
+	if (p->capabilities.as4byte == 0)
+		printf("%s\tannounce as4byte no\n", c);
 	if (p->announce_type == ANNOUNCE_SELF)
 		printf("%s\tannounce self\n", c);
 	else if (p->announce_type == ANNOUNCE_NONE)
@@ -324,6 +413,10 @@ print_peer(struct peer_config *p, struct
 		printf("%s\tdepend on \"%s\"\n", c, p->if_depend);
 	if (p->flags & PEERFLAG_TRANS_AS)
 		printf("%s\ttransparent-as yes\n", c);
+#if defined(IPV6_LINKLOCAL_PEER)
+	if (p->lliface[0])
+		printf("%s\tinterface %s\n", c, p->lliface);
+#endif
 
 	if (p->auth.method == AUTH_MD5SIG)
 		printf("%s\ttcp md5sig\n", c);
@@ -354,8 +447,7 @@ print_peer(struct peer_config *p, struct
 	if (p->ttlsec)
 		printf("%s\tttl-security yes\n", c);
 
-	printf("%s\tannounce IPv4 %s\n", c, print_safi(p->capabilities.mp_v4));
-	printf("%s\tannounce IPv6 %s\n", c, print_safi(p->capabilities.mp_v6));
+	print_announce(p, c);
 
 	if (p->softreconfig_in == 1)
 		printf("%s\tsoftreconfig in yes\n", c);
@@ -399,17 +491,14 @@ print_enc_alg(u_int8_t alg)
 	}
 }
 
-const char *
-print_safi(u_int8_t safi)
+void
+print_announce(struct peer_config *p, const char *c)
 {
-	switch (safi) {
-	case SAFI_NONE:
-		return ("none");
-	case SAFI_UNICAST:
-		return ("unicast");
-	default:
-		return ("?");
-	}
+	u_int8_t	aid;
+
+	for (aid = 0; aid < AID_MAX; aid++)
+		if (p->capabilities.mp[aid])
+			printf("%s\tannounce %s\n", c, aid2str(aid));
 }
 
 void
@@ -455,14 +544,14 @@ print_rule(struct peer *peer_l, struct f
 	} else
 		printf("any ");
 
-	if (r->match.prefix.addr.af)
+	if (r->match.prefix.addr.aid)
 		printf("prefix %s/%u ", log_addr(&r->match.prefix.addr),
 		    r->match.prefix.len);
 
-	if (r->match.prefix.addr.af == 0 && r->match.prefixlen.af) {
-		if (r->match.prefixlen.af == AF_INET)
+	if (r->match.prefix.addr.aid == 0 && r->match.prefixlen.aid) {
+		if (r->match.prefixlen.aid == AID_INET)
 			printf("inet ");
-		if (r->match.prefixlen.af == AF_INET6)
+		if (r->match.prefixlen.aid == AID_INET6)
 			printf("inet6 ");
 	}
 
@@ -479,6 +568,13 @@ print_rule(struct peer *peer_l, struct f
 		}
 	}
 
+	if (r->match.nexthop.flags) {
+		if (r->match.nexthop.flags == FILTER_NEXTHOP_NEIGHBOR)
+			printf("nexthop neighbor ");
+		else
+			printf("nexthop %s ", log_addr(&r->match.nexthop.addr));
+	}
+
 	if (r->match.as.type) {
 		if (r->match.as.type == AS_ALL)
 			printf("AS %s ", log_as(r->match.as.as));
@@ -492,11 +588,20 @@ print_rule(struct peer *peer_l, struct f
 			printf("unfluffy-as %s ", log_as(r->match.as.as));
 	}
 
+	if (r->match.aslen.type) {
+		printf("%s %u ", r->match.aslen.type == ASLEN_MAX ?
+		    "max-as-len" : "max-as-seq", r->match.aslen.aslen);
+	}
+
 	if (r->match.community.as != COMMUNITY_UNSET) {
 		printf("community ");
 		print_community(r->match.community.as,
 		    r->match.community.type);
 	}
+	if (r->match.ext_community.flags & EXT_COMMUNITY_FLAG_VALID) {
+		printf("ext-community ");
+		print_extcommunity(&r->match.ext_community);
+	}
 
 	print_set(&r->set);
 
@@ -513,6 +618,8 @@ mrt_type(enum mrt_type t)
 		return "table";
 	case MRT_TABLE_DUMP_MP:
 		return "table-mp";
+	case MRT_TABLE_DUMP_V2:
+		return "table-v2";
 	case MRT_ALL_IN:
 		return "all in";
 	case MRT_ALL_OUT:
@@ -541,12 +648,12 @@ print_mrt(u_int32_t pid, u_int32_t gid, 
 			printf("%s%sdump ", prep, prep2);
 			if (m->rib[0])
 				printf("rib %s ", m->rib);
+			printf("%s \"%s\"", mrt_type(m->type),
+			    MRT2MC(m)->name);
 			if (MRT2MC(m)->ReopenTimerInterval == 0)
-				printf("%s %s\n", mrt_type(m->type),
-				    MRT2MC(m)->name);
+				printf("\n");
 			else
-				printf("%s %s %d\n", mrt_type(m->type),
-				    MRT2MC(m)->name,
+				printf(" %ld\n",
 				    MRT2MC(m)->ReopenTimerInterval);
 		}
 }
@@ -612,26 +719,34 @@ peer_compare(const void *aa, const void 
 void
 print_config(struct bgpd_config *conf, struct rib_names *rib_l,
     struct network_head *net_l, struct peer *peer_l,
-    struct filter_head *rules_l, struct mrt_head *mrt_l)
+    struct filter_head *rules_l, struct mrt_head *mrt_l,
+    struct rdomain_head *rdom_l)
 {
 	struct filter_rule	*r;
 	struct network		*n;
 	struct rde_rib		*rr;
+	struct rdomain		*rd;
 
 	xmrt_l = mrt_l;
-	printf("\n");
 	print_mainconf(conf);
 	printf("\n");
+	TAILQ_FOREACH(n, net_l, entry)
+		print_network(&n->net);
+	printf("\n");
+	SIMPLEQ_FOREACH(rd, rdom_l, entry)
+		print_rdomain(rd);
+	printf("\n");
 	SIMPLEQ_FOREACH(rr, rib_l, entry) {
 		if (rr->flags & F_RIB_NOEVALUATE)
 			printf("rde rib %s no evaluate\n", rr->name);
-		else
+		else if (rr->flags & F_RIB_NOFIB)
 			printf("rde rib %s\n", rr->name);
+		else
+			printf("rde rib %s rtable %u fib-update %s\n", rr->name,
+			    rr->rtableid, rr->flags & F_RIB_NOFIBSYNC ?
+			    "no" : "yes");
 	}
 	printf("\n");
-	TAILQ_FOREACH(n, net_l, entry)
-		print_network(&n->net);
-	printf("\n");
 	print_mrt(0, 0, "", "");
 	printf("\n");
 	print_groups(conf, peer_l);
