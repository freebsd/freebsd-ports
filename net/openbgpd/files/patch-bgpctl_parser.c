Index: bgpctl/parser.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpctl/parser.c,v
retrieving revision 1.1.1.6
retrieving revision 1.5
diff -u -p -r1.1.1.6 -r1.5
--- bgpctl/parser.c	14 Feb 2010 20:20:14 -0000	1.1.1.6
+++ bgpctl/parser.c	10 Apr 2010 12:17:18 -0000	1.5
@@ -1,4 +1,4 @@
-/*	$OpenBSD: parser.c,v 1.54 2009/06/12 16:44:02 claudio Exp $ */
+/*	$OpenBSD: parser.c,v 1.61 2010/03/08 17:02:19 claudio Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Henning Brauer <henning@openbsd.org>
@@ -16,6 +16,10 @@
  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
  */
 
+#if defined(__FreeBSD__)        /* compat */
+#include "openbsd-compat.h"
+#endif /* defined(__FreeBSD__) */
+
 #include <sys/types.h>
 #include <sys/socket.h>
 
@@ -97,6 +101,7 @@ static const struct token t_prepself[];
 static const struct token t_weight[];
 static const struct token t_irrfilter[];
 static const struct token t_irrfilter_opts[];
+static const struct token t_log[];
 
 static const struct token t_main[] = {
 	{ KEYWORD,	"reload",	RELOAD,		NULL},
@@ -105,6 +110,7 @@ static const struct token t_main[] = {
 	{ KEYWORD,	"neighbor",	NEIGHBOR,	t_neighbor},
 	{ KEYWORD,	"network",	NONE,		t_network},
 	{ KEYWORD,	"irrfilter",	IRRFILTER,	t_irrfilter},
+	{ KEYWORD,	"log",		NONE,		t_log},
 	{ ENDTOKEN,	"",		NONE,		NULL}
 };
 
@@ -311,6 +317,12 @@ static const struct token t_irrfilter_op
 	{ ENDTOKEN,	"",		NONE,			NULL}
 };
 
+static const struct token t_log[] = {
+	{ KEYWORD,	"verbose",	LOG_VERBOSE,	NULL},
+	{ KEYWORD,	"brief",	LOG_BRIEF,	NULL},
+	{ ENDTOKEN,	"",		NONE,		NULL}
+};
+
 static struct parse_result	res;
 
 const struct token	*match_token(int *argc, char **argv[],
@@ -404,15 +416,22 @@ match_token(int *argc, char **argv[], co
 		case FAMILY:
 			if (word == NULL)
 				break;
-			if (!strcmp(word, "inet") || !strcmp(word, "IPv4")) {
+			if (!strcmp(word, "inet") ||
+			    !strcasecmp(word, "IPv4")) {
+				match++;
+				t = &table[i];
+				res.aid = AID_INET;
+			}
+			if (!strcmp(word, "inet6") ||
+			    !strcasecmp(word, "IPv6")) {
 				match++;
 				t = &table[i];
-				res.af = AF_INET;
+				res.aid = AID_INET6;
 			}
-			if (!strcmp(word, "inet6") || !strcmp(word, "IPv6")) {
+			if (!strcasecmp(word, "VPNv4")) {
 				match++;
 				t = &table[i];
-				res.af = AF_INET6;
+				res.aid = AID_VPN_IPv4;
 			}
 			break;
 		case ADDRESS:
@@ -584,7 +603,7 @@ show_valid_args(const struct token table
 			fprintf(stderr, "  <pftable>\n");
 			break;
 		case FAMILY:
-			fprintf(stderr, "  [ inet | inet6 | IPv4 | IPv6 ]\n");
+			fprintf(stderr, "  [ inet | inet6 | IPv4 | IPv6 | VPNv4 ]\n");
 			break;
 		case GETOPT:
 			fprintf(stderr, "  <options>\n");
@@ -608,7 +627,7 @@ parse_addr(const char *word, struct bgpd
 	bzero(&ina, sizeof(ina));
 
 	if (inet_net_pton(AF_INET, word, &ina, sizeof(ina)) != -1) {
-		addr->af = AF_INET;
+		addr->aid = AID_INET;
 		addr->v4 = ina;
 		return (1);
 	}
@@ -618,13 +637,7 @@ parse_addr(const char *word, struct bgpd
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
@@ -663,15 +676,15 @@ parse_prefix(const char *word, struct bg
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
@@ -706,7 +719,7 @@ parse_asnum(const char *word, u_int32_t 
 		if (errstr)
 			errx(1, "AS number is %s: %s", errstr, word);
 	} else {
-		uval = strtonum(word, 0, ASNUM_MAX - 1, &errstr);
+		uval = strtonum(word, 0, UINT_MAX, &errstr);
 		if (errstr)
 			errx(1, "AS number is %s: %s", errstr, word);
 	}
@@ -882,8 +895,14 @@ bgpctl_getopt(int *argc, char **argv[], 
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
