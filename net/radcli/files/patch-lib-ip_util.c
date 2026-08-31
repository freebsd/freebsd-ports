--- lib/ip_util.c.orig	2026-08-19 19:14:39 UTC
+++ lib/ip_util.c
@@ -39,7 +39,7 @@ struct addrinfo *rc_getaddrinfo (char const *host, uns
 	if (flags & PW_AI_AUTH)
 		service = "radius";
 	else if (flags & PW_AI_ACCT)
-		service = "radius-acct";
+		service = "radacct";
  
 	err = getaddrinfo(host, service, &hints, &res);
 	if (err != 0) {
