--- print-ppp.c.orig	Wed Mar 24 03:32:43 2004
+++ print-ppp.c	Sun Jan 23 00:26:26 2005
@@ -89,6 +89,7 @@
 	{ PPP_IPXCP,	  "IPXCP" },
 	{ PPP_STIICP,	  "STIICP" },
 	{ PPP_VINESCP,	  "VINESCP" },
+        { PPP_IPV6CP,     "IP6CP" },
 	{ PPP_MPLSCP,	  "MPLSCP" },
 
 	{ PPP_LCP,	  "LCP" },
@@ -211,7 +212,6 @@
 	"PPP-Muxing",		/* (30) */
 };
 
-/* IPV6CP - to be supported */
 /* ECP - to be supported */
 
 /* CCP Config Options */
@@ -275,17 +275,36 @@
 /* SDCP - to be supported */
 
 /* IPCP Config Options */
-
 #define IPCPOPT_2ADDR	1	/* RFC1172, RFC1332 (deprecated) */
 #define IPCPOPT_IPCOMP	2	/* RFC1332 */
 #define IPCPOPT_ADDR	3	/* RFC1332 */
 #define IPCPOPT_MOBILE4	4	/* RFC2290 */
-
 #define IPCPOPT_PRIDNS	129	/* RFC1877 */
 #define IPCPOPT_PRINBNS	130	/* RFC1877 */
 #define IPCPOPT_SECDNS	131	/* RFC1877 */
 #define IPCPOPT_SECNBNS	132	/* RFC1877 */
 
+struct tok ipcpopt_values[] = {
+        { IPCPOPT_2ADDR, "IP-Addrs" },
+        { IPCPOPT_IPCOMP, "IP-Comp" },
+        { IPCPOPT_ADDR, "IP-Addr" },
+        { IPCPOPT_MOBILE4, "Home-Addr" },
+        { IPCPOPT_PRIDNS, "Pri-DNS" },
+        { IPCPOPT_PRINBNS, "Pri-NBNS" },
+        { IPCPOPT_SECDNS, "Sec-DNS" },
+        { IPCPOPT_SECNBNS, "Sec-NBNS" },
+	{ 0,		  NULL }
+};
+
+
+/* IP6CP Config Options */
+#define IP6CP_IFID      1
+
+struct tok ip6cpopt_values[] = {
+        { IP6CP_IFID, "Interface-ID" },
+	{ 0,		  NULL }
+};
+
 /* ATCP - to be supported */
 /* OSINLCP - to be supported */
 /* BVCP - to be supported */
@@ -366,6 +385,7 @@
 static void handle_bap (const u_char *p, int length);
 static int print_lcp_config_options (const u_char *p, int);
 static int print_ipcp_config_options (const u_char *p, int);
+static int print_ip6cp_config_options (const u_char *p, int);
 static int print_ccp_config_options (const u_char *p, int);
 static int print_bacp_config_options (const u_char *p, int);
 static void handle_ppp (u_int proto, const u_char *p, int length);
@@ -382,7 +402,7 @@
 
         tptr=pptr;
 
-        typestr = tok2str(ppptype2str, "unknown", proto);
+        typestr = tok2str(ppptype2str, "unknown ctrl-proto (0x%04x)", proto);
         printf("%s, ",typestr);
 
 	if (length < 4) /* FIXME weak boundary checking */
@@ -401,7 +421,7 @@
 	tptr += 2;
 
 	if (length <= 4)
-		return;		/* there may be a NULL confreq etc. */
+		goto print_len_and_return;    /* there may be a NULL confreq etc. */
 
 	switch (code) {
 	case CPCODES_VEXT:
@@ -427,6 +447,9 @@
 			case PPP_IPCP:
 				pfunc = print_ipcp_config_options;
 				break;
+			case PPP_IPV6CP:
+				pfunc = print_ip6cp_config_options;
+				break;
 			case PPP_CCP:
 				pfunc = print_ccp_config_options;
 				break;
@@ -492,6 +515,8 @@
                     print_unknown_data(pptr-2,"\n\t",length+2);
 		break;
 	}
+
+ print_len_and_return:
 	printf(", length %u", length);
 
         if (vflag >1)
@@ -902,61 +927,41 @@
 	opt = p[0];
 	if (length < len)
 		return 0;
+
+	printf(", %s (0x%02x) ",
+	       tok2str(ipcpopt_values,"unknown",opt),
+	       opt);
+
 	switch (opt) {
 	case IPCPOPT_2ADDR:		/* deprecated */
 		if (len != 10)
 			goto invlen;
 		TCHECK2(*(p + 6), 4);
-		printf(", IP-Addrs src %s, dst %s",
+		printf("src %s, dst %s",
 		       ipaddr_string(p + 2),
 		       ipaddr_string(p + 6));
 		break;
 	case IPCPOPT_IPCOMP:
 		if (len < 4)
 			goto invlen;
-		printf(", IP-Comp");
 		TCHECK2(*(p + 2), 2);
 		if (EXTRACT_16BITS(p + 2) == PPP_VJC) {
-			printf(" VJ-Comp");
+			printf("VJ-Comp");
 			/* XXX: VJ-Comp parameters should be decoded */
 		} else
-			printf(" unknown-comp-proto=%04x", EXTRACT_16BITS(p + 2));
-		break;
-	case IPCPOPT_ADDR:
-		if (len != 6)
-			goto invlen;
-		TCHECK2(*(p + 2), 4);
-		printf(", IP-Addr %s", ipaddr_string(p + 2));
+			printf("unknown-comp-proto %04x", EXTRACT_16BITS(p + 2));
 		break;
+
+	case IPCPOPT_ADDR:     /* those options share the same format - fall through */
 	case IPCPOPT_MOBILE4:
-		if (len != 6)
-			goto invlen;
-		TCHECK2(*(p + 2), 4);
-		printf(", Home-Addr %s", ipaddr_string(p + 2));
-		break;
 	case IPCPOPT_PRIDNS:
-		if (len != 6)
-			goto invlen;
-		TCHECK2(*(p + 2), 4);
-		printf(", Pri-DNS %s", ipaddr_string(p + 2));
-		break;
 	case IPCPOPT_PRINBNS:
-		if (len != 6)
-			goto invlen;
-		TCHECK2(*(p + 2), 4);
-		printf(", Pri-NBNS %s", ipaddr_string(p + 2));
-		break;
 	case IPCPOPT_SECDNS:
-		if (len != 6)
-			goto invlen;
-		TCHECK2(*(p + 2), 4);
-		printf(", Sec-DNS %s", ipaddr_string(p + 2));
-		break;
 	case IPCPOPT_SECNBNS:
 		if (len != 6)
 			goto invlen;
 		TCHECK2(*(p + 2), 4);
-		printf(", Sec-NBNS %s", ipaddr_string(p + 2));
+		printf("%s", ipaddr_string(p + 2));
 		break;
 	default:
 		printf(", unknown-%d", opt);
@@ -972,6 +977,51 @@
 	printf("[|ipcp]");
 	return 0;
 }
+
+/* IP6CP config options */
+static int
+print_ip6cp_config_options(const u_char *p, int length)
+{
+	int len, opt;
+
+	if (length < 2)
+		return 0;
+	TCHECK2(*p, 2);
+	len = p[1];
+	opt = p[0];
+	if (length < len)
+		return 0;
+
+	printf(", %s (0x%02x) ",
+	       tok2str(ip6cpopt_values,"unknown",opt),
+	       opt);
+
+	switch (opt) {
+	case IP6CP_IFID:
+		if (len != 10)
+			goto invlen;
+		TCHECK2(*(p + 2), 8);
+		printf("%04x:%04x:%04x:%04x",
+		       EXTRACT_16BITS(p + 2),
+		       EXTRACT_16BITS(p + 4),
+		       EXTRACT_16BITS(p + 6),
+		       EXTRACT_16BITS(p + 8));
+		break;
+	default:
+		printf(", unknown-%d", opt);
+		break;
+	}
+	return len;
+
+invlen:
+	printf(", invalid-length-%d", opt);
+	return 0;
+
+trunc:
+	printf("[|ip6cp]");
+	return 0;
+}
+
 
 /* CCP config options */
 static int
