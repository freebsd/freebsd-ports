Index: bgpctl/parser.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpctl/parser.c,v
retrieving revision 1.1.1.1
retrieving revision 1.3
diff -u -p -r1.1.1.1 -r1.3
--- bgpctl/parser.c	30 Jun 2009 05:46:15 -0000	1.1.1.1
+++ bgpctl/parser.c	9 Jul 2009 17:22:12 -0000	1.3
@@ -1,4 +1,4 @@
-/*	$OpenBSD: parser.c,v 1.50 2008/06/15 09:58:43 claudio Exp $ */
+/*	$OpenBSD: parser.c,v 1.54 2009/06/12 16:44:02 claudio Exp $ */
 
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
 
@@ -42,6 +46,7 @@ enum token_type {
 	ASTYPE,
 	PREFIX,
 	PEERDESC,
+	RIBNAME,
 	COMMUNITY,
 	LOCALPREF,
 	MED,
@@ -72,6 +77,7 @@ static const struct token t_show_summary
 static const struct token t_show_fib[];
 static const struct token t_show_rib[];
 static const struct token t_show_rib_neigh[];
+static const struct token t_show_rib_rib[];
 static const struct token t_show_neighbor[];
 static const struct token t_show_neighbor_modifiers[];
 static const struct token t_fib[];
@@ -148,6 +154,7 @@ static const struct token t_show_rib[] =
 	{ FLAG,		"in",		F_CTL_ADJ_IN,	t_show_rib},
 	{ FLAG,		"out",		F_CTL_ADJ_OUT,	t_show_rib},
 	{ KEYWORD,	"neighbor",	NONE,		t_show_rib_neigh},
+	{ KEYWORD,	"table",	NONE,		t_show_rib_rib},
 	{ KEYWORD,	"summary",	SHOW_SUMMARY,	t_show_summary},
 	{ KEYWORD,	"memory",	SHOW_RIB_MEM,	NULL},
 	{ FAMILY,	"",		NONE,		t_show_rib},
@@ -161,6 +168,11 @@ static const struct token t_show_rib_nei
 	{ ENDTOKEN,	"",		NONE,	NULL}
 };
 
+static const struct token t_show_rib_rib[] = {
+	{ RIBNAME,	"",		NONE,	t_show_rib},
+	{ ENDTOKEN,	"",		NONE,	NULL}
+};
+
 static const struct token t_show_neighbor[] = {
 	{ NOTOKEN,	"",		NONE,	NULL},
 	{ PEERADDRESS,	"",		NONE,	t_show_neighbor_modifiers},
@@ -456,6 +468,15 @@ match_token(int *argc, char **argv[], co
 				t = &table[i];
 			}
 			break;
+		case RIBNAME:
+			if (!match && word != NULL && strlen(word) > 0) {
+				if (strlcpy(res.rib, word, sizeof(res.rib)) >=
+				    sizeof(res.rib))
+					errx(1, "rib name too long");
+				match++;
+				t = &table[i];
+			}
+			break;
 		case COMMUNITY:
 			if (word != NULL && strlen(word) > 0 &&
 			    parse_community(word, &res)) {
@@ -547,6 +568,9 @@ show_valid_args(const struct token table
 		case PEERDESC:
 			fprintf(stderr, "  <neighbor description>\n");
 			break;
+		case RIBNAME:
+			fprintf(stderr, "  <rib name>\n");
+			break;
 		case COMMUNITY:
 			fprintf(stderr, "  <community>\n");
 			break;
@@ -686,7 +710,7 @@ parse_asnum(const char *word, u_int32_t 
 		if (errstr)
 			errx(1, "AS number is %s: %s", errstr, word);
 	} else {
-		uval = strtonum(word, 0, USHRT_MAX - 1, &errstr);
+		uval = strtonum(word, 0, ASNUM_MAX - 1, &errstr);
 		if (errstr)
 			errx(1, "AS number is %s: %s", errstr, word);
 	}
@@ -801,7 +825,7 @@ parse_community(const char *word, struct
 	type = getcommunity(p);
 
 done:
-	if (as == 0 || as == USHRT_MAX) {
+	if (as == 0) {
 		fprintf(stderr, "Invalid community\n");
 		return (0);
 	}
@@ -814,7 +838,7 @@ done:
 			break;
 		default:
 			/* unknown */
-			fprintf(stderr, "Invalid well-known community\n");
+			fprintf(stderr, "Unknown well-known community\n");
 			return (0);
 		}
 
@@ -856,33 +880,6 @@ parse_nexthop(const char *word, struct p
 	return (1);
 }
 
-/* XXX local copies from kroute.c, should go to a shared file */
-in_addr_t
-prefixlen2mask(u_int8_t prefixlen)
-{
-	if (prefixlen == 0)
-		return (0);
-
-	return (0xffffffff << (32 - prefixlen));
-}
-
-void
-inet6applymask(struct in6_addr *dest, const struct in6_addr *src, int prefixlen)
-{
-	struct in6_addr	mask;
-	int		i;
-
-	bzero(&mask, sizeof(mask));
-	for (i = 0; i < prefixlen / 8; i++)
-		mask.s6_addr[i] = 0xff;
-	i = prefixlen % 8;
-	if (i)
-		mask.s6_addr[prefixlen / 8] = 0xff00 >> i;
-
-	for (i = 0; i < 16; i++)
-		dest->s6_addr[i] = src->s6_addr[i] & mask.s6_addr[i];
-}
-
 int
 bgpctl_getopt(int *argc, char **argv[], int type)
 {
