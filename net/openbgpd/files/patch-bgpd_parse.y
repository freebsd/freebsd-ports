Index: bgpd/parse.y
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/parse.y,v
retrieving revision 1.1.1.8
retrieving revision 1.12
diff -u -p -r1.1.1.8 -r1.12
--- bgpd/parse.y	14 Feb 2010 20:19:57 -0000	1.1.1.8
+++ bgpd/parse.y	8 Dec 2012 20:17:59 -0000	1.12
@@ -1,4 +1,4 @@
-/*	$OpenBSD: parse.y,v 1.231 2009/06/06 01:10:29 claudio Exp $ */
+/*	$OpenBSD: parse.y,v 1.264 2012/09/23 09:39:17 claudio Exp $ */
 
 /*
  * Copyright (c) 2002, 2003, 2004 Henning Brauer <henning@openbsd.org>
@@ -25,7 +25,10 @@
 #include <sys/stat.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
-
+#if !defined(__FreeBSD__) /* FreeBSD has no mpls support. */
+#include <netmpls/mpls.h>
+#endif
+	
 #include <ctype.h>
 #include <err.h>
 #include <unistd.h>
@@ -33,6 +36,9 @@
 #include <limits.h>
 #include <stdarg.h>
 #include <stdio.h>
+#if defined(__FreeBSD__)
+#include <stdlib.h>
+#endif
 #include <string.h>
 #include <syslog.h>
 
@@ -74,10 +80,12 @@ char		*symget(const char *);
 
 static struct bgpd_config	*conf;
 static struct mrt_head		*mrtconf;
-static struct network_head	*netconf;
+static struct network_head	*netconf, *gnetconf;
 static struct peer		*peer_l, *peer_l_old;
 static struct peer		*curpeer;
 static struct peer		*curgroup;
+static struct rdomain		*currdom;
+static struct rdomain_head	*rdom_l;
 static struct filter_head	*filter_l;
 static struct filter_head	*peerfilter_l;
 static struct filter_head	*groupfilter_l;
@@ -105,7 +113,7 @@ struct filter_match_l {
 	struct filter_match	 m;
 	struct filter_prefix_l	*prefix_l;
 	struct filter_as_l	*as_l;
-	sa_family_t		 af;
+	u_int8_t		 aid;
 } fmopts;
 
 struct peer	*alloc_peer(void);
@@ -113,8 +121,8 @@ struct peer	*new_peer(void);
 struct peer	*new_group(void);
 int		 add_mrtconfig(enum mrt_type, char *, time_t, struct peer *,
 		    char *);
-int		 add_rib(char *, u_int16_t);
-int		 find_rib(char *);
+int		 add_rib(char *, u_int, u_int16_t);
+struct rde_rib	*find_rib(char *);
 int		 get_id(struct peer *);
 int		 expand_rule(struct filter_rule *, struct filter_peers_l *,
 		    struct filter_match_l *, struct filter_set_head *);
@@ -123,12 +131,14 @@ int		 neighbor_consistent(struct peer *)
 int		 merge_filterset(struct filter_set_head *, struct filter_set *);
 void		 copy_filterset(struct filter_set_head *,
 		    struct filter_set_head *);
-void		 move_filterset(struct filter_set_head *,
-		    struct filter_set_head *);
 struct filter_rule	*get_rule(enum action_types);
 
 int		 getcommunity(char *);
-int		 parsecommunity(char *, int *, int *);
+int		 parsecommunity(struct filter_community *, char *);
+int		 parsesubtype(char *);
+int		 parseextvalue(char *, u_int32_t *);
+int		 parseextcommunity(struct filter_extcommunity *, char *,
+		    char *);
 
 typedef struct {
 	union {
@@ -159,29 +169,33 @@ typedef struct {
 %}
 
 %token	AS ROUTERID HOLDTIME YMIN LISTEN ON FIBUPDATE RTABLE
+%token	RDOMAIN RD EXPORTTRGT IMPORTTRGT
 %token	RDE RIB EVALUATE IGNORE COMPARE
 %token	GROUP NEIGHBOR NETWORK
-%token	REMOTEAS DESCR LOCALADDR MULTIHOP PASSIVE MAXPREFIX RESTART
-%token	ANNOUNCE DEMOTE CONNECTRETRY
-%token	ENFORCE NEIGHBORAS CAPABILITIES REFLECTOR DEPEND DOWN SOFTRECONFIG
-%token	DUMP IN OUT
+%token	REMOTEAS DESCR LLIFACE LOCALADDR MULTIHOP PASSIVE MAXPREFIX RESTART
+%token	ANNOUNCE CAPABILITIES REFRESH AS4BYTE CONNECTRETRY
+%token	DEMOTE ENFORCE NEIGHBORAS REFLECTOR DEPEND DOWN SOFTRECONFIG
+%token	DUMP IN OUT SOCKET RESTRICTED
 %token	LOG ROUTECOLL TRANSPARENT
 %token	TCP MD5SIG PASSWORD KEY TTLSECURITY
 %token	ALLOW DENY MATCH
 %token	QUICK
 %token	FROM TO ANY
 %token	CONNECTED STATIC
-%token	PREFIX PREFIXLEN SOURCEAS TRANSITAS PEERAS COMMUNITY DELETE
+%token	COMMUNITY EXTCOMMUNITY
+%token	PREFIX PREFIXLEN SOURCEAS TRANSITAS PEERAS DELETE MAXASLEN MAXASSEQ
 %token	SET LOCALPREF MED METRIC NEXTHOP REJECT BLACKHOLE NOMODIFY SELF
-%token	PREPEND_SELF PREPEND_PEER PFTABLE WEIGHT RTLABEL
+%token	PREPEND_SELF PREPEND_PEER PFTABLE WEIGHT RTLABEL ORIGIN
 %token	ERROR INCLUDE
 %token	IPSEC ESP AH SPI IKE
 %token	IPV4 IPV6
 %token	QUALIFY VIA
+%token	NE LE GE XRANGE
 %token	<v.string>		STRING
 %token	<v.number>		NUMBER
-%type	<v.number>		asnumber as4number optnumber yesno inout
-%type	<v.number>		espah family restart
+%type	<v.number>		asnumber as4number optnumber
+%type	<v.number>		espah family restart origincode nettype
+%type	<v.number>		yesno inout restricted
 %type	<v.string>		string filter_rib
 %type	<v.addr>		address
 %type	<v.prefix>		prefix addrspec
@@ -204,6 +218,7 @@ grammar		: /* empty */
 		| grammar include '\n'
 		| grammar conf_main '\n'
 		| grammar varset '\n'
+		| grammar rdomain '\n'
 		| grammar neighbor '\n'
 		| grammar group '\n'
 		| grammar filterrule '\n'
@@ -211,8 +226,12 @@ grammar		: /* empty */
 		;
 
 asnumber	: NUMBER			{
-			if ($1 < 0 || $1 >= ASNUM_MAX) {
-				yyerror("AS too big: max %u", ASNUM_MAX - 1);
+			/*
+			 * Accroding to iana 65535 and 4294967295 are reserved
+			 * but enforcing this is not duty of the parser.
+			 */
+			if ($1 < 0 || $1 > UINT_MAX) {
+				yyerror("AS too big: max %u", UINT_MAX);
 				YYERROR;
 			}
 		}
@@ -274,6 +293,8 @@ yesno		:  STRING			{
 			else if (!strcmp($1, "no"))
 				$$ = 0;
 			else {
+				yyerror("syntax error, "
+				    "either yes or no expected");
 				free($1);
 				YYERROR;
 			}
@@ -318,7 +339,7 @@ conf_main	: AS as4number		{
 			conf->short_as = $3;
 		}
 		| ROUTERID address		{
-			if ($2.af != AF_INET) {
+			if ($2.aid != AID_INET) {
 				yyerror("router-id must be an IPv4 address");
 				YYERROR;
 			}
@@ -342,42 +363,25 @@ conf_main	: AS as4number		{
 		}
 		| LISTEN ON address	{
 			struct listen_addr	*la;
-			struct sockaddr_in	*in;
-			struct sockaddr_in6	*in6;
 
 			if ((la = calloc(1, sizeof(struct listen_addr))) ==
 			    NULL)
 				fatal("parse conf_main listen on calloc");
 
 			la->fd = -1;
-			la->sa.ss_family = $3.af;
-			switch ($3.af) {
-			case AF_INET:
-				la->sa.ss_len = sizeof(struct sockaddr_in);
-				in = (struct sockaddr_in *)&la->sa;
-				in->sin_addr.s_addr = $3.v4.s_addr;
-				in->sin_port = htons(BGP_PORT);
-				break;
-			case AF_INET6:
-				la->sa.ss_len = sizeof(struct sockaddr_in6);
-				in6 = (struct sockaddr_in6 *)&la->sa;
-				memcpy(&in6->sin6_addr, &$3.v6,
-				    sizeof(in6->sin6_addr));
-				in6->sin6_port = htons(BGP_PORT);
-				break;
-			default:
-				yyerror("king bula does not like family %u",
-				    $3.af);
-				YYERROR;
-			}
-
+			memcpy(&la->sa, addr2sa(&$3, BGP_PORT), sizeof(la->sa));
 			TAILQ_INSERT_TAIL(listen_addrs, la, entry);
 		}
 		| FIBUPDATE yesno		{
+			struct rde_rib *rr;
+			rr = find_rib("Loc-RIB");
+			if (rr == NULL)
+				fatalx("RTABLE can not find the main RIB!");
+
 			if ($2 == 0)
-				conf->flags |= BGPD_FLAG_NO_FIB_UPDATE;
+				rr->flags |= F_RIB_NOFIBSYNC;
 			else
-				conf->flags &= ~BGPD_FLAG_NO_FIB_UPDATE;
+				rr->flags &= ~F_RIB_NOFIBSYNC;
 		}
 		| ROUTECOLL yesno	{
 			if ($2 == 1)
@@ -386,7 +390,7 @@ conf_main	: AS as4number		{
 				conf->flags &= ~BGPD_FLAG_NO_EVALUATE;
 		}
 		| RDE RIB STRING {
-			if (add_rib($3, F_RIB_NOFIB)) {
+			if (add_rib($3, 0, F_RIB_NOFIB)) {
 				free($3);
 				YYERROR;
 			}
@@ -395,9 +399,27 @@ conf_main	: AS as4number		{
 		| RDE RIB STRING yesno EVALUATE {
 			if ($4) {
 				free($3);
+				yyerror("bad rde rib definition");
 				YYERROR;
 			}
-			if (!add_rib($3, F_RIB_NOEVALUATE)) {
+			if (add_rib($3, 0, F_RIB_NOFIB | F_RIB_NOEVALUATE)) {
+				free($3);
+				YYERROR;
+			}
+			free($3);
+		}
+		| RDE RIB STRING RTABLE NUMBER {
+			if (add_rib($3, $5, 0)) {
+				free($3);
+				YYERROR;
+			}
+			free($3);
+		}
+		| RDE RIB STRING RTABLE NUMBER FIBUPDATE yesno {
+			int	flags = 0;
+			if ($7 == 0)
+				flags = F_RIB_NOFIBSYNC;
+			if (add_rib($3, $5, flags)) {
 				free($3);
 				YYERROR;
 			}
@@ -418,59 +440,7 @@ conf_main	: AS as4number		{
 			}
 			free($2);
 		}
-		| NETWORK prefix filter_set	{
-			struct network	*n;
-
-			if ((n = calloc(1, sizeof(struct network))) == NULL)
-				fatal("new_network");
-			memcpy(&n->net.prefix, &$2.prefix,
-			    sizeof(n->net.prefix));
-			n->net.prefixlen = $2.len;
-			move_filterset($3, &n->net.attrset);
-			free($3);
-
-			TAILQ_INSERT_TAIL(netconf, n, entry);
-		}
-		| NETWORK family STATIC filter_set	{
-			if ($2 == AFI_IPv4) {
-				conf->flags |= BGPD_FLAG_REDIST_STATIC;
-				move_filterset($4, &conf->staticset);
-			} else if ($2 == AFI_IPv6) {
-				conf->flags |= BGPD_FLAG_REDIST6_STATIC;
-				move_filterset($4, &conf->staticset6);
-			} else {
-				yyerror("unknown family");
-				free($4);
-				YYERROR;
-			}
-			free($4);
-		}
-		| NETWORK family CONNECTED filter_set	{
-			if ($2 == AFI_IPv4) {
-				conf->flags |= BGPD_FLAG_REDIST_CONNECTED;
-				move_filterset($4, &conf->connectset);
-			} else if ($2 == AFI_IPv6) {
-				conf->flags |= BGPD_FLAG_REDIST6_CONNECTED;
-				move_filterset($4, &conf->connectset6);
-			} else {
-				yyerror("unknown family");
-				free($4);
-				YYERROR;
-			}
-			free($4);
-		}
-		| NETWORK STATIC filter_set	{
-			/* keep for compatibility till after next release */
-			conf->flags |= BGPD_FLAG_REDIST_STATIC;
-			move_filterset($3, &conf->staticset);
-			free($3);
-		}
-		| NETWORK CONNECTED filter_set	{
-			/* keep for compatibility till after next release */
-			conf->flags |= BGPD_FLAG_REDIST_CONNECTED;
-			move_filterset($3, &conf->connectset);
-			free($3);
-		}
+		| network
 		| DUMP STRING STRING optnumber		{
 			int action;
 
@@ -484,6 +454,8 @@ conf_main	: AS as4number		{
 				action = MRT_TABLE_DUMP;
 			else if (!strcmp($2, "table-mp"))
 				action = MRT_TABLE_DUMP_MP;
+			else if (!strcmp($2, "table-v2"))
+				action = MRT_TABLE_DUMP_V2;
 			else {
 				yyerror("unknown mrt dump type");
 				free($2);
@@ -511,6 +483,8 @@ conf_main	: AS as4number		{
 				action = MRT_TABLE_DUMP;
 			else if (!strcmp($4, "table-mp"))
 				action = MRT_TABLE_DUMP_MP;
+			else if (!strcmp($4, "table-v2"))
+				action = MRT_TABLE_DUMP_V2;
 			else {
 				yyerror("unknown mrt dump type");
 				free($3);
@@ -575,11 +549,20 @@ conf_main	: AS as4number		{
 			free($4);
 		}
 		| RTABLE NUMBER {
-			if ($2 > RT_TABLEID_MAX || $2 < 0) {
-				yyerror("invalid rtable id");
+#if defined(__FreeBSD__)	/* FreeBSD does not support RTABLE */
+			yyerror("rtable id not supported in FreeBSD, yet");
+			YYERROR;
+#else
+			struct rde_rib *rr;
+			if (ktable_exists($2, NULL) != 1) {
+				yyerror("rtable id %lld does not exist", $2);
 				YYERROR;
 			}
-			conf->rtableid = $2;
+			rr = find_rib("Loc-RIB");
+			if (rr == NULL)
+				fatalx("RTABLE can not find the main RIB!");
+			rr->rtableid = $2;
+#endif /* defined(__FreeBSD__) */
 		}
 		| CONNECTRETRY NUMBER {
 			if ($2 > USHRT_MAX || $2 < 1) {
@@ -588,6 +571,15 @@ conf_main	: AS as4number		{
 			}
 			conf->connectretry = $2;
 		}
+		| SOCKET STRING	restricted {
+			if ($3) {
+				free(conf->rcsock);
+				conf->rcsock = $2;
+			} else {
+				free(conf->csock);
+				conf->csock = $2;
+			}
+		}
 		;
 
 mrtdump		: DUMP STRING inout STRING optnumber	{
@@ -620,10 +612,47 @@ mrtdump		: DUMP STRING inout STRING optn
 		}
 		;
 
+network		: NETWORK prefix filter_set	{
+			struct network	*n;
+
+			if ((n = calloc(1, sizeof(struct network))) == NULL)
+				fatal("new_network");
+			memcpy(&n->net.prefix, &$2.prefix,
+			    sizeof(n->net.prefix));
+			n->net.prefixlen = $2.len;
+			filterset_move($3, &n->net.attrset);
+			free($3);
+
+			TAILQ_INSERT_TAIL(netconf, n, entry);
+		}
+		| NETWORK family nettype filter_set	{
+			struct network	*n;
+
+			if ((n = calloc(1, sizeof(struct network))) == NULL)
+				fatal("new_network");
+			if (afi2aid($2, SAFI_UNICAST, &n->net.prefix.aid) ==
+			    -1) {
+				yyerror("unknown family");
+				filterset_free($4);
+				free($4);
+				YYERROR;
+			}
+			n->net.type = $3 ? NETWORK_STATIC : NETWORK_CONNECTED;
+			filterset_move($4, &n->net.attrset);
+			free($4);
+
+			TAILQ_INSERT_TAIL(netconf, n, entry);
+		}
+		;
+
 inout		: IN		{ $$ = 1; }
 		| OUT		{ $$ = 0; }
 		;
 
+restricted	: RESTRICTED	{ $$ = 1; }
+		| /* nothing */	{ $$ = 0; }
+		;
+
 address		: STRING		{
 			u_int8_t	len;
 
@@ -635,11 +664,11 @@ address		: STRING		{
 			}
 			free($1);
 
-			if (($$.af == AF_INET && len != 32) ||
-			    ($$.af == AF_INET6 && len != 128)) {
+			if (($$.aid == AID_INET && len != 32) ||
+			    ($$.aid == AID_INET6 && len != 128)) {
 				/* unreachable */
 				yyerror("got prefixlen %u, expected %u",
-				    len, $$.af == AF_INET ? 32 : 128);
+				    len, $$.aid == AID_INET ? 32 : 128);
 				YYERROR;
 			}
 		}
@@ -653,7 +682,7 @@ prefix		: STRING '/' NUMBER	{
 				free($1);
 				YYERROR;
 			}
-			if (asprintf(&s, "%s/%lld", $1, $3) == -1)
+			if (asprintf(&s, "%s/%lld", $1, (long long int)$3) == -1)
 				fatal(NULL);
 			free($1);
 
@@ -672,7 +701,7 @@ prefix		: STRING '/' NUMBER	{
 				yyerror("bad prefix %lld/%lld", $1, $3);
 				YYERROR;
 			}
-			if (asprintf(&s, "%lld/%lld", $1, $3) == -1)
+			if (asprintf(&s, "%lld/%lld", (long long int)$1, (long long int)$3) == -1)
 				fatal(NULL);
 
 			if (!host(s, &$$.prefix, &$$.len)) {
@@ -686,7 +715,7 @@ prefix		: STRING '/' NUMBER	{
 
 addrspec	: address	{
 			memcpy(&$$.prefix, &$1, sizeof(struct bgpd_addr));
-			if ($$.prefix.af == AF_INET)
+			if ($$.prefix.aid == AID_INET)
 				$$.len = 32;
 			else
 				$$.len = 128;
@@ -705,14 +734,150 @@ optnumber	: /* empty */		{ $$ = 0; }
 		| NUMBER
 		;
 
+rdomain		: RDOMAIN NUMBER optnl '{' optnl	{
+			if (ktable_exists($2, NULL) != 1) {
+				yyerror("rdomain %lld does not exist", $2);
+				YYERROR;
+			}
+			if (!(currdom = calloc(1, sizeof(struct rdomain))))
+				fatal(NULL);
+			currdom->rtableid = $2;
+			TAILQ_INIT(&currdom->import);
+			TAILQ_INIT(&currdom->export);
+			TAILQ_INIT(&currdom->net_l);
+			netconf = &currdom->net_l;
+		}
+		    rdomainopts_l '}' {
+			/* insert into list */
+			SIMPLEQ_INSERT_TAIL(rdom_l, currdom, entry);
+			currdom = NULL;
+			netconf = gnetconf;
+		}
+
+rdomainopts_l	: rdomainopts_l rdomainoptsl
+		| rdomainoptsl
+		;
+
+rdomainoptsl	: rdomainopts nl
+		;
+
+rdomainopts	: RD STRING {
+			struct filter_extcommunity	ext;
+			u_int64_t			rd;
+
+			if (parseextcommunity(&ext, "rt", $2) == -1) {
+				free($2);
+				YYERROR;
+			}
+			free($2);
+			/*
+			 * RD is almost encode like an ext-community,
+			 * but only almost so convert here.
+			 */
+			if (community_ext_conv(&ext, 0, &rd)) {
+				yyerror("bad encoding of rd");
+				YYERROR;
+			}
+			rd = betoh64(rd) & 0xffffffffffffULL;
+			switch (ext.type) {
+			case EXT_COMMUNITY_TWO_AS:
+				rd |= (0ULL << 48);
+				break;
+			case EXT_COMMUNITY_IPV4:
+				rd |= (1ULL << 48);
+				break;
+			case EXT_COMMUNITY_FOUR_AS:
+				rd |= (2ULL << 48);
+				break;
+			default:
+				yyerror("bad encoding of rd");
+				YYERROR;
+			}
+			currdom->rd = htobe64(rd);
+		}
+		| EXPORTTRGT STRING STRING	{
+			struct filter_set	*set;
+
+			if ((set = calloc(1, sizeof(struct filter_set))) ==
+			    NULL)
+				fatal(NULL);
+			set->type = ACTION_SET_EXT_COMMUNITY;
+			if (parseextcommunity(&set->action.ext_community,
+			    $2, $3) == -1) {
+				free($3);
+				free($2);
+				free(set);
+				YYERROR;
+			}
+			free($3);
+			free($2);
+			TAILQ_INSERT_TAIL(&currdom->export, set, entry);
+		}
+		| IMPORTTRGT STRING STRING	{
+			struct filter_set	*set;
+
+			if ((set = calloc(1, sizeof(struct filter_set))) ==
+			    NULL)
+				fatal(NULL);
+			set->type = ACTION_SET_EXT_COMMUNITY;
+			if (parseextcommunity(&set->action.ext_community,
+			    $2, $3) == -1) {
+				free($3);
+				free($2);
+				free(set);
+				YYERROR;
+			}
+			free($3);
+			free($2);
+			TAILQ_INSERT_TAIL(&currdom->import, set, entry);
+		}
+		| DESCR string		{
+			if (strlcpy(currdom->descr, $2,
+			    sizeof(currdom->descr)) >=
+			    sizeof(currdom->descr)) {
+				yyerror("descr \"%s\" too long: max %u",
+				    $2, sizeof(currdom->descr) - 1);
+				free($2);
+				YYERROR;
+			}
+			free($2);
+		}
+		| FIBUPDATE yesno		{
+			if ($2 == 0)
+				currdom->flags |= F_RIB_NOFIBSYNC;
+			else
+				currdom->flags &= ~F_RIB_NOFIBSYNC;
+		}
+		| network
+		| DEPEND ON STRING	{
+			/* XXX this is a hack */
+			if (if_nametoindex($3) == 0) {
+				yyerror("interface %s does not exist", $3);
+				free($3);
+				YYERROR;
+			}
+			strlcpy(currdom->ifmpe, $3, IFNAMSIZ);
+			free($3);
+			if (get_mpe_label(currdom)) {
+				yyerror("failed to get mpls label from %s",
+				    currdom->ifmpe);
+				YYERROR;
+			}
+		}
+		;
+
 neighbor	: {	curpeer = new_peer(); }
 		    NEIGHBOR addrspec {
 			memcpy(&curpeer->conf.remote_addr, &$3.prefix,
 			    sizeof(curpeer->conf.remote_addr));
 			curpeer->conf.remote_masklen = $3.len;
-			if (($3.prefix.af == AF_INET && $3.len != 32) ||
-			    ($3.prefix.af == AF_INET6 && $3.len != 128))
+			if (($3.prefix.aid == AID_INET && $3.len != 32) ||
+			    ($3.prefix.aid == AID_INET6 && $3.len != 128))
 				curpeer->conf.template = 1;
+			if (curpeer->conf.capabilities.mp[
+			    curpeer->conf.remote_addr.aid] == -1)
+				curpeer->conf.capabilities.mp[
+				    curpeer->conf.remote_addr.aid] = 1;
 			if (get_id(curpeer)) {
 				yyerror("get_id failed");
 				YYERROR;
@@ -802,6 +967,17 @@ peeropts	: REMOTEAS as4number	{
 			}
 			free($2);
 		}
+		| LLIFACE string	{
+			if (strlcpy(curpeer->conf.lliface, $2,
+			    sizeof(curpeer->conf.lliface)) >=
+			    sizeof(curpeer->conf.lliface)) {
+				yyerror("lliface \"%s\" too long: max %u",
+				    $2, sizeof(curpeer->conf.lliface) - 1);
+				free($2);
+				YYERROR;
+			}
+			free($2);
+	        }
 		| LOCALADDR address	{
 			memcpy(&curpeer->conf.local_addr, &$2,
 			    sizeof(curpeer->conf.local_addr));
@@ -852,13 +1028,17 @@ peeropts	: REMOTEAS as4number	{
 			curpeer->conf.min_holdtime = $3;
 		}
 		| ANNOUNCE family STRING {
-			u_int8_t	safi;
+			u_int8_t	aid, safi;
+			int8_t		val = 1;
 
-			if (!strcmp($3, "none"))
-				safi = SAFI_NONE;
-			else if (!strcmp($3, "unicast"))
+			if (!strcmp($3, "none")) {
 				safi = SAFI_UNICAST;
-			else {
+				val = 0;
+			} else if (!strcmp($3, "unicast")) {
+				safi = SAFI_UNICAST;
+			} else if (!strcmp($3, "vpn")) {
+				safi = SAFI_MPLSVPN;
+			} else {
 				yyerror("unknown/unsupported SAFI \"%s\"",
 				    $3);
 				free($3);
@@ -866,25 +1046,31 @@ peeropts	: REMOTEAS as4number	{
 			}
 			free($3);
 
-			switch ($2) {
-			case AFI_IPv4:
-				curpeer->conf.capabilities.mp_v4 = safi;
-				break;
-			case AFI_IPv6:
-				curpeer->conf.capabilities.mp_v6 = safi;
-				break;
-			default:
-				fatal("king bula sees borked AFI");
+			if (afi2aid($2, safi, &aid) == -1) {
+				yyerror("unknown AFI/SAFI pair");
+				YYERROR;
 			}
+			curpeer->conf.capabilities.mp[aid] = val;
 		}
 		| ANNOUNCE CAPABILITIES yesno {
 			curpeer->conf.announce_capa = $3;
 		}
+		| ANNOUNCE REFRESH yesno {
+			curpeer->conf.capabilities.refresh = $3;
+		}
+		| ANNOUNCE RESTART yesno {
+			curpeer->conf.capabilities.grestart.restart = $3;
+		}
+		| ANNOUNCE AS4BYTE yesno {
+			curpeer->conf.capabilities.as4byte = $3;
+		}
 		| ANNOUNCE SELF {
 			curpeer->conf.announce_type = ANNOUNCE_SELF;
 		}
 		| ANNOUNCE STRING {
-			if (!strcmp($2, "none"))
+			if (!strcmp($2, "self"))
+				curpeer->conf.announce_type = ANNOUNCE_SELF;
+			else if (!strcmp($2, "none"))
 				curpeer->conf.announce_type = ANNOUNCE_NONE;
 			else if (!strcmp($2, "all"))
 				curpeer->conf.announce_type = ANNOUNCE_ALL;
@@ -1083,7 +1269,7 @@ peeropts	: REMOTEAS as4number	{
 			curpeer->conf.reflector_client = 1;
 		}
 		| REFLECTOR address	{
-			if ($2.af != AF_INET) {
+			if ($2.aid != AID_INET) {
 				yyerror("route reflector cluster-id must be "
 				    "an IPv4 address");
 				YYERROR;
@@ -1157,6 +1343,10 @@ family		: IPV4	{ $$ = AFI_IPv4; }
 		| IPV6	{ $$ = AFI_IPv6; }
 		;
 
+nettype		: STATIC { $$ = 1; },
+		| CONNECTED { $$ = 0; }
+		;
+
 espah		: ESP		{ $$ = 1; }
 		| AH		{ $$ = 0; }
 		;
@@ -1336,12 +1526,12 @@ filter_prefix_l	: filter_prefix				{ $$ 
 		;
 
 filter_prefix	: prefix				{
-			if (fmopts.af && fmopts.af != $1.prefix.af) {
+			if (fmopts.aid && fmopts.aid != $1.prefix.aid) {
 				yyerror("rules with mixed address families "
 				    "are not allowed");
 				YYERROR;
 			} else
-				fmopts.af = $1.prefix.af;
+				fmopts.aid = $1.prefix.aid;
 			if (($$ = calloc(1, sizeof(struct filter_prefix_l))) ==
 			    NULL)
 				fatal(NULL);
@@ -1410,6 +1600,12 @@ filter_as	: as4number		{
 				fatal(NULL);
 			$$->a.as = $1;
 		}
+		| NEIGHBORAS		{
+			if (($$ = calloc(1, sizeof(struct filter_as_l))) ==
+			    NULL)
+				fatal(NULL);
+			$$->a.flags = AS_FLAG_NEIGHBORAS;
+		}
 		;
 
 filter_match_h	: /* empty */			{
@@ -1437,18 +1633,18 @@ filter_elm	: filter_prefix_h	{
 			fmopts.prefix_l = $1;
 		}
 		| PREFIXLEN prefixlenop		{
-			if (fmopts.af == 0) {
+			if (fmopts.aid == 0) {
 				yyerror("address family needs to be specified "
 				    "before \"prefixlen\"");
 				YYERROR;
 			}
-			if (fmopts.m.prefixlen.af) {
+			if (fmopts.m.prefixlen.aid) {
 				yyerror("\"prefixlen\" already specified");
 				YYERROR;
 			}
 			memcpy(&fmopts.m.prefixlen, &$2,
 			    sizeof(fmopts.m.prefixlen));
-			fmopts.m.prefixlen.af = fmopts.af;
+			fmopts.m.prefixlen.aid = fmopts.aid;
 		}
 		| filter_as_h		{
 			if (fmopts.as_l != NULL) {
@@ -1457,32 +1653,93 @@ filter_elm	: filter_prefix_h	{
 			}
 			fmopts.as_l = $1;
 		}
+		| MAXASLEN NUMBER	{
+			if (fmopts.m.aslen.type != ASLEN_NONE) {
+				yyerror("AS length filters already specified");
+				YYERROR;
+			}
+			if ($2 < 0 || $2 > UINT_MAX) {
+				yyerror("bad max-as-len %lld", $2);
+				YYERROR;
+			}
+			fmopts.m.aslen.type = ASLEN_MAX;
+			fmopts.m.aslen.aslen = $2;
+		}
+		| MAXASSEQ NUMBER	{
+			if (fmopts.m.aslen.type != ASLEN_NONE) {
+				yyerror("AS length filters already specified");
+				YYERROR;
+			}
+			if ($2 < 0 || $2 > UINT_MAX) {
+				yyerror("bad max-as-seq %lld", $2);
+				YYERROR;
+			}
+			fmopts.m.aslen.type = ASLEN_SEQ;
+			fmopts.m.aslen.aslen = $2;
+		}
 		| COMMUNITY STRING	{
 			if (fmopts.m.community.as != COMMUNITY_UNSET) {
 				yyerror("\"community\" already specified");
 				free($2);
 				YYERROR;
 			}
-			if (parsecommunity($2, &fmopts.m.community.as,
-			    &fmopts.m.community.type) == -1) {
+			if (parsecommunity(&fmopts.m.community, $2) == -1) {
 				free($2);
 				YYERROR;
 			}
 			free($2);
 		}
+		| EXTCOMMUNITY STRING STRING {
+			if (fmopts.m.ext_community.flags &
+			    EXT_COMMUNITY_FLAG_VALID) {
+				yyerror("\"ext-community\" already specified");
+				free($2);
+				free($3);
+				YYERROR;
+			}
+
+			if (parseextcommunity(&fmopts.m.ext_community,
+			    $2, $3) == -1) {
+				free($2);
+				free($3);
+				YYERROR;
+			}
+			free($2);
+			free($3);
+		}
 		| IPV4			{
-			if (fmopts.af) {
+			if (fmopts.aid) {
 				yyerror("address family already specified");
 				YYERROR;
 			}
-			fmopts.af = AF_INET;
+			fmopts.aid = AID_INET;
 		}
 		| IPV6			{
-			if (fmopts.af) {
+			if (fmopts.aid) {
 				yyerror("address family already specified");
 				YYERROR;
 			}
-			fmopts.af = AF_INET6;
+			fmopts.aid = AID_INET6;
+		}
+		| NEXTHOP address 	{
+			if (fmopts.m.nexthop.flags) {
+				yyerror("nexthop already specified");
+				YYERROR;
+			}
+			if (fmopts.aid && fmopts.aid != $2.aid) {
+				yyerror("nexthop address family doesn't match "
+				    "rule address family");
+				YYERROR;
+			}
+			fmopts.m.nexthop.addr = $2;
+			fmopts.m.nexthop.flags = FILTER_NEXTHOP_ADDR;
+		}
+		| NEXTHOP NEIGHBOR 	{
+			if (fmopts.m.nexthop.flags) {
+				yyerror("nexthop already specified");
+				YYERROR;
+			}
+			fmopts.m.nexthop.flags = FILTER_NEXTHOP_NEIGHBOR;
 		}
 		;
 
@@ -1588,7 +1845,7 @@ filter_set_opt	: LOCALPREF NUMBER		{
 			}
 			if (($$ = calloc(1, sizeof(struct filter_set))) == NULL)
 				fatal(NULL);
-			if ($2 > 0) {
+			if ($2 >= 0) {
 				$$->type = ACTION_SET_MED;
 				$$->action.metric = $2;
 			} else {
@@ -1623,7 +1880,7 @@ filter_set_opt	: LOCALPREF NUMBER		{
 			}
 			if (($$ = calloc(1, sizeof(struct filter_set))) == NULL)
 				fatal(NULL);
-			if ($2 > 0) {
+			if ($2 >= 0) {
 				$$->type = ACTION_SET_MED;
 				$$->action.metric = $2;
 			} else {
@@ -1782,8 +2039,7 @@ filter_set_opt	: LOCALPREF NUMBER		{
 			else
 				$$->type = ACTION_SET_COMMUNITY;
 
-			if (parsecommunity($3, &$$->action.community.as,
-			    &$$->action.community.type) == -1) {
+			if (parsecommunity(&$$->action.community, $3) == -1) {
 				free($3);
 				free($$);
 				YYERROR;
@@ -1796,40 +2052,62 @@ filter_set_opt	: LOCALPREF NUMBER		{
 				free($$);
 				YYERROR;
 			}
-			/* Don't allow setting of unknown well-known types */
-			if ($$->action.community.as == COMMUNITY_WELLKNOWN) {
-				switch ($$->action.community.type) {
-				case COMMUNITY_NO_EXPORT:
-				case COMMUNITY_NO_ADVERTISE:
-				case COMMUNITY_NO_EXPSUBCONFED:
-				case COMMUNITY_NO_PEER:
-					/* valid */
-					break;
-				default:
-					/* unknown */
-					yyerror("Invalid well-known community");
-					free($$);
-					YYERROR;
-					break;
-				}
+		}
+		| EXTCOMMUNITY delete STRING STRING {
+			if (($$ = calloc(1, sizeof(struct filter_set))) == NULL)
+				fatal(NULL);
+			if ($2)
+				$$->type = ACTION_DEL_EXT_COMMUNITY;
+			else
+				$$->type = ACTION_SET_EXT_COMMUNITY;
+
+			if (parseextcommunity(&$$->action.ext_community,
+			    $3, $4) == -1) {
+				free($3);
+				free($4);
+				free($$);
+				YYERROR;
 			}
+			free($3);
+			free($4);
+		}
+		| ORIGIN origincode {
+			if (($$ = calloc(1, sizeof(struct filter_set))) == NULL)
+				fatal(NULL);
+			$$->type = ACTION_SET_ORIGIN;
+			$$->action.origin = $2;
 		}
 		;
 
+origincode	: string {
+			if (!strcmp($1, "egp"))
+				$$ = ORIGIN_EGP;
+			else if (!strcmp($1, "igp"))
+				$$ = ORIGIN_IGP;
+			else if (!strcmp($1, "incomplete"))
+				$$ = ORIGIN_INCOMPLETE;
+			else {
+				yyerror("unknown origin \"%s\"", $1);
+				free($1);
+				YYERROR;
+			}
+			free($1);
+		};
+
 comma		: ","
 		| /* empty */
 		;
 
 unaryop		: '='		{ $$ = OP_EQ; }
-		| '!' '='	{ $$ = OP_NE; }
-		| '<' '='	{ $$ = OP_LE; }
+		| NE		{ $$ = OP_NE; }
+		| LE		{ $$ = OP_LE; }
 		| '<'		{ $$ = OP_LT; }
-		| '>' '='	{ $$ = OP_GE; }
+		| GE		{ $$ = OP_GE; }
 		| '>'		{ $$ = OP_GT; }
 		;
 
 binaryop	: '-'		{ $$ = OP_RANGE; }
-		| '>' '<'	{ $$ = OP_XRANGE; }
+		| XRANGE	{ $$ = OP_XRANGE; }
 		;
 
 %%
@@ -1873,6 +2151,7 @@ lookup(char *s)
 		{ "allow",		ALLOW},
 		{ "announce",		ANNOUNCE},
 		{ "any",		ANY},
+		{ "as-4byte",		AS4BYTE },
 		{ "blackhole",		BLACKHOLE},
 		{ "capabilities",	CAPABILITIES},
 		{ "community",		COMMUNITY},
@@ -1889,16 +2168,22 @@ lookup(char *s)
 		{ "enforce",		ENFORCE},
 		{ "esp",		ESP},
 		{ "evaluate",		EVALUATE},
+		{ "export-target",	EXPORTTRGT},
+		{ "ext-community",	EXTCOMMUNITY},
 		{ "fib-update",		FIBUPDATE},
 		{ "from",		FROM},
 		{ "group",		GROUP},
 		{ "holdtime",		HOLDTIME},
 		{ "ignore",		IGNORE},
 		{ "ike",		IKE},
+		{ "import-target",	IMPORTTRGT},
 		{ "in",			IN},
 		{ "include",		INCLUDE},
 		{ "inet",		IPV4},
 		{ "inet6",		IPV6},
+#if defined(IPV6_LINKLOCAL_PEER)
+		{ "interface",		LLIFACE},
+#endif
 		{ "ipsec",		IPSEC},
 		{ "key",		KEY},
 		{ "listen",		LISTEN},
@@ -1906,6 +2191,8 @@ lookup(char *s)
 		{ "localpref",		LOCALPREF},
 		{ "log",		LOG},
 		{ "match",		MATCH},
+		{ "max-as-len",		MAXASLEN},
+		{ "max-as-seq",		MAXASSEQ},
 		{ "max-prefix",		MAXPREFIX},
 		{ "md5sig",		MD5SIG},
 		{ "med",		MED},
@@ -1918,6 +2205,7 @@ lookup(char *s)
 		{ "nexthop",		NEXTHOP},
 		{ "no-modify",		NOMODIFY},
 		{ "on",			ON},
+		{ "origin",		ORIGIN},
 		{ "out",		OUT},
 		{ "passive",		PASSIVE},
 		{ "password",		PASSWORD},
@@ -1929,10 +2217,14 @@ lookup(char *s)
 		{ "prepend-self",	PREPEND_SELF},
 		{ "qualify",		QUALIFY},
 		{ "quick",		QUICK},
+		{ "rd",			RD},
 		{ "rde",		RDE},
+		{ "rdomain",		RDOMAIN},
+		{ "refresh",		REFRESH },
 		{ "reject",		REJECT},
 		{ "remote-as",		REMOTEAS},
 		{ "restart",		RESTART},
+		{ "restricted",		RESTRICTED},
 		{ "rib",		RIB},
 		{ "route-collector",	ROUTECOLL},
 		{ "route-reflector",	REFLECTOR},
@@ -1941,6 +2233,7 @@ lookup(char *s)
 		{ "rtlabel",		RTLABEL},
 		{ "self",		SELF},
 		{ "set",		SET},
+		{ "socket",		SOCKET },
 		{ "softreconfig",	SOFTRECONFIG},
 		{ "source-as",		SOURCEAS},
 		{ "spi",		SPI},
@@ -2117,9 +2410,10 @@ top:
 					return (0);
 				if (next == quotec || c == ' ' || c == '\t')
 					c = next;
-				else if (next == '\n')
+				else if (next == '\n') {
+					file->lineno++;
 					continue;
-				else
+				} else
 					lungetc(next);
 			} else if (c == quotec) {
 				*p = '\0';
@@ -2135,6 +2429,26 @@ top:
 		if (yylval.v.string == NULL)
 			fatal("yylex: strdup");
 		return (STRING);
+	case '!':
+		next = lgetc(0);
+		if (next == '=')
+			return (NE);
+		lungetc(next);
+		break;
+	case '<':
+		next = lgetc(0);
+		if (next == '=')
+			return (LE);
+		lungetc(next);
+		break;
+	case '>':
+		next = lgetc(0);
+		if (next == '<')
+			return (XRANGE);
+		else if (next == '=')
+			return (GE);
+		lungetc(next);
+		break;
 	}
 
 #define allowed_to_end_number(x) \
@@ -2274,18 +2588,21 @@ popfile(void)
 int
 parse_config(char *filename, struct bgpd_config *xconf,
     struct mrt_head *xmconf, struct peer **xpeers, struct network_head *nc,
-    struct filter_head *xfilter_l)
+    struct filter_head *xfilter_l, struct rdomain_head *xrdom_l)
 {
 	struct sym		*sym, *next;
 	struct peer		*p, *pnext;
 	struct listen_addr	*la;
 	struct network		*n;
 	struct filter_rule	*r;
+	struct rde_rib		*rr;
+	struct rdomain		*rd;
 	int			 errors = 0;
 
 	if ((conf = calloc(1, sizeof(struct bgpd_config))) == NULL)
 		fatal(NULL);
 	conf->opts = xconf->opts;
+	conf->csock = strdup(SOCKET_NAME);
 
 	if ((file = pushfile(filename, 1)) == NULL) {
 		free(conf);
@@ -2316,13 +2633,15 @@ parse_config(char *filename, struct bgpd
 	id = 1;
 
 	/* network list is always empty in the parent */
-	netconf = nc;
+	gnetconf = netconf = nc;
 	TAILQ_INIT(netconf);
 	/* init the empty filter list for later */
 	TAILQ_INIT(xfilter_l);
+	SIMPLEQ_INIT(xrdom_l);
+	rdom_l = xrdom_l;
 
-	add_rib("Adj-RIB-In", F_RIB_NOEVALUATE);
-	add_rib("Loc-RIB", 0);
+	add_rib("Adj-RIB-In", 0, F_RIB_NOFIB | F_RIB_NOEVALUATE);
+	add_rib("Loc-RIB", 0, 0);
 
 	yyparse();
 	errors = file->errors;
@@ -2344,6 +2663,9 @@ parse_config(char *filename, struct bgpd
 
 	if (errors) {
 		/* XXX more leaks in this case */
+		free(conf->csock);
+		free(conf->rcsock);
+
 		while ((la = TAILQ_FIRST(listen_addrs)) != NULL) {
 			TAILQ_REMOVE(listen_addrs, la, entry);
 			free(la);
@@ -2357,23 +2679,44 @@ parse_config(char *filename, struct bgpd
 
 		while ((n = TAILQ_FIRST(netconf)) != NULL) {
 			TAILQ_REMOVE(netconf, n, entry);
+			filterset_free(&n->net.attrset);
 			free(n);
 		}
 
 		while ((r = TAILQ_FIRST(filter_l)) != NULL) {
 			TAILQ_REMOVE(filter_l, r, entry);
+			filterset_free(&r->set);
 			free(r);
 		}
 
 		while ((r = TAILQ_FIRST(peerfilter_l)) != NULL) {
 			TAILQ_REMOVE(peerfilter_l, r, entry);
+			filterset_free(&r->set);
 			free(r);
 		}
 
 		while ((r = TAILQ_FIRST(groupfilter_l)) != NULL) {
 			TAILQ_REMOVE(groupfilter_l, r, entry);
+			filterset_free(&r->set);
 			free(r);
 		}
+		while ((rr = SIMPLEQ_FIRST(&ribnames)) != NULL) {
+			SIMPLEQ_REMOVE_HEAD(&ribnames, entry);
+			free(rr);
+		}
+		while ((rd = SIMPLEQ_FIRST(rdom_l)) != NULL) {
+			SIMPLEQ_REMOVE_HEAD(rdom_l, entry);
+			filterset_free(&rd->export);
+			filterset_free(&rd->import);
+
+			while ((n = TAILQ_FIRST(&rd->net_l)) != NULL) {
+				TAILQ_REMOVE(&rd->net_l, n, entry);
+				filterset_free(&n->net.attrset);
+				free(n);
+			}
+
+			free(rd);
+		}
 	} else {
 		errors += merge_config(xconf, conf, peer_l, listen_addrs);
 		errors += mrt_mergeconfig(xmconf, mrtconf);
@@ -2505,27 +2848,27 @@ getcommunity(char *s)
 }
 
 int
-parsecommunity(char *s, int *as, int *type)
+parsecommunity(struct filter_community *c, char *s)
 {
 	char *p;
-	int i;
+	int i, as;
 
 	/* Well-known communities */
 	if (strcasecmp(s, "NO_EXPORT") == 0) {
-		*as = COMMUNITY_WELLKNOWN;
-		*type = COMMUNITY_NO_EXPORT;
+		c->as = COMMUNITY_WELLKNOWN;
+		c->type = COMMUNITY_NO_EXPORT;
 		return (0);
 	} else if (strcasecmp(s, "NO_ADVERTISE") == 0) {
-		*as = COMMUNITY_WELLKNOWN;
-		*type = COMMUNITY_NO_ADVERTISE;
+		c->as = COMMUNITY_WELLKNOWN;
+		c->type = COMMUNITY_NO_ADVERTISE;
 		return (0);
 	} else if (strcasecmp(s, "NO_EXPORT_SUBCONFED") == 0) {
-		*as = COMMUNITY_WELLKNOWN;
-		*type = COMMUNITY_NO_EXPSUBCONFED;
+		c->as = COMMUNITY_WELLKNOWN;
+		c->type = COMMUNITY_NO_EXPSUBCONFED;
 		return (0);
 	} else if (strcasecmp(s, "NO_PEER") == 0) {
-		*as = COMMUNITY_WELLKNOWN;
-		*type = COMMUNITY_NO_PEER;
+		c->as = COMMUNITY_WELLKNOWN;
+		c->type = COMMUNITY_NO_PEER;
 		return (0);
 	}
 
@@ -2537,23 +2880,176 @@ parsecommunity(char *s, int *as, int *ty
 
 	if ((i = getcommunity(s)) == COMMUNITY_ERROR)
 		return (-1);
-	if (i == USHRT_MAX) {
+	if (i == COMMUNITY_WELLKNOWN) {
 		yyerror("Bad community AS number");
 		return (-1);
 	}
-	*as = i;
+	as = i;
 
 	if ((i = getcommunity(p)) == COMMUNITY_ERROR)
 		return (-1);
-	*type = i;
+	c->as = as;
+	c->type = i;
 
 	return (0);
 }
 
+int
+parsesubtype(char *type)
+{
+	/* this has to be sorted always */
+	static const struct keywords keywords[] = {
+		{ "bdc",	EXT_COMMUNITY_BGP_COLLECT },
+		{ "odi",	EXT_COMMUNITY_OSPF_DOM_ID },
+		{ "ori",	EXT_COMMUNITY_OSPF_RTR_ID },
+		{ "ort",	EXT_COMMUNITY_OSPF_RTR_TYPE },
+		{ "rt",		EXT_COMMUNITY_ROUTE_TGT },
+		{ "soo",	EXT_CUMMUNITY_ROUTE_ORIG }
+	};
+	const struct keywords	*p;
+
+	p = bsearch(type, keywords, sizeof(keywords)/sizeof(keywords[0]),
+	    sizeof(keywords[0]), kw_cmp);
+
+	if (p)
+		return (p->k_val);
+	else
+		return (-1);
+}
+
+int
+parseextvalue(char *s, u_int32_t *v)
+{
+	const char 	*errstr;
+	char		*p;
+	struct in_addr	 ip;
+	u_int32_t	 uvalh = 0, uval;
+
+	if ((p = strchr(s, '.')) == NULL) {
+		/* AS_PLAIN number (4 or 2 byte) */
+		uval = strtonum(s, 0, UINT_MAX, &errstr);
+		if (errstr) {
+			yyerror("Bad ext-community %s is %s", s, errstr);
+			return (-1);
+		}
+		*v = uval;
+		if (uval > USHRT_MAX)
+			return (EXT_COMMUNITY_FOUR_AS);
+		else
+			return (EXT_COMMUNITY_TWO_AS);
+	} else if (strchr(p + 1, '.') == NULL) {
+		/* AS_DOT number (4-byte) */
+		*p++ = '\0';
+		uvalh = strtonum(s, 0, USHRT_MAX, &errstr);
+		if (errstr) {
+			yyerror("Bad ext-community %s is %s", s, errstr);
+			return (-1);
+		}
+		uval = strtonum(p, 0, USHRT_MAX, &errstr);
+		if (errstr) {
+			yyerror("Bad ext-community %s is %s", p, errstr);
+			return (-1);
+		}
+		*v = uval | (uvalh << 16);
+		return (EXT_COMMUNITY_FOUR_AS);
+	} else {
+		/* more then one dot -> IP address */
+		if (inet_aton(s, &ip) == 0) {
+			yyerror("Bad ext-community %s not parseable", s);
+			return (-1);
+		}
+		*v = ip.s_addr;
+		return (EXT_COMMUNITY_IPV4);
+	}
+	return (-1);
+}
+
+int
+parseextcommunity(struct filter_extcommunity *c, char *t, char *s)
+{
+	const struct ext_comm_pairs	 iana[] = IANA_EXT_COMMUNITIES;
+	const char 	*errstr;
+	u_int64_t	 ullval = 0;
+	u_int32_t	 uval;
+	char		*p, *ep;
+	unsigned int	 i;
+	int		 type, subtype;
+
+	if ((subtype = parsesubtype(t)) == -1) {
+		yyerror("Bad ext-community unknown type");
+		return (-1);
+	}
+
+	if ((p = strchr(s, ':')) == NULL) {
+		type = EXT_COMMUNITY_OPAQUE,
+		errno = 0;
+		ullval = strtoull(s, &ep, 0);
+		if (s[0] == '\0' || *ep != '\0') {
+			yyerror("Bad ext-community bad value");
+			return (-1);
+		}
+		if (errno == ERANGE && ullval > EXT_COMMUNITY_OPAQUE_MAX) {
+			yyerror("Bad ext-community value to big");
+			return (-1);
+		}
+		c->data.ext_opaq = ullval;
+	} else {
+		*p++ = '\0';
+		if ((type = parseextvalue(s, &uval)) == -1)
+			return (-1);
+		switch (type) {
+		case EXT_COMMUNITY_TWO_AS:
+			ullval = strtonum(p, 0, UINT_MAX, &errstr);
+			break;
+		case EXT_COMMUNITY_IPV4:
+		case EXT_COMMUNITY_FOUR_AS:
+			ullval = strtonum(p, 0, USHRT_MAX, &errstr);
+			break;
+		default:
+			fatalx("parseextcommunity: unexpected result");
+		}
+		if (errstr) {
+			yyerror("Bad ext-community %s is %s", p,
+			    errstr);
+			return (-1);
+		}
+		switch (type) {
+		case EXT_COMMUNITY_TWO_AS:
+			c->data.ext_as.as = uval;
+			c->data.ext_as.val = ullval;
+			break;
+		case EXT_COMMUNITY_IPV4:
+			c->data.ext_ip.addr.s_addr = uval;
+			c->data.ext_ip.val = ullval;
+			break;
+		case EXT_COMMUNITY_FOUR_AS:
+			c->data.ext_as4.as4 = uval;
+			c->data.ext_as4.val = ullval;
+			break;
+		}
+	}
+	c->type = type;
+	c->subtype = subtype;
+
+	/* verify type/subtype combo */
+	for (i = 0; i < sizeof(iana)/sizeof(iana[0]); i++) {
+		if (iana[i].type == type && iana[i].subtype == subtype) {
+			if (iana[i].transitive)
+				c->type |= EXT_COMMUNITY_TRANSITIVE;
+			c->flags |= EXT_COMMUNITY_FLAG_VALID;
+			return (0);
+		}
+	}
+
+	yyerror("Bad ext-community bad format for type");
+	return (-1);
+}
+
 struct peer *
 alloc_peer(void)
 {
 	struct peer	*p;
+	u_int8_t	 i;
 
 	if ((p = calloc(1, sizeof(struct peer))) == NULL)
 		fatal("new_peer");
@@ -2564,11 +3060,11 @@ alloc_peer(void)
 	p->conf.distance = 1;
 	p->conf.announce_type = ANNOUNCE_UNDEF;
 	p->conf.announce_capa = 1;
-	p->conf.capabilities.mp_v4 = SAFI_UNICAST;
-	p->conf.capabilities.mp_v6 = SAFI_NONE;
+	for (i = 0; i < AID_MAX; i++)
+		p->conf.capabilities.mp[i] = -1;
 	p->conf.capabilities.refresh = 1;
-	p->conf.capabilities.restart = 0;
-	p->conf.capabilities.as4byte = 0;
+	p->conf.capabilities.grestart.restart = 1;
+	p->conf.capabilities.as4byte = 1;
 	p->conf.local_as = conf->as;
 	p->conf.local_short_as = conf->short_as;
 	p->conf.softreconfig_in = 1;
@@ -2592,6 +3088,9 @@ new_peer(void)
 		if (strlcpy(p->conf.descr, curgroup->conf.descr,
 		    sizeof(p->conf.descr)) >= sizeof(p->conf.descr))
 			fatalx("new_peer descr strlcpy");
+		if (strlcpy(p->conf.lliface, curgroup->conf.lliface,
+		    sizeof(p->conf.lliface)) >= sizeof(p->conf.lliface))
+			fatalx("new_peer lliface strlcpy");
 		p->conf.groupid = curgroup->conf.id;
 		p->conf.local_as = curgroup->conf.local_as;
 		p->conf.local_short_as = curgroup->conf.local_short_as;
@@ -2674,39 +3173,52 @@ add_mrtconfig(enum mrt_type type, char *
 }
 
 int
-add_rib(char *name, u_int16_t flags)
+add_rib(char *name, u_int rtableid, u_int16_t flags)
 {
 	struct rde_rib	*rr;
+	u_int		 rdom;
 
-	if (find_rib(name)) {
-		yyerror("rib \"%s\" allready exists.", name);
-		return (-1);
-	}
-
-	if ((rr = calloc(1, sizeof(*rr))) == NULL) {
-		log_warn("add_rib");
-		return (-1);
+	if ((rr = find_rib(name)) == NULL) {
+		if ((rr = calloc(1, sizeof(*rr))) == NULL) {
+			log_warn("add_rib");
+			return (-1);
+		}
 	}
 	if (strlcpy(rr->name, name, sizeof(rr->name)) >= sizeof(rr->name)) {
 		yyerror("rib name \"%s\" too long: max %u",
 		   name, sizeof(rr->name) - 1);
+		free(rr);
 		return (-1);
 	}
 	rr->flags |= flags;
+	if ((rr->flags & F_RIB_HASNOFIB) == 0) {
+		if (ktable_exists(rtableid, &rdom) != 1) {
+			yyerror("rtable id %lld does not exist", rtableid);
+			free(rr);
+			return (-1);
+		}
+		if (rdom != 0) {
+			yyerror("rtable %lld does not belong to rdomain 0",
+			    rtableid);
+			free(rr);
+			return (-1);
+		}
+		rr->rtableid = rtableid;
+	}
 	SIMPLEQ_INSERT_TAIL(&ribnames, rr, entry);
 	return (0);
 }
 
-int
+struct rde_rib *
 find_rib(char *name)
 {
 	struct rde_rib	*rr;
 
 	SIMPLEQ_FOREACH(rr, &ribnames, entry) {
 		if (!strcmp(rr->name, name))
-			return (1);
+			return (rr);
 	}
-	return (0);
+	return (NULL);
 }
 
 int
@@ -2715,7 +3227,7 @@ get_id(struct peer *newpeer)
 	struct peer	*p;
 
 	for (p = peer_l_old; p != NULL; p = p->next)
-		if (newpeer->conf.remote_addr.af) {
+		if (newpeer->conf.remote_addr.aid) {
 			if (!memcmp(&p->conf.remote_addr,
 			    &newpeer->conf.remote_addr,
 			    sizeof(p->conf.remote_addr))) {
@@ -2856,9 +3368,11 @@ str2key(char *s, char *dest, size_t max_
 int
 neighbor_consistent(struct peer *p)
 {
+	u_int8_t	i;
+
 	/* local-address and peer's address: same address family */
-	if (p->conf.local_addr.af &&
-	    p->conf.local_addr.af != p->conf.remote_addr.af) {
+	if (p->conf.local_addr.aid &&
+	    p->conf.local_addr.aid != p->conf.remote_addr.aid) {
 		yyerror("local-address and neighbor address "
 		    "must be of the same address family");
 		return (-1);
@@ -2869,7 +3383,7 @@ neighbor_consistent(struct peer *p)
 	    p->conf.auth.method == AUTH_IPSEC_IKE_AH ||
 	    p->conf.auth.method == AUTH_IPSEC_MANUAL_ESP ||
 	    p->conf.auth.method == AUTH_IPSEC_MANUAL_AH) &&
-	    !p->conf.local_addr.af) {
+	    !p->conf.local_addr.aid) {
 		yyerror("neighbors with any form of IPsec configured "
 		    "need local-address to be specified");
 		return (-1);
@@ -2889,18 +3403,14 @@ neighbor_consistent(struct peer *p)
 		return (-1);
 	}
 
-	/* for testing: enable 4-byte AS number capability if necessary */
-	if (conf->as > USHRT_MAX || p->conf.remote_as > USHRT_MAX)
-		p->conf.capabilities.as4byte = 1;
-
 	/* set default values if they where undefined */
 	p->conf.ebgp = (p->conf.remote_as != conf->as);
 	if (p->conf.announce_type == ANNOUNCE_UNDEF)
-		p->conf.announce_type = p->conf.ebgp == 0 ?
-		    ANNOUNCE_ALL : ANNOUNCE_SELF;
+		p->conf.announce_type = p->conf.ebgp ?
+		    ANNOUNCE_SELF : ANNOUNCE_ALL;
 	if (p->conf.enforce_as == ENFORCE_AS_UNDEF)
-		p->conf.enforce_as = p->conf.ebgp == 0 ?
-		    ENFORCE_AS_OFF : ENFORCE_AS_ON;
+		p->conf.enforce_as = p->conf.ebgp ?
+		    ENFORCE_AS_ON : ENFORCE_AS_OFF;
 
 	/* EBGP neighbors are not allowed in route reflector clusters */
 	if (p->conf.reflector_client && p->conf.ebgp) {
@@ -2909,6 +3419,11 @@ neighbor_consistent(struct peer *p)
 		return (-1);
 	}
 
+	/* the default MP capability is NONE */
+	for (i = 0; i < AID_MAX; i++)
+		if (p->conf.capabilities.mp[i] == -1)
+			p->conf.capabilities.mp[i] = 0;
+
 	return (0);
 }
 
@@ -2927,6 +3442,11 @@ merge_filterset(struct filter_set_head *
 				yyerror("community is already set");
 			else if (s->type == ACTION_DEL_COMMUNITY)
 				yyerror("community will already be deleted");
+			else if (s->type == ACTION_SET_EXT_COMMUNITY)
+				yyerror("ext-community is already set");
+			else if (s->type == ACTION_DEL_EXT_COMMUNITY)
+				yyerror(
+				    "ext-community will already be deleted");
 			else
 				yyerror("redefining set parameter %s",
 				    filterset_name(s->type));
@@ -2953,9 +3473,18 @@ merge_filterset(struct filter_set_head *
 					return (0);
 				}
 				break;
+			case ACTION_SET_EXT_COMMUNITY:
+			case ACTION_DEL_EXT_COMMUNITY:
+				if (memcmp(&s->action.ext_community,
+				    &t->action.ext_community,
+				    sizeof(s->action.ext_community)) < 0) {
+					TAILQ_INSERT_BEFORE(t, s, entry);
+					return (0);
+				}
+				break;
 			case ACTION_SET_NEXTHOP:
-				if (s->action.nexthop.af <
-				    t->action.nexthop.af) {
+				if (s->action.nexthop.aid <
+				    t->action.nexthop.aid) {
 					TAILQ_INSERT_BEFORE(t, s, entry);
 					return (0);
 				}
@@ -2985,22 +3514,6 @@ copy_filterset(struct filter_set_head *s
 	}
 }
 
-void
-move_filterset(struct filter_set_head *source, struct filter_set_head *dest)
-{
-	struct filter_set	*s;
-
-	TAILQ_INIT(dest);
-
-	if (source == NULL)
-		return;
-
-	while ((s = TAILQ_FIRST(source)) != NULL) {
-		TAILQ_REMOVE(source, s, entry);
-		TAILQ_INSERT_TAIL(dest, s, entry);
-	}
-}
-
 struct filter_rule *
 get_rule(enum action_types type)
 {
