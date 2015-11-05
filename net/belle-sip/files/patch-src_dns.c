--- src/dns.c.orig	2015-10-19 11:43:47 UTC
+++ src/dns.c
@@ -4345,6 +4345,7 @@ int dns_resconf_loadfromresolv(struct dn
 	union res_sockaddr_union addresses[3];
 	int i,error;
 
+	memset(&res, 0, sizeof(res));
 	if ((error = res_ninit(&res))) {
 		return error;
 	}
