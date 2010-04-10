Index: bgpd/printconf.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/printconf.c,v
retrieving revision 1.1.1.7
retrieving revision 1.7
diff -u -p -r1.1.1.7 -r1.7
--- bgpd/printconf.c	14 Feb 2010 20:19:57 -0000	1.1.1.7
+++ bgpd/printconf.c	10 Apr 2010 12:16:23 -0000	1.7
@@ -1,4 +1,4 @@
-/*	$OpenBSD: printconf.c,v 1.70 2009/06/06 01:10:29 claudio Exp $	*/
+/*	$OpenBSD: printconf.c,v 1.79 2010/03/05 15:25:00 claudio Exp $	*/
 
 /*
  * Copyright (c) 2003, 2004 Henning Brauer <henning@openbsd.org>
@@ -19,6 +19,9 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#if defined(__FreeBSD__)	/* limits.h */
+#include <limits.h>
+#endif
 
 #include "bgpd.h"
 #include "mrt.h"
@@ -27,6 +30,8 @@
 
 void		 print_op(enum comp_ops);
 void		 print_community(int, int);
+void		 print_extcommunity(struct filter_extcommunity *);
+void		 print_origin(u_int8_t);
 void		 print_set(struct filter_set_head *);
 void		 print_mainconf(struct bgpd_config *);
 void		 print_network(struct network_config *);
@@ -34,7 +39,7 @@ void		 print_peer(struct peer_config *, 
 		    const char *);
 const char	*print_auth_alg(u_int8_t);
 const char	*print_enc_alg(u_int8_t);
-const char	*print_safi(u_int8_t);
+void		 print_announce(struct peer_config *, const char *);
 void		 print_rule(struct peer *, struct filter_rule *);
 const char *	 mrt_type(enum mrt_type);
 void		 print_mrt(u_int32_t, u_int32_t, const char *, const char *);
@@ -94,6 +99,45 @@ print_community(int as, int type)
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
+		    c->data.ext_opaq);
+		break;
+	default:
+		printf("0x%x 0x%llx ", c->type, c->data.ext_opaq);
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
@@ -161,11 +205,23 @@ print_set(struct filter_set_head *set)
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
@@ -236,7 +292,7 @@ print_mainconf(struct bgpd_config *conf)
 		print_set(&conf->connectset6);
 		printf("\n");
 	}
-	if (conf->flags & BGPD_FLAG_REDIST_STATIC) {
+	if (conf->flags & BGPD_FLAG_REDIST6_STATIC) {
 		printf("network inet6 static");
 		if (!TAILQ_EMPTY(&conf->staticset6))
 			printf(" ");
@@ -263,8 +319,8 @@ print_peer(struct peer_config *p, struct
 	char		*method;
 	struct in_addr	 ina;
 
-	if ((p->remote_addr.af == AF_INET && p->remote_masklen != 32) ||
-	    (p->remote_addr.af == AF_INET6 && p->remote_masklen != 128))
+	if ((p->remote_addr.aid == AID_INET && p->remote_masklen != 32) ||
+	    (p->remote_addr.aid == AID_INET6 && p->remote_masklen != 128))
 		printf("%sneighbor %s/%u {\n", c, log_addr(&p->remote_addr),
 		    p->remote_masklen);
 	else
@@ -281,7 +337,7 @@ print_peer(struct peer_config *p, struct
 		printf("%s\tmultihop %u\n", c, p->distance);
 	if (p->passive)
 		printf("%s\tpassive\n", c);
-	if (p->local_addr.af)
+	if (p->local_addr.aid)
 		printf("%s\tlocal-address %s\n", c, log_addr(&p->local_addr));
 	if (p->max_prefix) {
 		printf("%s\tmax-prefix %u", c, p->max_prefix);
@@ -295,6 +351,12 @@ print_peer(struct peer_config *p, struct
 		printf("%s\tholdtime min %u\n", c, p->min_holdtime);
 	if (p->announce_capa == 0)
 		printf("%s\tannounce capabilities no\n", c);
+	if (p->capabilities.refresh == 0)
+		printf("%s\tannounce refresh no\n", c);
+	if (p->capabilities.restart == 1)
+		printf("%s\tannounce restart yes\n", c);
+	if (p->capabilities.as4byte == 0)
+		printf("%s\tannounce as4byte no\n", c);
 	if (p->announce_type == ANNOUNCE_SELF)
 		printf("%s\tannounce self\n", c);
 	else if (p->announce_type == ANNOUNCE_NONE)
@@ -324,6 +386,10 @@ print_peer(struct peer_config *p, struct
 		printf("%s\tdepend on \"%s\"\n", c, p->if_depend);
 	if (p->flags & PEERFLAG_TRANS_AS)
 		printf("%s\ttransparent-as yes\n", c);
+#if defined(IPV6_LINKLOCAL_PEER)
+	if (p->lliface[0])
+		printf("%s\tinterface %s\n", c, p->lliface);
+#endif
 
 	if (p->auth.method == AUTH_MD5SIG)
 		printf("%s\ttcp md5sig\n", c);
@@ -354,8 +420,7 @@ print_peer(struct peer_config *p, struct
 	if (p->ttlsec)
 		printf("%s\tttl-security yes\n", c);
 
-	printf("%s\tannounce IPv4 %s\n", c, print_safi(p->capabilities.mp_v4));
-	printf("%s\tannounce IPv6 %s\n", c, print_safi(p->capabilities.mp_v6));
+	print_announce(p, c);
 
 	if (p->softreconfig_in == 1)
 		printf("%s\tsoftreconfig in yes\n", c);
@@ -399,17 +464,14 @@ print_enc_alg(u_int8_t alg)
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
@@ -455,14 +517,14 @@ print_rule(struct peer *peer_l, struct f
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
 
@@ -497,6 +559,10 @@ print_rule(struct peer *peer_l, struct f
 		print_community(r->match.community.as,
 		    r->match.community.type);
 	}
+	if (r->match.ext_community.flags & EXT_COMMUNITY_FLAG_VALID) {
+		printf("ext-community ");
+		print_extcommunity(&r->match.ext_community);
+	}
 
 	print_set(&r->set);
 
