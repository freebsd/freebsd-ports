--- networking/httpd.c.orig	2018-12-05 14:44:34 UTC
+++ networking/httpd.c
@@ -2109,10 +2109,10 @@ static void handle_incoming_and_exit(con
 	}
 #if ENABLE_FEATURE_IPV6
 	if (fromAddr->u.sa.sa_family == AF_INET6
-	 && fromAddr->u.sin6.sin6_addr.s6_addr32[0] == 0
-	 && fromAddr->u.sin6.sin6_addr.s6_addr32[1] == 0
-	 && ntohl(fromAddr->u.sin6.sin6_addr.s6_addr32[2]) == 0xffff)
-		rmt_ip = ntohl(fromAddr->u.sin6.sin6_addr.s6_addr32[3]);
+	 && fromAddr->u.sin6.sin6_addr.s6_addr[0] == 0
+	 && fromAddr->u.sin6.sin6_addr.s6_addr[1] == 0
+	 && ntohl(fromAddr->u.sin6.sin6_addr.s6_addr[2]) == 0xffff)
+		rmt_ip = ntohl(fromAddr->u.sin6.sin6_addr.s6_addr[3]);
 #endif
 	if (ENABLE_FEATURE_HTTPD_CGI || DEBUG || verbose) {
 		/* NB: can be NULL (user runs httpd -i by hand?) */
