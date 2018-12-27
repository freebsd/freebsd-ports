From 6af39d63aa9323b4b8c39efe24ae0c88c949a901 Mon Sep 17 00:00:00 2001
From: Miroslav Lichvar <mlichvar@redhat.com>
Date: Mon, 3 Dec 2018 15:51:54 +0100
Subject: ntp: don't use IP_SENDSRCADDR on bound socket

On FreeBSD, sendmsg() fails when IP_SENDSRCADDR specifies a source
address on a socket that is bound to the address. This prevents a server
configured with the bindaddress directive from responding to clients.

Add a new variable to check whether the server IPv4 socket is not bound
before setting the source address.
--- ntp_io.c.orig	2018-09-19 14:38:15 UTC
+++ ntp_io.c
@@ -105,6 +105,9 @@ static int separate_client_sockets;
    disabled */
 static int permanent_server_sockets;
 
+/* Flag indicating the server IPv4 socket is bound to an address */
+static int bound_server_sock_fd4;
+
 /* Flag indicating that we have been initialised */
 static int initialised=0;
 
@@ -168,6 +171,9 @@ prepare_socket(int family, int port_number, int client
       my_addr.in4.sin_port = htons(port_number);
       my_addr_len = sizeof (my_addr.in4);
 
+      if (!client_only)
+        bound_server_sock_fd4 = my_addr.in4.sin_addr.s_addr != htonl(INADDR_ANY);
+
       break;
 #ifdef FEAT_IPV6
     case AF_INET6:
@@ -821,8 +827,8 @@ NIO_SendPacket(NTP_Packet *packet, NTP_Remote_Address 
   msg.msg_flags = 0;
   cmsglen = 0;
 
-  if (local_addr->ip_addr.family == IPADDR_INET4) {
 #ifdef HAVE_IN_PKTINFO
+  if (local_addr->ip_addr.family == IPADDR_INET4) {
     struct in_pktinfo *ipi;
 
     cmsg = CMSG_FIRSTHDR(&msg);
@@ -837,7 +843,11 @@ NIO_SendPacket(NTP_Packet *packet, NTP_Remote_Address 
     ipi->ipi_spec_dst.s_addr = htonl(local_addr->ip_addr.addr.in4);
     if (local_addr->if_index != INVALID_IF_INDEX)
       ipi->ipi_ifindex = local_addr->if_index;
+  }
 #elif defined(IP_SENDSRCADDR)
+  /* Specify the IPv4 source address only if the socket is not bound */
+  if (local_addr->ip_addr.family == IPADDR_INET4 &&
+      local_addr->sock_fd == server_sock_fd4 && !bound_server_sock_fd4) {
     struct in_addr *addr;
 
     cmsg = CMSG_FIRSTHDR(&msg);
@@ -850,8 +860,8 @@ NIO_SendPacket(NTP_Packet *packet, NTP_Remote_Address 
 
     addr = (struct in_addr *)CMSG_DATA(cmsg);
     addr->s_addr = htonl(local_addr->ip_addr.addr.in4);
-#endif
   }
+#endif
 
 #ifdef HAVE_IN6_PKTINFO
   if (local_addr->ip_addr.family == IPADDR_INET6) {
