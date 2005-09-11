--- src/libspf2/spf_dns_rr.c.orig	Thu Jul 28 18:40:13 2005
+++ src/libspf2/spf_dns_rr.c	Thu Jul 28 18:40:29 2005
@@ -45,7 +45,7 @@
 				const char *domain)
 {
 	return SPF_dns_rr_new_init(spf_dns_server,
-					domain, ns_t_any, 0, NXDOMAIN);
+					domain, ns_t_any, 0, HOST_NOT_FOUND);
 }
 
 SPF_dns_rr_t *
