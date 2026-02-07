--- ./record.c.orig	2001-03-15 09:33:04.000000000 +0100
+++ ./record.c	2014-07-22 13:20:14.000000000 +0200
@@ -65,8 +65,8 @@
 	tm = localtime(&rec->time);
 	strftime(tstr, sizeof(tstr), "%x %X", tm);
 	
-	srcp = libnet_host_lookup(rec->src, Opt_dns);
-	dstp = libnet_host_lookup(rec->dst, Opt_dns);
+	srcp = libnet_addr2name4(rec->src, Opt_dns);
+	dstp = libnet_addr2name4(rec->dst, Opt_dns);
 
 	if ((pr = getprotobynumber(rec->proto)) == NULL)
 		protop = "unknown";
