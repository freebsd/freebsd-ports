--- dns.h.orig	2004-11-25 18:13:49.000000000 -0600
+++ dns.h	2015-01-21 14:06:33.000000000 -0600
@@ -47,6 +47,8 @@
 
 	#define mkip(a,b,c,d) ((((a)&0xff)<<24)|(((b)&0xff)<<16)|(((c)&0xff)<<8)|((d)&0xff))
 
+	int dns_query_rr_aaaa(const res_state statp, char *fmt, ...);
+
 	int dns_query_rr_a(const res_state statp, char *fmt, ...);
 	int dns_rdnsbl_has_rr_a(const res_state statp, long ip, char *domain);
 
