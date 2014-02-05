--- ./src/checksum.c.orig	2014-02-03 14:04:23.999531000 +0000
+++ ./src/checksum.c	2014-02-03 14:15:33.000000000 +0000
@@ -120,7 +120,7 @@
   By Jorge Cwik <jorge@laser.satlink.net>, adapted for linux by Arnt
   Gulbrandsen.
 */
-inline u_short ip_fast_csum(u_char * iph, u_int ihl)
+u_short ip_fast_csum(u_char * iph, u_int ihl)
 {
   u_int sum;
   if (dontchksum(((struct ip*)iph)->ip_src.s_addr))
@@ -191,13 +191,13 @@
   this routine is used for miscellaneous IP-like checksums, mainly in
   icmp.c
 */
-inline u_short
+u_short
 ip_compute_csum(u_char * buff, int len)
 {
   return (csum_fold(csum_partial(buff, len, 0)));
 }
 
-inline u_short
+u_short
 my_tcp_check(struct tcphdr *th, int len, u_int saddr, u_int daddr)
 {
   if (dontchksum(saddr))
@@ -205,7 +205,7 @@
   return csum_tcpudp_magic(saddr, daddr, len, IPPROTO_TCP,
 			   csum_partial((u_char *)th, len, 0));
 }
-inline u_short
+u_short
 my_udp_check(void *u, int len, u_int saddr, u_int daddr)
 {
   if (dontchksum(saddr))
