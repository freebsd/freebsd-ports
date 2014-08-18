--- src/dns.c.orig	2014-08-16 15:34:00.457977967 +0600
+++ src/dns.c	2014-08-16 15:34:32.647973864 +0600
@@ -4306,6 +4306,7 @@
 	union res_sockaddr_union addresses[3];
 	int i,error;
 
+	bzero(&res, sizeof(res));
 	if ((error = res_ninit(&res))) {
 		return error;
 	}
