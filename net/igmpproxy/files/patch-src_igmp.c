--- src/igmp.c.orig	2022-10-29 10:01:46 UTC
+++ src/igmp.c
@@ -288,7 +288,7 @@ static void buildIgmp(uint32_t src, uint32_t dst, int 
     igmp->igmp_group.s_addr = group;
     igmp->igmp_cksum        = 0;
     igmp->igmp_cksum        = inetChksum((unsigned short *)igmp,
-                                         IP_HEADER_RAOPT_LEN + datalen);
+                                         sizeof(igmp) + datalen);
 
 }
 
