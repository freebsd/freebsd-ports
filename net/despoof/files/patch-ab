--- despoof.c.orig	Sat Sep  2 18:34:37 2000
+++ despoof.c	Sat Sep  2 18:34:45 2000
@@ -150,7 +150,7 @@
 
   if (targetaddr == ip->ip_src.s_addr) 
   {
-    if (((inquery == 1) && (icmp->icmp_type == ICMP_ECHOREPLY)) || ((inquery == 2) && (icmp->icmp_type == ICMP_TIMESTAMPREPLY)) || ((inquery == 3) && (sport == ntohs(tcphdr->th_dport))))
+    if (((inquery == 1) && (icmp->icmp_type == ICMP_ECHOREPLY)) || ((inquery == 2) && (icmp->icmp_type == ICMP_TSTAMPREPLY)) || ((inquery == 3) && (sport == ntohs(tcphdr->th_dport))))
     {
       if (ttlval == ip->ip_ttl)
       {
