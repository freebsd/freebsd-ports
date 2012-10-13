Index: bgpctl/parser.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpctl/parser.c,v
retrieving revision 1.1.1.6
retrieving revision 1.7
diff -u -p -r1.1.1.6 -r1.7
--- bgpctl/parser.c	14 Feb 2010 20:20:14 -0000	1.1.1.6
+++ bgpctl/parser.c	13 Oct 2012 18:35:56 -0000	1.7
@@ -1,4 +1,4 @@
-/*	$OpenBSD: parser.c,v 1.54 2009/06/12 16:44:02 claudio Exp $ */
+/*	$OpenBSD: parser.c,v 1.64 2012/03/27 18:24:11 claudio Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Henning Brauer <henning@openbsd.org>
@@ -16,11 +16,16 @@
  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
  */
 
+#if defined(__FreeBSD__)        /* compat */
+#include "openbsd-compat.h"
+#endif /* defined(__FreeBSD__) */
+
 #include <sys/types.h>
 #include <sys/socket.h>
 
 #include <err.h>
 #include <errno.h>
+#include <fcntl.h>
 #include <limits.h>
 #include <netdb.h>
 #include <stdio.h>
@@ -52,7 +57,9 @@ enum token_type {
 	PREPSELF,
 	WEIGHT,
 	FAMILY,
-	GETOPT
+	GETOPT,
+	RTABLE,
+	FILENAME
 };
 
 enum getopts {
@@ -72,14 +79,18 @@ static const struct token t_show[];
 static const struct token t_show_summary[];
 static const struct token t_show_fib[];
 static const struct token t_show_rib[];
+static const struct token t_show_mrt[];
+static const struct token t_show_mrt_file[];
 static const struct token t_show_rib_neigh[];
+static const struct token t_show_mrt_neigh[];
 static const struct token t_show_rib_rib[];
 static const struct token t_show_neighbor[];
 static const struct token t_show_neighbor_modifiers[];
 static const struct token t_fib[];
 static const struct token t_neighbor[];
 static const struct token t_neighbor_modifiers[];
-static const struct token t_show_as[];
+static const struct token t_show_rib_as[];
+static const struct token t_show_mrt_as[];
 static const struct token t_show_prefix[];
 static const struct token t_show_ip[];
 static const struct token t_show_community[];
@@ -97,6 +108,9 @@ static const struct token t_prepself[];
 static const struct token t_weight[];
 static const struct token t_irrfilter[];
 static const struct token t_irrfilter_opts[];
+static const struct token t_log[];
+static const struct token t_fib_table[];
+static const struct token t_show_fib_table[];
 
 static const struct token t_main[] = {
 	{ KEYWORD,	"reload",	RELOAD,		NULL},
@@ -105,6 +119,7 @@ static const struct token t_main[] = {
 	{ KEYWORD,	"neighbor",	NEIGHBOR,	t_neighbor},
 	{ KEYWORD,	"network",	NONE,		t_network},
 	{ KEYWORD,	"irrfilter",	IRRFILTER,	t_irrfilter},
+	{ KEYWORD,	"log",		NONE,		t_log},
 	{ ENDTOKEN,	"",		NONE,		NULL}
 };
 
@@ -116,8 +131,10 @@ static const struct token t_show[] = {
 	{ KEYWORD,	"network",	NETWORK_SHOW,	t_network_show},
 	{ KEYWORD,	"nexthop",	SHOW_NEXTHOP,	NULL},
 	{ KEYWORD,	"rib",		SHOW_RIB,	t_show_rib},
+	{ KEYWORD,	"tables",	SHOW_FIB_TABLES, NULL},
 	{ KEYWORD,	"ip",		NONE,		t_show_ip},
 	{ KEYWORD,	"summary",	SHOW_SUMMARY,	t_show_summary},
+	{ KEYWORD,	"mrt",		SHOW_MRT,	t_show_mrt},
 	{ ENDTOKEN,	"",		NONE,		NULL}
 };
 
@@ -128,24 +145,26 @@ static const struct token t_show_summary
 };
 
 static const struct token t_show_fib[] = {
-	{ NOTOKEN,	"",		NONE,			NULL},
-	{ FLAG,		"connected",	F_CONNECTED,		t_show_fib},
-	{ FLAG,		"static",	F_STATIC,		t_show_fib},
-	{ FLAG,		"bgp",		F_BGPD_INSERTED,	t_show_fib},
-	{ FLAG,		"nexthop",	F_NEXTHOP,		t_show_fib},
-	{ FAMILY,	"",		NONE,			t_show_fib},
-	{ ADDRESS,	"",		NONE,			NULL},
-	{ ENDTOKEN,	"",		NONE,			NULL}
+	{ NOTOKEN,	"",		NONE,		 NULL},
+	{ FLAG,		"connected",	F_CONNECTED,	 t_show_fib},
+	{ FLAG,		"static",	F_STATIC,	 t_show_fib},
+	{ FLAG,		"bgp",		F_BGPD_INSERTED, t_show_fib},
+	{ FLAG,		"nexthop",	F_NEXTHOP,	 t_show_fib},
+	{ KEYWORD,	"table",	NONE,		 t_show_fib_table},
+	{ FAMILY,	"",		NONE,		 t_show_fib},
+	{ ADDRESS,	"",		NONE,		 NULL},
+	{ ENDTOKEN,	"",		NONE,		 NULL}
 };
 
 static const struct token t_show_rib[] = {
 	{ NOTOKEN,	"",		NONE,		NULL},
-	{ ASTYPE,	"as",		AS_ALL,		t_show_as},
-	{ ASTYPE,	"source-as",	AS_SOURCE,	t_show_as},
-	{ ASTYPE,	"transit-as",	AS_TRANSIT,	t_show_as},
-	{ ASTYPE,	"peer-as",	AS_PEER,	t_show_as},
+	{ ASTYPE,	"as",		AS_ALL,		t_show_rib_as},
+	{ ASTYPE,	"source-as",	AS_SOURCE,	t_show_rib_as},
+	{ ASTYPE,	"transit-as",	AS_TRANSIT,	t_show_rib_as},
+	{ ASTYPE,	"peer-as",	AS_PEER,	t_show_rib_as},
 	{ ASTYPE,	"empty-as",	AS_EMPTY,	t_show_rib},
 	{ KEYWORD,	"community",	NONE,		t_show_community},
+	{ FLAG,		"selected",	F_CTL_ACTIVE,	t_show_rib},
 	{ FLAG,		"detail",	F_CTL_DETAIL,	t_show_rib},
 	{ FLAG,		"in",		F_CTL_ADJ_IN,	t_show_rib},
 	{ FLAG,		"out",		F_CTL_ADJ_OUT,	t_show_rib},
@@ -158,12 +177,38 @@ static const struct token t_show_rib[] =
 	{ ENDTOKEN,	"",		NONE,		NULL}
 };
 
+
+static const struct token t_show_mrt[] = {
+	{ NOTOKEN,	"",		NONE,		NULL},
+	{ ASTYPE,	"as",		AS_ALL,		t_show_mrt_as},
+	{ ASTYPE,	"source-as",	AS_SOURCE,	t_show_mrt_as},
+	{ ASTYPE,	"transit-as",	AS_TRANSIT,	t_show_mrt_as},
+	{ ASTYPE,	"peer-as",	AS_PEER,	t_show_mrt_as},
+	{ ASTYPE,	"empty-as",	AS_EMPTY,	t_show_mrt},
+	{ FLAG,		"detail",	F_CTL_DETAIL,	t_show_mrt},
+	{ KEYWORD,	"neighbor",	NONE,		t_show_mrt_neigh},
+	{ KEYWORD,	"file",		NONE,		t_show_mrt_file},
+	{ FAMILY,	"",		NONE,		t_show_mrt},
+	{ PREFIX,	"",		NONE,		t_show_prefix},
+	{ ENDTOKEN,	"",		NONE,		NULL}
+};
+
+static const struct token t_show_mrt_file[] = {
+	{ FILENAME,	"",		NONE,		t_show_mrt},
+	{ ENDTOKEN,	"",		NONE,	NULL}
+};
+
 static const struct token t_show_rib_neigh[] = {
 	{ PEERADDRESS,	"",		NONE,	t_show_rib},
 	{ PEERDESC,	"",		NONE,	t_show_rib},
 	{ ENDTOKEN,	"",		NONE,	NULL}
 };
 
+static const struct token t_show_mrt_neigh[] = {
+	{ PEERADDRESS,	"",		NONE,	t_show_mrt},
+	{ ENDTOKEN,	"",		NONE,	NULL}
+};
+
 static const struct token t_show_rib_rib[] = {
 	{ RIBNAME,	"",		NONE,	t_show_rib},
 	{ ENDTOKEN,	"",		NONE,	NULL}
@@ -187,6 +232,7 @@ static const struct token t_show_neighbo
 static const struct token t_fib[] = {
 	{ KEYWORD,	"couple",	FIB_COUPLE,	NULL},
 	{ KEYWORD,	"decouple",	FIB_DECOUPLE,	NULL},
+	{ KEYWORD,	"table",	NONE,		t_fib_table},
 	{ ENDTOKEN,	"",		NONE,		NULL}
 };
 
@@ -204,11 +250,16 @@ static const struct token t_neighbor_mod
 	{ ENDTOKEN,	"",		NONE,			NULL}
 };
 
-static const struct token t_show_as[] = {
+static const struct token t_show_rib_as[] = {
 	{ ASNUM,	"",		NONE,		t_show_rib},
 	{ ENDTOKEN,	"",		NONE,		NULL}
 };
 
+static const struct token t_show_mrt_as[] = {
+	{ ASNUM,	"",		NONE,		t_show_mrt},
+	{ ENDTOKEN,	"",		NONE,		NULL}
+};
+
 static const struct token t_show_prefix[] = {
 	{ NOTOKEN,	"",		NONE,		NULL},
 	{ FLAG,		"all",		F_LONGER,	NULL},
@@ -231,6 +282,7 @@ static const struct token t_network[] = 
 	{ KEYWORD,	"delete",	NETWORK_REMOVE,	t_prefix},
 	{ KEYWORD,	"flush",	NETWORK_FLUSH,	NULL},
 	{ KEYWORD,	"show",		NETWORK_SHOW,	t_network_show},
+	{ KEYWORD,	"mrt",		NETWORK_MRT,	t_show_mrt},
 	{ ENDTOKEN,	"",		NONE,		NULL}
 };
 
@@ -311,6 +363,22 @@ static const struct token t_irrfilter_op
 	{ ENDTOKEN,	"",		NONE,			NULL}
 };
 
+static const struct token t_log[] = {
+	{ KEYWORD,	"verbose",	LOG_VERBOSE,	NULL},
+	{ KEYWORD,	"brief",	LOG_BRIEF,	NULL},
+	{ ENDTOKEN,	"",		NONE,		NULL}
+};
+
+static const struct token t_fib_table[] = {
+	{ RTABLE,	"",			NONE,	t_fib},
+	{ ENDTOKEN,	"",			NONE,	NULL}
+};
+
+static const struct token t_show_fib_table[] = {
+	{ RTABLE,	"",			NONE,	t_show_fib},
+	{ ENDTOKEN,	"",			NONE,	NULL}
+};
+
 static struct parse_result	res;
 
 const struct token	*match_token(int *argc, char **argv[],
@@ -404,15 +472,22 @@ match_token(int *argc, char **argv[], co
 		case FAMILY:
 			if (word == NULL)
 				break;
-			if (!strcmp(word, "inet") || !strcmp(word, "IPv4")) {
+			if (!strcmp(word, "inet") ||
+			    !strcasecmp(word, "IPv4")) {
 				match++;
 				t = &table[i];
-				res.af = AF_INET;
+				res.aid = AID_INET;
 			}
-			if (!strcmp(word, "inet6") || !strcmp(word, "IPv6")) {
+			if (!strcmp(word, "inet6") ||
+			    !strcasecmp(word, "IPv6")) {
 				match++;
 				t = &table[i];
-				res.af = AF_INET6;
+				res.aid = AID_INET6;
+			}
+			if (!strcasecmp(word, "VPNv4")) {
+				match++;
+				t = &table[i];
+				res.aid = AID_VPN_IPv4;
 			}
 			break;
 		case ADDRESS:
@@ -485,6 +560,7 @@ match_token(int *argc, char **argv[], co
 		case PREPNBR:
 		case PREPSELF:
 		case WEIGHT:
+		case RTABLE:
 			if (word != NULL && strlen(word) > 0 &&
 			    parse_number(word, &res, table[i].type)) {
 				match++;
@@ -518,6 +594,23 @@ match_token(int *argc, char **argv[], co
 				t = &table[i];
 			}
 			break;
+		case FILENAME:
+			if (word != NULL && strlen(word) > 0) {
+				if ((res.mrtfd = open(word, O_RDONLY)) == -1) {
+					/*
+					 * ignore error if path has no / and
+					 * does not exist. In hope to print
+					 * usage.
+					 */
+					if (errno == ENOENT &&
+					    !strchr(word, '/'))
+						break;
+					err(1, "mrt open(%s)", word);
+				}
+				match++;
+				t = &table[i];
+			}
+			break;
 		case ENDTOKEN:
 			break;
 		}
@@ -577,6 +670,9 @@ show_valid_args(const struct token table
 		case WEIGHT:
 			fprintf(stderr, "  <number>\n");
 			break;
+		case RTABLE:
+			fprintf(stderr, "  <rtableid>\n");
+			break;
 		case NEXTHOP:
 			fprintf(stderr, "  <address>\n");
 			break;
@@ -584,11 +680,14 @@ show_valid_args(const struct token table
 			fprintf(stderr, "  <pftable>\n");
 			break;
 		case FAMILY:
-			fprintf(stderr, "  [ inet | inet6 | IPv4 | IPv6 ]\n");
+			fprintf(stderr, "  [ inet | inet6 | IPv4 | IPv6 | VPNv4 ]\n");
 			break;
 		case GETOPT:
 			fprintf(stderr, "  <options>\n");
 			break;
+		case FILENAME:
+			fprintf(stderr, "  <filename>\n");
+			break;
 		case ENDTOKEN:
 			break;
 		}
@@ -608,7 +707,7 @@ parse_addr(const char *word, struct bgpd
 	bzero(&ina, sizeof(ina));
 
 	if (inet_net_pton(AF_INET, word, &ina, sizeof(ina)) != -1) {
-		addr->af = AF_INET;
+		addr->aid = AID_INET;
 		addr->v4 = ina;
 		return (1);
 	}
@@ -618,13 +717,7 @@ parse_addr(const char *word, struct bgpd
 	hints.ai_socktype = SOCK_DGRAM; /*dummy*/
 	hints.ai_flags = AI_NUMERICHOST;
 	if (getaddrinfo(word, "0", &hints, &r) == 0) {
-		addr->af = AF_INET6;
-		memcpy(&addr->v6,
-		    &((struct sockaddr_in6 *)r->ai_addr)->sin6_addr,
-		    sizeof(addr->v6));
-		addr->scope_id =
-		    ((struct sockaddr_in6 *)r->ai_addr)->sin6_scope_id;
-
+		sa2addr(r->ai_addr, addr);
 		freeaddrinfo(r);
 		return (1);
 	}
@@ -647,7 +740,7 @@ parse_prefix(const char *word, struct bg
 	if ((p = strrchr(word, '/')) != NULL) {
 		mask = strtonum(p + 1, 0, 128, &errstr);
 		if (errstr)
-			errx(1, "invalid netmask: %s", errstr);
+			errx(1, "netmask %s", errstr);
 
 		if ((ps = malloc(strlen(word) - strlen(p) + 1)) == NULL)
 			err(1, "parse_prefix: malloc");
@@ -663,15 +756,15 @@ parse_prefix(const char *word, struct bg
 		if (parse_addr(word, addr) == 0)
 			return (0);
 
-	switch (addr->af) {
-	case AF_INET:
+	switch (addr->aid) {
+	case AID_INET:
 		if (mask == -1)
 			mask = 32;
 		if (mask > 32)
 			errx(1, "invalid netmask: too large");
 		addr->v4.s_addr = addr->v4.s_addr & htonl(prefixlen2mask(mask));
 		break;
-	case AF_INET6:
+	case AID_INET6:
 		if (mask == -1)
 			mask = 128;
 		inet6applymask(&addr->v6, &addr->v6, mask);
@@ -706,7 +799,7 @@ parse_asnum(const char *word, u_int32_t 
 		if (errstr)
 			errx(1, "AS number is %s: %s", errstr, word);
 	} else {
-		uval = strtonum(word, 0, ASNUM_MAX - 1, &errstr);
+		uval = strtonum(word, 0, UINT_MAX, &errstr);
 		if (errstr)
 			errx(1, "AS number is %s: %s", errstr, word);
 	}
@@ -730,6 +823,11 @@ parse_number(const char *word, struct pa
 		errx(1, "number is %s: %s", errstr, word);
 
 	/* number was parseable */
+	if (type == RTABLE) {
+		r->rtableid = uval;
+		return (1);
+	}
+
 	if ((fs = calloc(1, sizeof(struct filter_set))) == NULL)
 		err(1, NULL);
 	switch (type) {
@@ -882,8 +980,14 @@ bgpctl_getopt(int *argc, char **argv[], 
 	int	  ch;
 
 	optind = optreset = 1;
-	while ((ch = getopt((*argc) + 1, (*argv) - 1, "o:")) != -1) {
+	while ((ch = getopt((*argc) + 1, (*argv) - 1, "46o:")) != -1) {
 		switch (ch) {
+		case '4':
+			res.flags = (res.flags | F_IPV4) & ~F_IPV6;
+			break;
+		case '6':
+			res.flags = (res.flags | F_IPV6) & ~F_IPV4;
+			break;
 		case 'o':
 			res.irr_outdir = optarg;
 			break;
