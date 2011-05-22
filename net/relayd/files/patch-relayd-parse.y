--- relayd.orig/parse.y	2011-05-22 01:06:39.462150204 +0200
+++ relayd/parse.y	2011-05-22 01:06:54.687080706 +0200
@@ -35,7 +35,7 @@
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <arpa/nameser.h>
-#include <net/route.h>
+// FreeBSD #include <net/route.h>
 
 #include <ctype.h>
 #include <unistd.h>
@@ -93,8 +93,10 @@
 objid_t			 last_host_id = 0;
 objid_t			 last_relay_id = 0;
 objid_t			 last_proto_id = 0;
+/* FreeBSD exclude
 objid_t			 last_rt_id = 0;
 objid_t			 last_nr_id = 0;
+*/
 
 static struct rdr	*rdr = NULL;
 static struct table	*table = NULL;
@@ -103,7 +105,9 @@
 struct relaylist	 relays;
 static struct protocol	*proto = NULL;
 static struct protonode	 node;
+/* FreeBSD exclude
 static struct router	*router = NULL;
+*/
 static u_int16_t	 label = 0;
 static in_port_t	 tableport = 0;
 static int		 nodedirection;
@@ -148,12 +152,20 @@
 %token	CIPHERS CODE COOKIE DEMOTE DIGEST DISABLE ERROR EXPECT
 %token	EXTERNAL FILENAME FILTER FORWARD FROM HASH HEADER HOST ICMP
 %token	INCLUDE INET INET6 INTERFACE INTERVAL IP LABEL LISTEN
-%token	LOADBALANCE LOG LOOKUP MARK MARKED MODE NAT NO DESTINATION
-%token	NODELAY NOTHING ON PARENT PATH PORT PREFORK PRIORITY PROTO
+// FreeBSD exclude	%token	LOADBALANCE LOG LOOKUP MARK MARKED MODE NAT NO DESTINATION
+%token	LOADBALANCE LOG LOOKUP MARK MARKED MODE NAT NO
+// FreeBSD exclude	%token	NODELAY NOTHING ON PARENT PATH PORT PREFORK PRIORITY PROTO
+%token	NODELAY NOTHING ON PARENT PATH PORT PREFORK PROTO
 %token	QUERYSTR REAL REDIRECT RELAY REMOVE REQUEST RESPONSE RETRY
 %token	RETURN ROUNDROBIN ROUTE SACK SCRIPT SEND SESSION SOCKET SPLICE
+/* FreeBSD exclude
 %token	SSL STICKYADDR STYLE TABLE TAG TCP TIMEOUT TO ROUTER RTLABEL
 %token	TRANSPARENT TRAP UPDATES URL VIRTUAL WITH TTL RTABLE MATCH
+*/
+// Start FreeBSD include
+%token	SSL STICKYADDR STYLE TABLE TAG TCP TIMEOUT TO
+%token	TRANSPARENT TRAP UPDATES URL VIRTUAL WITH TTL
+// End FreeBSD include
 %token	<v.string>	STRING
 %token  <v.number>	NUMBER
 %type	<v.string>	hostname interface table
@@ -179,7 +191,7 @@
 		| grammar tabledef '\n'
 		| grammar relay '\n'
 		| grammar proto '\n'
-		| grammar router '\n'
+// FreeBSD	| grammar router '\n'
 		| grammar error '\n'		{ file->errors++; }
 		;
 
@@ -363,6 +375,7 @@
 			}
 			conf->sc_prefork_relay = $2;
 		}
+/* FreeBSD exclude
 		| DEMOTE STRING		{
 			if (loadcfg)
 				break;
@@ -386,6 +399,7 @@
 				break;
 			conf->sc_flags |= F_TRAP;
 		}
+*/
 		;
 
 loglevel	: UPDATES		{ $$ = RELAYD_OPT_LOGUPDATE; }
@@ -658,6 +672,7 @@
 			bcopy(&$2, &table->conf.timeout,
 			    sizeof(struct timeval));
 		}
+/* FreeBSD exclude
 		| DEMOTE STRING		{
 			table->conf.flags |= F_DEMOTE;
 			if (strlcpy(table->conf.demote_group, $2,
@@ -675,6 +690,7 @@
 				YYERROR;
 			}
 		}
+*/
 		| INTERVAL NUMBER	{
 			if ($2 < conf->sc_interval.tv_sec ||
 			    $2 % conf->sc_interval.tv_sec) {
@@ -1261,6 +1277,8 @@
 				    rlay->rl_conf.name);
 				YYERROR;
 			}
+			if ((rlay->rl_conf.flags & F_NATLOOK) == 0 &&
+/* FreeBSD exclude	
 			if ((rlay->rl_conf.flags & (F_NATLOOK|F_DIVERT)) ==
 			    (F_NATLOOK|F_DIVERT)) {
 				yyerror("relay %s with conflicting nat lookup "
@@ -1268,6 +1286,7 @@
 				YYERROR;
 			}
 			if ((rlay->rl_conf.flags & (F_NATLOOK|F_DIVERT)) == 0 &&
+*/
 			    rlay->rl_conf.dstss.ss_family == AF_UNSPEC &&
 			    rlay->rl_conf.dsttable == EMPTY_ID) {
 				yyerror("relay %s has no target, rdr, "
@@ -1430,11 +1449,13 @@
 			rlay->rl_conf.flags |= F_NATLOOK;
 			rlay->rl_conf.dstretry = $3;
 		}
+/* FreeBSD exclude
 		| DESTINATION retry		{
 			conf->sc_flags |= F_NEEDPF;
 			rlay->rl_conf.flags |= F_DIVERT;
 			rlay->rl_conf.dstretry = $2;
 		}
+*/
 		| tablespec	{
 			if (rlay->rl_backuptable) {
 				yyerror("only one backup table is allowed");
@@ -1459,6 +1480,7 @@
 		| HASH			{ $$ = RELAY_DSTMODE_HASH; }
 		;
 
+/* FreeBSD exclude
 router		: ROUTER STRING		{
 			struct router *rt = NULL;
 
@@ -1594,7 +1616,7 @@
 		| DISABLE		{ rlay->rl_conf.flags |= F_DISABLE; }
 		| include
 		;
-
+*/
 dstaf		: /* empty */		{
 			rlay->rl_conf.dstaf.ss_family = AF_UNSPEC;
 		}
@@ -1670,6 +1692,7 @@
 			}
 			hst->conf.parentid = $2;
 		}
+/* FreeBSD exclude
 		| PRIORITY NUMBER		{
 			if (hst->conf.priority) {
 				yyerror("priority already set");
@@ -1681,6 +1704,7 @@
 			}
 			hst->conf.priority = $2;
 		}
+*/
 		| IP TTL NUMBER		{
 			if (hst->conf.ttl) {
 				yyerror("ttl value already set");
@@ -1794,8 +1818,10 @@
 		{ "ciphers",		CIPHERS },
 		{ "code",		CODE },
 		{ "cookie",		COOKIE },
+/* FreeBSD exclude
 		{ "demote",		DEMOTE },
 		{ "destination",	DESTINATION },
+*/
 		{ "digest",		DIGEST },
 		{ "disable",		DISABLE },
 		{ "error",		ERROR },
@@ -1833,7 +1859,7 @@
 		{ "path",		PATH },
 		{ "port",		PORT },
 		{ "prefork",		PREFORK },
-		{ "priority",		PRIORITY },
+// FreeBSD	{ "priority",		PRIORITY },
 		{ "protocol",		PROTO },
 		{ "query",		QUERYSTR },
 		{ "real",		REAL },
@@ -1846,9 +1872,11 @@
 		{ "return",		RETURN },
 		{ "roundrobin",		ROUNDROBIN },
 		{ "route",		ROUTE },
+/* FreeBSD exclude
 		{ "router",		ROUTER },
 		{ "rtable",		RTABLE },
 		{ "rtlabel",		RTLABEL },
+*/
 		{ "sack",		SACK },
 		{ "script",		SCRIPT },
 		{ "send",		SEND },
@@ -1864,7 +1892,7 @@
 		{ "timeout",		TIMEOUT },
 		{ "to",			TO },
 		{ "transparent",	TRANSPARENT },
-		{ "trap",		TRAP },
+// FreeBSD	{ "trap",		TRAP },
 		{ "ttl",		TTL },
 		{ "updates",		UPDATES },
 		{ "url",		URL },
@@ -2096,7 +2124,8 @@
 	(isalnum(x) || (ispunct(x) && x != '(' && x != ')' && \
 	x != '{' && x != '}' && x != '<' && x != '>' && \
 	x != '!' && x != '=' && x != '#' && \
-	x != ',' && x != '/'))
+	x != ','))
+// FreeBSD exclude	x != ',' && x != '/'))
 
 	if (isalnum(c) || c == ':' || c == '_') {
 		do {
@@ -2240,13 +2269,14 @@
 	loadcfg = 1;
 	errors = 0;
 	last_host_id = last_table_id = last_rdr_id = last_proto_id =
-	    last_relay_id = last_rt_id = last_nr_id = 0;
+// FreeBSD	last_relay_id = last_rt_id = last_nr_id = 0;
+	    last_relay_id = 0;
 
 	rdr = NULL;
 	table = NULL;
 	rlay = NULL;
 	proto = NULL;
-	router = NULL;
+// FreeBSD	router = NULL;
 
 	if ((file = pushfile(filename, 0)) == NULL)
 		return (-1);
@@ -2276,8 +2306,8 @@
 	}
 
 	if (TAILQ_EMPTY(conf->sc_rdrs) &&
-	    TAILQ_EMPTY(conf->sc_relays) &&
-	    TAILQ_EMPTY(conf->sc_rts)) {
+	    TAILQ_EMPTY(conf->sc_relays) /* FreeBSD exclude &&
+	    TAILQ_EMPTY(conf->sc_rts) */ ) {
 		log_warnx("no actions, nothing to do");
 		errors++;
 	}
@@ -2493,7 +2523,8 @@
 	hints.ai_family = PF_UNSPEC;
 	hints.ai_socktype = SOCK_DGRAM; /* DUMMY */
 	error = getaddrinfo(s, NULL, &hints, &res0);
-	if (error == EAI_AGAIN || error == EAI_NODATA || error == EAI_NONAME)
+//	if (error == EAI_AGAIN || error == EAI_NODATA || error == EAI_NONAME)
+	if (error == EAI_AGAIN || error == EAI_NONAME)
 		return (0);
 	if (error) {
 		log_warnx("%s: could not parse \"%s\": %s", __func__, s,
