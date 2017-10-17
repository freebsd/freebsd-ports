--- src/sys/net/if_spppsubr.c.orig	2016-08-02 11:51:10 UTC
+++ src/sys/net/if_spppsubr.c
@@ -3185,7 +3185,7 @@ sppp_ipcp_scr(struct sppp *sp)
 
 #ifdef notyet
 	if (sp->ipcp.opts & (1 << IPCP_OPT_COMPRESSION)) {
-		opt[i++] = IPCP_OPT_COMPRESSION;
+		opt[i++] = (char)IPCP_OPT_COMPRESSION;
 		opt[i++] = 6;
 		opt[i++] = 0;	/* VJ header compression */
 		opt[i++] = 0x2d; /* VJ header compression */
@@ -3210,7 +3210,7 @@ sppp_ipcp_scr(struct sppp *sp)
 #endif
 
 	if (sp->query_dns & 1) {
-		opt[i++] = IPCP_OPT_PRIMDNS;
+		opt[i++] = (char)IPCP_OPT_PRIMDNS;
 		opt[i++] = 6;
 		opt[i++] = sp->dns_addrs[0] >> 24;
 		opt[i++] = sp->dns_addrs[0] >> 16;
@@ -3218,7 +3218,7 @@ sppp_ipcp_scr(struct sppp *sp)
 		opt[i++] = sp->dns_addrs[0];
 	}
 	if (sp->query_dns & 2) {
-		opt[i++] = IPCP_OPT_SECDNS;
+		opt[i++] = (char)IPCP_OPT_SECDNS;
 		opt[i++] = 6;
 		opt[i++] = sp->dns_addrs[1] >> 24;
 		opt[i++] = sp->dns_addrs[1] >> 16;
