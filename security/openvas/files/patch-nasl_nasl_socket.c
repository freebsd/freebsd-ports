--- nasl/nasl_socket.c	2020-12-31 17:33:40.663863000 -0500
+++ nasl/nasl_socket.c	2020-12-31 17:36:11.693013000 -0500
@@ -51,6 +51,8 @@
 #include <stdlib.h>              /* for atoi() */
 #include <string.h>              /* for bzero */
 #include <sys/time.h>
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <unistd.h> /* for close */
 
 #ifndef EADDRNOTAVAIL
@@ -311,7 +313,7 @@
   if (IN6_IS_ADDR_V4MAPPED (p))
     {
       bzero (&daddr, sizeof (daddr));
-      daddr.sin_addr.s_addr = p->s6_addr32[3];
+      daddr.sin_addr.s_addr = p->s6_addr[12];
       daddr.sin_family = AF_INET;
       daddr.sin_port = htons (dport);
       unblock_socket (sock);
@@ -546,7 +548,7 @@
   if (IN6_IS_ADDR_V4MAPPED (ia))
     {
       bzero (&soca, sizeof (soca));
-      soca.sin_addr.s_addr = ia->s6_addr32[3];
+      soca.sin_addr.s_addr = ia->s6_addr[12];
       soca.sin_port = htons (port);
       soca.sin_family = AF_INET;
 
