Obtained from:	https://sources.debian.org/patches/libspf2/1.2.10-8.2/abolish-spf-rrtype.patch/

--- src/libspf2/spf_server.c.orig	2023-10-04 16:34:06 UTC
+++ src/libspf2/spf_server.c
@@ -346,7 +346,7 @@ SPF_server_get_record(SPF_server_t *spf_server,
 						spf_response, spf_recordp);
 
 	/* I am VERY, VERY sorry about the gotos. Shevek. */
-	rr_type = ns_t_spf;
+	rr_type = ns_t_txt;
 retry:
 	rr_txt = SPF_dns_lookup(resolver, domain, rr_type, TRUE);
 
