--- ./source3/utils/net_lookup.c.orig	2013-11-18 23:13:25.859884543 +0000
+++ ./source3/utils/net_lookup.c	2013-11-18 23:21:48.283312520 +0000
@@ -321,7 +321,7 @@
 
 		print_sockaddr(addr, sizeof(addr), &kdcs[i].ss);
 
-		d_printf("%s:%hd\n", addr, kdcs[i].port);
+		d_printf("%s:%u\n", addr, kdcs[i].port);
 	}
 
 	return 0;
