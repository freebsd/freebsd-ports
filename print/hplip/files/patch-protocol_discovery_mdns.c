Use a dynamically allocated port instead of binding port 5353.  The bind(2)
call fails when Avahi has already claimed port 5353.  On top of that, HPLIP
only performs one-shot queries and those shouldn't be using port 5353 according
to RFC 6762.

Don't disable loop-back.  It's harmless.

Use default TTL of 1.  RFC 6762 requires 255 for responses, not for queries.

There's no need to join the multicast group for one-shot queries.  Responses
are sent to the unicast address.

--- protocol/discovery/mdns.c.orig	2020-07-01 14:48:56 UTC
+++ protocol/discovery/mdns.c
@@ -24,7 +24,11 @@
  Author: Sanjay Kumar
  \*****************************************************************************/
 
-//#include <stdio.h>
+#include <ctype.h>
+#include <stdio.h>
+#include <stdlib.h>
+#include <unistd.h>
+#include <sys/select.h>
 #include <string.h>
 #include <syslog.h>
 #include <sys/socket.h>
@@ -70,57 +74,13 @@ static int mdns_convert_name_to_dns(const char *name, 
 static int mdns_open_socket(int *psocket)
 {
     int stat = MDNS_STATUS_ERROR;
-    int udp_socket = -1, yes = 1;
-    char loop = 0, ttl = 255;
-    struct sockaddr_in recv_addr , addr;
-    struct ip_mreq mreq;
+    int udp_socket;
 
     DBG("mdns_open_socket entry.\n");
 
     if ((udp_socket = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
     {
         BUG("unable to create udp socket: %m\n");
-        goto bugout;
-    }
-
-    /* Get rid of "address already in use" error message. */
-    if (setsockopt(udp_socket, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) == -1)
-    {
-        BUG("unable to setsockopt: %m\n");
-        goto bugout;
-    }
-
-    /* Bind the socket to port and IP equal to INADDR_ANY. */
-    bzero(&recv_addr, sizeof(recv_addr));
-    recv_addr.sin_family = AF_INET;
-    recv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
-    recv_addr.sin_port = htons(5353);
-    if (bind(udp_socket, (struct sockaddr *) &recv_addr, sizeof(recv_addr)) == -1)
-    {
-        BUG("unable to bind udp socket: %m\n");
-        goto bugout;
-    }
-
-    /* Set multicast loopback off. */
-    if (setsockopt(udp_socket, IPPROTO_IP, IP_MULTICAST_LOOP, &loop, sizeof(loop)) == -1)
-    {
-        BUG("unable to setsockopt: %m\n");
-        goto bugout;
-    }
-
-    /* Set ttl to 255. Required by mdns. */
-    if (setsockopt(udp_socket, IPPROTO_IP, IP_MULTICAST_TTL, &ttl, sizeof(ttl))== -1)
-    {
-        BUG("unable to setsockopt: %m\n");
-        goto bugout;
-    }
-
-    /* Join the .local multicast group */
-    mreq.imr_multiaddr.s_addr = inet_addr("224.0.0.251");
-    mreq.imr_interface.s_addr = htonl(INADDR_ANY);
-    if (setsockopt(udp_socket, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(struct ip_mreq)) == -1) {
-        BUG("unable to add to multicast group: %m\n");
-        close(udp_socket);
         goto bugout;
     }
 
