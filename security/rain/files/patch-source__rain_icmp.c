--- source/rain_icmp.c.orig	Fri Aug 17 07:36:45 2001
+++ source/rain_icmp.c	Wed Apr 20 01:18:32 2005
@@ -256,7 +256,7 @@
   }
 
 
-  pkt->tot_len = (sizeof(struct icmp) + strlen(buffer));
+  pkt->tot_len = (sizeof(struct icmp) + sizeof(char)*packetsize);
 
 
   /*
