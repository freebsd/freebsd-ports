--- source/rain_igmp.c.orig	Fri Aug 17 07:37:15 2001
+++ source/rain_igmp.c	Wed Apr 20 01:18:45 2005
@@ -114,7 +114,7 @@
   }
 
 
-  pkt->tot_len = (sizeof(struct igmp) + strlen(buffer));
+  pkt->tot_len = (sizeof(struct igmp) + sizeof(char)*packetsize);
 
 
   /* 
