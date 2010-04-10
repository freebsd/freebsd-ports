Index: bgpd/parse.y
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/parse.y,v
retrieving revision 1.1.1.8
retrieving revision 1.8
diff -u -p -r1.1.1.8 -r1.8
--- bgpd/parse.y	14 Feb 2010 20:19:57 -0000	1.1.1.8
+++ bgpd/parse.y	10 Apr 2010 12:16:23 -0000	1.8
@@ -1,4 +1,4 @@
-/*	$OpenBSD: parse.y,v 1.231 2009/06/06 01:10:29 claudio Exp $ */
+/*	$OpenBSD: parse.y,v 1.250 2010/03/31 18:53:23 claudio Exp $ */
 
 /*
  * Copyright (c) 2002, 2003, 2004 Henning Brauer <henning@openbsd.org>
@@ -105,7 +105,7 @@ struct filter_match_l {
 	struct filter_match	 m;
 	struct filter_prefix_l	*prefix_l;
 	struct filter_as_l	*as_l;
-	sa_family_t		 af;
+	u_int8_t		 aid;
 } fmopts;
 
 struct peer	*alloc_peer(void);
@@ -128,7 +128,11 @@ void		 move_filterset(struct filter_set_
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
@@ -161,9 +165,9 @@ typedef struct {
 %token	AS ROUTERID HOLDTIME YMIN LISTEN ON FIBUPDATE RTABLE
 %token	RDE RIB EVALUATE IGNORE COMPARE
 %token	GROUP NEIGHBOR NETWORK
-%token	REMOTEAS DESCR LOCALADDR MULTIHOP PASSIVE MAXPREFIX RESTART
-%token	ANNOUNCE DEMOTE CONNECTRETRY
-%token	ENFORCE NEIGHBORAS CAPABILITIES REFLECTOR DEPEND DOWN SOFTRECONFIG
+%token	REMOTEAS DESCR LLIFACE LOCALADDR MULTIHOP PASSIVE MAXPREFIX RESTART
+%token	ANNOUNCE CAPABILITIES REFRESH AS4BYTE CONNECTRETRY
+%token	DEMOTE ENFORCE NEIGHBORAS REFLECTOR DEPEND DOWN SOFTRECONFIG
 %token	DUMP IN OUT
 %token	LOG ROUTECOLL TRANSPARENT
 %token	TCP MD5SIG PASSWORD KEY TTLSECURITY
@@ -171,17 +175,19 @@ typedef struct {
 %token	QUICK
 %token	FROM TO ANY
 %token	CONNECTED STATIC
-%token	PREFIX PREFIXLEN SOURCEAS TRANSITAS PEERAS COMMUNITY DELETE
+%token	COMMUNITY EXTCOMMUNITY
+%token	PREFIX PREFIXLEN SOURCEAS TRANSITAS PEERAS DELETE
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
 %type	<v.number>		asnumber as4number optnumber yesno inout
-%type	<v.number>		espah family restart
+%type	<v.number>		espah family restart origincode
 %type	<v.string>		string filter_rib
 %type	<v.addr>		address
 %type	<v.prefix>		prefix addrspec
@@ -211,8 +217,12 @@ grammar		: /* empty */
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
@@ -274,6 +284,8 @@ yesno		:  STRING			{
 			else if (!strcmp($1, "no"))
 				$$ = 0;
 			else {
+				yyerror("syntax error, "
+				    "either yes or no expected");
 				free($1);
 				YYERROR;
 			}
@@ -318,7 +330,7 @@ conf_main	: AS as4number		{
 			conf->short_as = $3;
 		}
 		| ROUTERID address		{
-			if ($2.af != AF_INET) {
+			if ($2.aid != AID_INET) {
 				yyerror("router-id must be an IPv4 address");
 				YYERROR;
 			}
@@ -342,35 +354,13 @@ conf_main	: AS as4number		{
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
@@ -397,7 +387,7 @@ conf_main	: AS as4number		{
 				free($3);
 				YYERROR;
 			}
-			if (!add_rib($3, F_RIB_NOEVALUATE)) {
+			if (!add_rib($3, F_RIB_NOFIB | F_RIB_NOEVALUATE)) {
 				free($3);
 				YYERROR;
 			}
@@ -459,18 +449,6 @@ conf_main	: AS as4number		{
 			}
 			free($4);
 		}
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
 		| DUMP STRING STRING optnumber		{
 			int action;
 
@@ -575,11 +553,16 @@ conf_main	: AS as4number		{
 			free($4);
 		}
 		| RTABLE NUMBER {
+#if defined(__FreeBSD__)	/* FreeBSD does not support RTABLE */
+			yyerror("rtable id not supported in FreeBSD, yet");
+			YYERROR;
+#else
 			if ($2 > RT_TABLEID_MAX || $2 < 0) {
 				yyerror("invalid rtable id");
 				YYERROR;
 			}
 			conf->rtableid = $2;
+#endif /* defined(__FreeBSD__) */
 		}
 		| CONNECTRETRY NUMBER {
 			if ($2 > USHRT_MAX || $2 < 1) {
@@ -635,11 +618,11 @@ address		: STRING		{
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
@@ -686,7 +669,7 @@ prefix		: STRING '/' NUMBER	{
 
 addrspec	: address	{
 			memcpy(&$$.prefix, &$1, sizeof(struct bgpd_addr));
-			if ($$.prefix.af == AF_INET)
+			if ($$.prefix.aid == AID_INET)
 				$$.len = 32;
 			else
 				$$.len = 128;
@@ -710,9 +693,13 @@ neighbor	: {	curpeer = new_peer(); }
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
@@ -802,6 +789,17 @@ peeropts	: REMOTEAS as4number	{
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
@@ -852,13 +850,17 @@ peeropts	: REMOTEAS as4number	{
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
@@ -866,25 +868,31 @@ peeropts	: REMOTEAS as4number	{
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
+			curpeer->conf.capabilities.restart = $3;
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
@@ -1083,7 +1091,7 @@ peeropts	: REMOTEAS as4number	{
 			curpeer->conf.reflector_client = 1;
 		}
 		| REFLECTOR address	{
-			if ($2.af != AF_INET) {
+			if ($2.aid != AID_INET) {
 				yyerror("route reflector cluster-id must be "
 				    "an IPv4 address");
 				YYERROR;
@@ -1336,12 +1344,12 @@ filter_prefix_l	: filter_prefix				{ $$ 
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
@@ -1437,18 +1445,18 @@ filter_elm	: filter_prefix_h	{
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
@@ -1463,26 +1471,43 @@ filter_elm	: filter_prefix_h	{
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
 		}
 		;
 
@@ -1782,8 +1807,7 @@ filter_set_opt	: LOCALPREF NUMBER		{
 			else
 				$$->type = ACTION_SET_COMMUNITY;
 
-			if (parsecommunity($3, &$$->action.community.as,
-			    &$$->action.community.type) == -1) {
+			if (parsecommunity(&$$->action.community, $3) == -1) {
 				free($3);
 				free($$);
 				YYERROR;
@@ -1796,40 +1820,62 @@ filter_set_opt	: LOCALPREF NUMBER		{
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
@@ -1873,6 +1919,7 @@ lookup(char *s)
 		{ "allow",		ALLOW},
 		{ "announce",		ANNOUNCE},
 		{ "any",		ANY},
+		{ "as-4byte",		AS4BYTE },
 		{ "blackhole",		BLACKHOLE},
 		{ "capabilities",	CAPABILITIES},
 		{ "community",		COMMUNITY},
@@ -1889,6 +1936,7 @@ lookup(char *s)
 		{ "enforce",		ENFORCE},
 		{ "esp",		ESP},
 		{ "evaluate",		EVALUATE},
+		{ "ext-community",	EXTCOMMUNITY},
 		{ "fib-update",		FIBUPDATE},
 		{ "from",		FROM},
 		{ "group",		GROUP},
@@ -1899,6 +1947,9 @@ lookup(char *s)
 		{ "include",		INCLUDE},
 		{ "inet",		IPV4},
 		{ "inet6",		IPV6},
+#if defined(IPV6_LINKLOCAL_PEER)
+		{ "interface",		LLIFACE},
+#endif
 		{ "ipsec",		IPSEC},
 		{ "key",		KEY},
 		{ "listen",		LISTEN},
@@ -1918,6 +1969,7 @@ lookup(char *s)
 		{ "nexthop",		NEXTHOP},
 		{ "no-modify",		NOMODIFY},
 		{ "on",			ON},
+		{ "origin",		ORIGIN},
 		{ "out",		OUT},
 		{ "passive",		PASSIVE},
 		{ "password",		PASSWORD},
@@ -1930,6 +1982,7 @@ lookup(char *s)
 		{ "qualify",		QUALIFY},
 		{ "quick",		QUICK},
 		{ "rde",		RDE},
+		{ "refresh",		REFRESH },
 		{ "reject",		REJECT},
 		{ "remote-as",		REMOTEAS},
 		{ "restart",		RESTART},
@@ -2135,6 +2188,26 @@ top:
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
@@ -2505,27 +2578,27 @@ getcommunity(char *s)
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
 
@@ -2537,23 +2610,176 @@ parsecommunity(char *s, int *as, int *ty
 
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
@@ -2564,11 +2790,11 @@ alloc_peer(void)
 	p->conf.distance = 1;
 	p->conf.announce_type = ANNOUNCE_UNDEF;
 	p->conf.announce_capa = 1;
-	p->conf.capabilities.mp_v4 = SAFI_UNICAST;
-	p->conf.capabilities.mp_v6 = SAFI_NONE;
+	for (i = 0; i < AID_MAX; i++)
+		p->conf.capabilities.mp[i] = -1;
 	p->conf.capabilities.refresh = 1;
 	p->conf.capabilities.restart = 0;
-	p->conf.capabilities.as4byte = 0;
+	p->conf.capabilities.as4byte = 1;
 	p->conf.local_as = conf->as;
 	p->conf.local_short_as = conf->short_as;
 	p->conf.softreconfig_in = 1;
@@ -2592,6 +2818,9 @@ new_peer(void)
 		if (strlcpy(p->conf.descr, curgroup->conf.descr,
 		    sizeof(p->conf.descr)) >= sizeof(p->conf.descr))
 			fatalx("new_peer descr strlcpy");
+		if (strlcpy(p->conf.lliface, curgroup->conf.lliface,
+		    sizeof(p->conf.lliface)) >= sizeof(p->conf.lliface))
+			fatalx("new_peer lliface strlcpy");
 		p->conf.groupid = curgroup->conf.id;
 		p->conf.local_as = curgroup->conf.local_as;
 		p->conf.local_short_as = curgroup->conf.local_short_as;
@@ -2715,7 +2944,7 @@ get_id(struct peer *newpeer)
 	struct peer	*p;
 
 	for (p = peer_l_old; p != NULL; p = p->next)
-		if (newpeer->conf.remote_addr.af) {
+		if (newpeer->conf.remote_addr.aid) {
 			if (!memcmp(&p->conf.remote_addr,
 			    &newpeer->conf.remote_addr,
 			    sizeof(p->conf.remote_addr))) {
@@ -2856,9 +3085,11 @@ str2key(char *s, char *dest, size_t max_
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
@@ -2869,7 +3100,7 @@ neighbor_consistent(struct peer *p)
 	    p->conf.auth.method == AUTH_IPSEC_IKE_AH ||
 	    p->conf.auth.method == AUTH_IPSEC_MANUAL_ESP ||
 	    p->conf.auth.method == AUTH_IPSEC_MANUAL_AH) &&
-	    !p->conf.local_addr.af) {
+	    !p->conf.local_addr.aid) {
 		yyerror("neighbors with any form of IPsec configured "
 		    "need local-address to be specified");
 		return (-1);
@@ -2889,10 +3120,6 @@ neighbor_consistent(struct peer *p)
 		return (-1);
 	}
 
-	/* for testing: enable 4-byte AS number capability if necessary */
-	if (conf->as > USHRT_MAX || p->conf.remote_as > USHRT_MAX)
-		p->conf.capabilities.as4byte = 1;
-
 	/* set default values if they where undefined */
 	p->conf.ebgp = (p->conf.remote_as != conf->as);
 	if (p->conf.announce_type == ANNOUNCE_UNDEF)
@@ -2909,6 +3136,11 @@ neighbor_consistent(struct peer *p)
 		return (-1);
 	}
 
+	/* the default MP capability is NONE */
+	for (i = 0; i < AID_MAX; i++)
+		if (p->conf.capabilities.mp[i] == -1)
+			p->conf.capabilities.mp[i] = 0;
+
 	return (0);
 }
 
@@ -2927,6 +3159,11 @@ merge_filterset(struct filter_set_head *
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
@@ -2953,9 +3190,18 @@ merge_filterset(struct filter_set_head *
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
