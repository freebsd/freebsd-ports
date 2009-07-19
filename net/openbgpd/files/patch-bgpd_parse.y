Index: bgpd/parse.y
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/parse.y,v
retrieving revision 1.1.1.1
retrieving revision 1.4
diff -u -p -r1.1.1.1 -r1.4
--- bgpd/parse.y	30 Jun 2009 05:46:15 -0000	1.1.1.1
+++ bgpd/parse.y	9 Jul 2009 17:22:14 -0000	1.4
@@ -1,4 +1,4 @@
-/*	$OpenBSD: parse.y,v 1.217 2008/07/08 13:14:58 claudio Exp $ */
+/*	$OpenBSD: parse.y,v 1.231 2009/06/06 01:10:29 claudio Exp $ */
 
 /*
  * Copyright (c) 2002, 2003, 2004 Henning Brauer <henning@openbsd.org>
@@ -39,6 +39,7 @@
 #include "bgpd.h"
 #include "mrt.h"
 #include "session.h"
+#include "rde.h"
 
 TAILQ_HEAD(files, file)		 files = TAILQ_HEAD_INITIALIZER(files);
 static struct file {
@@ -110,7 +111,10 @@ struct filter_match_l {
 struct peer	*alloc_peer(void);
 struct peer	*new_peer(void);
 struct peer	*new_group(void);
-int		 add_mrtconfig(enum mrt_type, char *, time_t, struct peer *);
+int		 add_mrtconfig(enum mrt_type, char *, time_t, struct peer *,
+		    char *);
+int		 add_rib(char *, u_int16_t);
+int		 find_rib(char *);
 int		 get_id(struct peer *);
 int		 expand_rule(struct filter_rule *, struct filter_peers_l *,
 		    struct filter_match_l *, struct filter_set_head *);
@@ -155,10 +159,10 @@ typedef struct {
 %}
 
 %token	AS ROUTERID HOLDTIME YMIN LISTEN ON FIBUPDATE RTABLE
-%token	RDE EVALUATE IGNORE COMPARE
+%token	RDE RIB EVALUATE IGNORE COMPARE
 %token	GROUP NEIGHBOR NETWORK
-%token	REMOTEAS DESCR LOCALADDR MULTIHOP PASSIVE MAXPREFIX RESTART
-%token	ANNOUNCE DEMOTE
+%token	REMOTEAS DESCR LLIFACE LOCALADDR MULTIHOP PASSIVE MAXPREFIX RESTART
+%token	ANNOUNCE DEMOTE CONNECTRETRY
 %token	ENFORCE NEIGHBORAS CAPABILITIES REFLECTOR DEPEND DOWN SOFTRECONFIG
 %token	DUMP IN OUT
 %token	LOG ROUTECOLL TRANSPARENT
@@ -178,7 +182,7 @@ typedef struct {
 %token	<v.number>		NUMBER
 %type	<v.number>		asnumber as4number optnumber yesno inout
 %type	<v.number>		espah family restart
-%type	<v.string>		string
+%type	<v.string>		string filter_rib
 %type	<v.addr>		address
 %type	<v.prefix>		prefix addrspec
 %type	<v.u8>			action quick direction delete
@@ -207,8 +211,8 @@ grammar		: /* empty */
 		;
 
 asnumber	: NUMBER			{
-			if ($1 < 0 || $1 >= USHRT_MAX) {
-				yyerror("AS too big: max %u", USHRT_MAX - 1);
+			if ($1 < 0 || $1 >= ASNUM_MAX) {
+				yyerror("AS too big: max %u", ASNUM_MAX - 1);
 				YYERROR;
 			}
 		}
@@ -381,6 +385,24 @@ conf_main	: AS as4number		{
 			else
 				conf->flags &= ~BGPD_FLAG_NO_EVALUATE;
 		}
+		| RDE RIB STRING {
+			if (add_rib($3, F_RIB_NOFIB)) {
+				free($3);
+				YYERROR;
+			}
+			free($3);
+		}
+		| RDE RIB STRING yesno EVALUATE {
+			if ($4) {
+				free($3);
+				YYERROR;
+			}
+			if (!add_rib($3, F_RIB_NOEVALUATE)) {
+				free($3);
+				YYERROR;
+			}
+			free($3);
+		}
 		| TRANSPARENT yesno	{
 			if ($2 == 1)
 				conf->flags |= BGPD_FLAG_DECISION_TRANS_AS;
@@ -469,12 +491,42 @@ conf_main	: AS as4number		{
 				YYERROR;
 			}
 			free($2);
-			if (add_mrtconfig(action, $3, $4, NULL) == -1) {
+			if (add_mrtconfig(action, $3, $4, NULL, NULL) == -1) {
 				free($3);
 				YYERROR;
 			}
 			free($3);
 		}
+		| DUMP RIB STRING STRING STRING optnumber		{
+			int action;
+
+			if ($6 < 0 || $6 > UINT_MAX) {
+				yyerror("bad timeout");
+				free($3);
+				free($4);
+				free($5);
+				YYERROR;
+			}
+			if (!strcmp($4, "table"))
+				action = MRT_TABLE_DUMP;
+			else if (!strcmp($4, "table-mp"))
+				action = MRT_TABLE_DUMP_MP;
+			else {
+				yyerror("unknown mrt dump type");
+				free($3);
+				free($4);
+				free($5);
+				YYERROR;
+			}
+			free($4);
+			if (add_mrtconfig(action, $5, $6, NULL, $3) == -1) {
+				free($3);
+				free($5);
+				YYERROR;
+			}
+			free($3);
+			free($5);
+		}
 		| mrtdump
 		| RDE STRING EVALUATE		{
 			if (!strcmp($2, "route-age"))
@@ -523,11 +575,23 @@ conf_main	: AS as4number		{
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
+		}
+		| CONNECTRETRY NUMBER {
+			if ($2 > USHRT_MAX || $2 < 1) {
+				yyerror("invalid connect-retry");
+				YYERROR;
+			}
+			conf->connectretry = $2;
 		}
 		;
 
@@ -550,7 +614,8 @@ mrtdump		: DUMP STRING inout STRING optn
 				free($4);
 				YYERROR;
 			}
-			if (add_mrtconfig(action, $4, $5, curpeer) == -1) {
+			if (add_mrtconfig(action, $4, $5, curpeer, NULL) ==
+			    -1) {
 				free($2);
 				free($4);
 				YYERROR;
@@ -742,6 +807,17 @@ peeropts	: REMOTEAS as4number	{
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
@@ -759,6 +835,22 @@ peeropts	: REMOTEAS as4number	{
 		| DOWN		{
 			curpeer->conf.down = 1;
 		}
+		| RIB STRING	{
+			if (!find_rib($2)) {
+				yyerror("rib \"%s\" does not exist.", $2);
+				free($2);
+				YYERROR;
+			}
+			if (strlcpy(curpeer->conf.rib, $2,
+			    sizeof(curpeer->conf.rib)) >=
+			    sizeof(curpeer->conf.rib)) {
+				yyerror("rib name \"%s\" too long: max %u",
+				   $2, sizeof(curpeer->conf.rib) - 1);
+				free($2);
+				YYERROR;
+			}
+			free($2);
+		}
 		| HOLDTIME NUMBER	{
 			if ($2 < MIN_HOLDTIME || $2 > USHRT_MAX) {
 				yyerror("holdtime must be between %u and %u",
@@ -1058,6 +1150,12 @@ peeropts	: REMOTEAS as4number	{
 			else
 				curpeer->conf.softreconfig_out = $3;
 		}
+		| TRANSPARENT yesno	{
+			if ($2 == 1)
+				curpeer->conf.flags |= PEERFLAG_TRANS_AS;
+			else
+				curpeer->conf.flags &= ~PEERFLAG_TRANS_AS;
+		}
 		;
 
 restart		: /* nada */		{ $$ = 0; }
@@ -1115,16 +1213,37 @@ encspec		: /* nada */	{
 		}
 		;
 
-filterrule	: action quick direction filter_peer_h filter_match_h filter_set
+filterrule	: action quick filter_rib direction filter_peer_h filter_match_h filter_set
 		{
 			struct filter_rule	 r;
 
 			bzero(&r, sizeof(r));
 			r.action = $1;
 			r.quick = $2;
-			r.dir = $3;
-
-			if (expand_rule(&r, $4, &$5, $6) == -1)
+			r.dir = $4;
+			if ($3) {
+				if (r.dir != DIR_IN) {
+					yyerror("rib only allowed on \"from\" "
+					    "rules.");
+					free($3);
+					YYERROR;
+				}
+				if (!find_rib($3)) {
+					yyerror("rib \"%s\" does not exist.",
+					    $3);
+					free($3);
+					YYERROR;
+				}
+				if (strlcpy(r.rib, $3, sizeof(r.rib)) >=
+				    sizeof(r.rib)) {
+					yyerror("rib name \"%s\" too long: "
+					    "max %u", $3, sizeof(r.rib) - 1);
+					free($3);
+					YYERROR;
+				}
+				free($3);
+			}
+			if (expand_rule(&r, $5, &$6, $7) == -1)
 				YYERROR;
 		}
 		;
@@ -1142,6 +1261,9 @@ direction	: FROM		{ $$ = DIR_IN; }
 		| TO		{ $$ = DIR_OUT; }
 		;
 
+filter_rib	: /* empty */	{ $$ = NULL; }
+		| RIB STRING	{ $$ = $2; }
+
 filter_peer_h	: filter_peer
 		| '{' filter_peer_l '}'		{ $$ = $2; }
 		;
@@ -1396,7 +1518,7 @@ prefixlenop	: unaryop NUMBER		{
 				YYERROR;
 			}
 			if ($1 >= $3) {
-				yyerror("start prefixlen is bigger that end");
+				yyerror("start prefixlen is bigger than end");
 				YYERROR;
 			}
 			$$.op = $2;
@@ -1771,6 +1893,7 @@ lookup(char *s)
 		{ "capabilities",	CAPABILITIES},
 		{ "community",		COMMUNITY},
 		{ "compare",		COMPARE},
+		{ "connect-retry",	CONNECTRETRY},
 		{ "connected",		CONNECTED},
 		{ "delete",		DELETE},
 		{ "demote",		DEMOTE},
@@ -1792,6 +1915,9 @@ lookup(char *s)
 		{ "include",		INCLUDE},
 		{ "inet",		IPV4},
 		{ "inet6",		IPV6},
+#if defined(IPV6_LINKLOCAL_PEER)
+		{ "interface",		LLIFACE},
+#endif
 		{ "ipsec",		IPSEC},
 		{ "key",		KEY},
 		{ "listen",		LISTEN},
@@ -1826,6 +1952,7 @@ lookup(char *s)
 		{ "reject",		REJECT},
 		{ "remote-as",		REMOTEAS},
 		{ "restart",		RESTART},
+		{ "rib",		RIB},
 		{ "route-collector",	ROUTECOLL},
 		{ "route-reflector",	REFLECTOR},
 		{ "router-id",		ROUTERID},
@@ -1933,11 +2060,13 @@ findeol(void)
 	int	c;
 
 	parsebuf = NULL;
-	pushback_index = 0;
 
 	/* skip to either EOF or the first real EOL */
 	while (1) {
-		c = lgetc(0);
+		if (pushback_index)
+			c = pushback_buffer[--pushback_index];
+		else
+			c = lgetc(0);
 		if (c == '\n') {
 			file->lineno++;
 			break;
@@ -2118,9 +2247,13 @@ pushfile(const char *name, int secret)
 {
 	struct file	*nfile;
 
-	if ((nfile = calloc(1, sizeof(struct file))) == NULL ||
-	    (nfile->name = strdup(name)) == NULL) {
+	if ((nfile = calloc(1, sizeof(struct file))) == NULL) {
+		log_warn("malloc");
+		return (NULL);
+	}
+	if ((nfile->name = strdup(name)) == NULL) {
 		log_warn("malloc");
+		free(nfile);
 		return (NULL);
 	}
 	if ((nfile->stream = fopen(nfile->name, "r")) == NULL) {
@@ -2207,6 +2340,9 @@ parse_config(char *filename, struct bgpd
 	/* init the empty filter list for later */
 	TAILQ_INIT(xfilter_l);
 
+	add_rib("Adj-RIB-In", F_RIB_NOEVALUATE);
+	add_rib("Loc-RIB", 0);
+
 	yyparse();
 	errors = file->errors;
 	popfile();
@@ -2452,6 +2588,8 @@ alloc_peer(void)
 	p->conf.capabilities.refresh = 1;
 	p->conf.capabilities.restart = 0;
 	p->conf.capabilities.as4byte = 0;
+	p->conf.local_as = conf->as;
+	p->conf.local_short_as = conf->short_as;
 	p->conf.softreconfig_in = 1;
 	p->conf.softreconfig_out = 1;
 
@@ -2473,10 +2611,16 @@ new_peer(void)
 		if (strlcpy(p->conf.descr, curgroup->conf.descr,
 		    sizeof(p->conf.descr)) >= sizeof(p->conf.descr))
 			fatalx("new_peer descr strlcpy");
+		if (strlcpy(p->conf.lliface, curgroup->conf.lliface,
+		    sizeof(p->conf.lliface)) >= sizeof(p->conf.lliface))
+			fatalx("new_peer lliface strlcpy");
 		p->conf.groupid = curgroup->conf.id;
+		p->conf.local_as = curgroup->conf.local_as;
+		p->conf.local_short_as = curgroup->conf.local_short_as;
 	}
 	p->next = NULL;
-
+	if (conf->flags & BGPD_FLAG_DECISION_TRANS_AS)
+		p->conf.flags |= PEERFLAG_TRANS_AS;
 	return (p);
 }
 
@@ -2487,11 +2631,15 @@ new_group(void)
 }
 
 int
-add_mrtconfig(enum mrt_type type, char *name, time_t timeout, struct peer *p)
+add_mrtconfig(enum mrt_type type, char *name, time_t timeout, struct peer *p,
+    char *rib)
 {
 	struct mrt	*m, *n;
 
 	LIST_FOREACH(m, mrtconf, entry) {
+		if ((rib && strcmp(rib, m->rib)) ||
+		    (!rib && *m->rib))
+			continue;
 		if (p == NULL) {
 			if (m->peer_id != 0 || m->group_id != 0)
 				continue;
@@ -2527,6 +2675,20 @@ add_mrtconfig(enum mrt_type type, char *
 			n->group_id = 0;
 		}
 	}
+	if (rib) {
+		if (!find_rib(rib)) {
+			yyerror("rib \"%s\" does not exist.", rib);
+			free(n);
+			return (-1);
+		}
+		if (strlcpy(n->rib, rib, sizeof(n->rib)) >=
+		    sizeof(n->rib)) {
+			yyerror("rib name \"%s\" too long: max %u",
+			    name, sizeof(n->rib) - 1);
+			free(n);
+			return (-1);
+		}
+	}
 
 	LIST_INSERT_HEAD(mrtconf, n, entry);
 
@@ -2534,6 +2696,42 @@ add_mrtconfig(enum mrt_type type, char *
 }
 
 int
+add_rib(char *name, u_int16_t flags)
+{
+	struct rde_rib	*rr;
+
+	if (find_rib(name)) {
+		yyerror("rib \"%s\" allready exists.", name);
+		return (-1);
+	}
+
+	if ((rr = calloc(1, sizeof(*rr))) == NULL) {
+		log_warn("add_rib");
+		return (-1);
+	}
+	if (strlcpy(rr->name, name, sizeof(rr->name)) >= sizeof(rr->name)) {
+		yyerror("rib name \"%s\" too long: max %u",
+		   name, sizeof(rr->name) - 1);
+		return (-1);
+	}
+	rr->flags |= flags;
+	SIMPLEQ_INSERT_TAIL(&ribnames, rr, entry);
+	return (0);
+}
+
+int
+find_rib(char *name)
+{
+	struct rde_rib	*rr;
+
+	SIMPLEQ_FOREACH(rr, &ribnames, entry) {
+		if (!strcmp(rr->name, name))
+			return (1);
+	}
+	return (0);
+}
+
+int
 get_id(struct peer *newpeer)
 {
 	struct peer	*p;
