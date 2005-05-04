--- source/rain_tcp.c.orig	Fri Aug 17 07:36:07 2001
+++ source/rain_tcp.c	Wed Apr 20 01:19:04 2005
@@ -244,7 +244,7 @@
   }
 
 
-  pkt->tot_len = (sizeof(struct tcphdr) + strlen(buffer));
+  pkt->tot_len = (sizeof(struct tcphdr) + sizeof(char)*packetsize);
 
 
   /* 
