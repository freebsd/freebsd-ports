--- source/rain_udp.c.orig	Fri Aug 17 07:36:26 2001
+++ source/rain_udp.c	Wed Apr 20 01:19:27 2005
@@ -105,7 +105,7 @@
      buffer[(sizeof(struct ip) + sizeof(struct udphdr)) + i] = pkt->payload[i];
   }
 
-  pkt->tot_len = (sizeof(struct udphdr) + strlen(buffer));
+  pkt->tot_len = (sizeof(struct udphdr) + sizeof(char)*packetsize);
 
 
   /*
