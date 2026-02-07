--- libopendmarc/opendmarc_dns.c.orig	2021-12-20 06:40:37 UTC
+++ libopendmarc/opendmarc_dns.c
@@ -203,6 +203,7 @@ dmarc_dns_get_record(char *domain, int *reply, char *g
 		++bp;
 
 #ifdef HAVE_RES_NINIT   
+	memset(&resp, '\0', sizeof resp);
 	res_ninit(&resp);
 #ifdef RES_USE_DNSSEC
 	resp.options |= RES_USE_DNSSEC;
