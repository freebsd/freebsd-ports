--- src/dns/dns.c.orig	2022-06-15 16:24:13 UTC
+++ src/dns/dns.c
@@ -5012,7 +5012,7 @@ static int guess_scope_id(void){
 	struct ifaddrs *ifp;
 	struct ifaddrs *ifpstart;
 	int scope_id = -1;
-	
+
 	if (getifaddrs(&ifpstart) < 0) {
 		return -1;
 	}
@@ -5035,7 +5035,7 @@ static int guess_scope_id(void){
 		}
 	}
 	freeifaddrs(ifpstart);
-	
+
 	return scope_id;
 }
 
@@ -5044,7 +5044,7 @@ int dns_resconf_loadfromresolv(struct dns_resolv_conf 
 	union res_sockaddr_union addresses[3];
 	int i,error,write_index;
 
-
+    memset(&res, 0, sizeof(res));
 	if ((error = res_ninit(&res))) {
 		return error;
 	}
