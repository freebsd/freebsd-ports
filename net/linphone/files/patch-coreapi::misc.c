
$FreeBSD$

--- coreapi/misc.c	2003/06/13 12:59:10	1.1
+++ coreapi/misc.c	2003/06/13 12:59:39
@@ -249,8 +249,7 @@
 	hints.ai_family = PF_UNSPEC;
 	hints.ai_flags = AI_NUMERICHOST;
 	getaddrinfo(lc->net_conf.sel_if->ipaddr, NULL, &hints, &res);
-	if ( (strcmp(lc->net_conf.sel_if->ipaddr,"127.0.0.1")!=0)
-	   && !IN6_IS_ADDR_LINKLOCAL(res->ai_addr) && !IN6_IS_ADDR_LOOPBACK(res->ai_addr))
+	if ( (strcmp(lc->net_conf.sel_if->ipaddr,"127.0.0.1")!=0))
 #else
 	if (strcmp(lc->net_conf.sel_if->ip4addr,"127.0.0.1")!=0)
 #endif
