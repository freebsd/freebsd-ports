--- pim6sd/mld6.c	Tue Nov 19 03:13:59 2002
+++ pim6sd/mld6.c	Tue Nov 19 03:13:46 2002
@@ -117,7 +117,7 @@
 
 /* Externals */
 
-extern struct in6_addr in6addr_linklocal_allnodes;
+//extern struct in6_addr in6addr_linklocal_allnodes;
 
 /* local variables. */
 static struct sockaddr_in6 	dst = {sizeof(dst), AF_INET6};
