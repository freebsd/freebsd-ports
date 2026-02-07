--- traceroute.c.orig	2016-09-02 21:07:07 UTC
+++ traceroute.c
@@ -798,7 +803,7 @@ struct opacket {
               struct icmp icmp_probe;
         } ip_payload;
 #endif /* V6.3.0 */
-};
+} __attribute__((packed));
 
 #ifdef SPRAY
 /*
