
$FreeBSD$

--- ehnt_processflow.c.orig	Thu Oct  4 22:18:29 2001
+++ ehnt_processflow.c	Thu Nov 14 22:17:18 2002
@@ -218,7 +218,7 @@
 	dstip.s_addr=rec->dstaddr;
 	nexthop.s_addr=rec->nexthop;
 
-	printf("%.0f:%s",local_flowcount,routeraddr_string);
+	printf("%.0f:%s:",local_flowcount,routeraddr_string);
 	printf("%d:%s:%d:",
 	       rec->input_index,
 	       inet_ntoa(srcip),
