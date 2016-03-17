--- nasl/nasl_socket.c.orig	2015-12-08 07:07:22 UTC
+++ nasl/nasl_socket.c
@@ -266,7 +266,7 @@ tryagain:
   if (IN6_IS_ADDR_V4MAPPED (p))
     {
       bzero (&daddr, sizeof (daddr));
-      daddr.sin_addr.s_addr = p->s6_addr32[3];
+      memcpy(&daddr.sin_addr.s_addr, &p->s6_addr[12], 4);
       daddr.sin_family = AF_INET;
       daddr.sin_port = htons (dport);
       unblock_socket (sock);
@@ -504,7 +504,7 @@ nasl_open_sock_udp (lex_ctxt * lexic)
   if (IN6_IS_ADDR_V4MAPPED (ia))
     {
       bzero (&soca, sizeof (soca));
-      soca.sin_addr.s_addr = ia->s6_addr32[3];
+      memcpy(&soca.sin_addr.s_addr, &ia->s6_addr[12], 4);
       soca.sin_port = htons (port);
       soca.sin_family = AF_INET;
 
