
$FreeBSD$

--- ehnt_processflow.c.orig	Thu Oct  4 22:18:29 2001
+++ ehnt_processflow.c	Fri May 21 11:22:02 2004
@@ -218,7 +218,7 @@
 	dstip.s_addr=rec->dstaddr;
 	nexthop.s_addr=rec->nexthop;
 
-	printf("%.0f:%s",local_flowcount,routeraddr_string);
+	printf("%.0f:%s:",local_flowcount,routeraddr_string);
 	printf("%d:%s:%d:",
 	       rec->input_index,
 	       inet_ntoa(srcip),
@@ -228,7 +228,7 @@
 	       inet_ntoa(dstip),
 	       rec->dstport);
 	
-	printf("%d:%d:%d:",rec->dOctets,rec->dPkts,rec->prot);
+	printf("%u:%d:%d:",rec->dOctets,rec->dPkts,rec->prot);
 	printf("%d:%d\n",rec->src_as,rec->dst_as);
 
 	if (e_flt->big) {
