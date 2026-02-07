--- tools/p0f-sendsyn.c.orig	2012-01-14 18:01:02.000000000 +0000
+++ tools/p0f-sendsyn.c	2014-12-11 14:16:03.000000000 +0000
@@ -122,7 +122,7 @@
 int main(int argc, char** argv) {
 
   static struct sockaddr_in sin;
-  char one = 1;
+  int one = 1;
   s32  sock;
   u32  i;
 
@@ -145,7 +145,7 @@
 
   if (sock < 0) PFATAL("Can't open raw socket (you need to be root).");
 
-  if (setsockopt(sock, IPPROTO_IP, IP_HDRINCL, (char*)&one, sizeof(char)))
+  if (setsockopt(sock, IPPROTO_IP, IP_HDRINCL, &one, sizeof(one)))
     PFATAL("setsockopt() on raw socket failed.");
 
   sin.sin_family = PF_INET;
@@ -153,7 +153,7 @@
   memcpy(&sin.sin_addr.s_addr, ip4->dst, 4);
 
   ip4->ver_hlen  = 0x45;
-  ip4->tot_len   = htons(MIN_TCP4 + 24);
+  ip4->tot_len   = MIN_TCP4 + 24; /* converted to network order in kernel */
   ip4->ttl       = 192;
   ip4->proto     = PROTO_TCP;
 
