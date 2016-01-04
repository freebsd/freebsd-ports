--- addrconf.c.orig	2008-06-15 07:48:40 UTC
+++ addrconf.c
@@ -173,7 +173,7 @@ update_address(ia, addr, dhcpifp, ctlp, 
 	    sacreate ? "create" : "update",
 	    in6addr2str(&addr->addr, 0), addr->pltime, addr->vltime);
 
-	if (sa->addr.vltime != 0)
+	if (sa->addr.vltime != 0 || sacreate)
 		if (na_ifaddrconf(IFADDRCONF_ADD, sa) < 0)
 			return (-1);
 
