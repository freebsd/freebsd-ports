--- net.c.orig	2016-08-01 13:07:58 UTC
+++ net.c
@@ -320,9 +320,11 @@ void net_send_tcp(int index)
   struct sockaddr_storage local;
   struct sockaddr_storage remote;
   struct sockaddr_in *local4 = (struct sockaddr_in *) &local;
-  struct sockaddr_in6 *local6 = (struct sockaddr_in6 *) &local;
   struct sockaddr_in *remote4 = (struct sockaddr_in *) &remote;
+#ifdef ENABLE_IPV6
+  struct sockaddr_in6 *local6 = (struct sockaddr_in6 *) &local;
   struct sockaddr_in6 *remote6 = (struct sockaddr_in6 *) &remote;
+#endif
   socklen_t len;
 
   ttl = index + 1;
@@ -437,9 +439,11 @@ void net_send_sctp(int index)
   struct sockaddr_storage local;
   struct sockaddr_storage remote;
   struct sockaddr_in *local4 = (struct sockaddr_in *) &local;
-  struct sockaddr_in6 *local6 = (struct sockaddr_in6 *) &local;
   struct sockaddr_in *remote4 = (struct sockaddr_in *) &remote;
+#ifdef ENABLE_IPV6
+  struct sockaddr_in6 *local6 = (struct sockaddr_in6 *) &local;
   struct sockaddr_in6 *remote6 = (struct sockaddr_in6 *) &remote;
+#endif
   socklen_t len;
 
   ttl = index + 1;
@@ -726,8 +730,12 @@ void net_send_query(int index) 
 
   /* sendto() assumes packet length includes the IPv4 header but not the 
      IPv6 header. */
-  spacketsize = abs(packetsize)	-
-		( ( af == AF_INET ) ? 0 : sizeof (struct ip6_hdr) );
+  spacketsize = abs(packetsize)
+#ifdef ENABLE_IPV6
+                - ( ( af == AF_INET ) ? 0 : sizeof (struct ip6_hdr) )
+#endif
+                ;
+
   rv = sendto(sendsock, packet, spacketsize, 0, remotesockaddr, salen);
   if (first && (rv < 0) && ((errno == EINVAL) || (errno == EMSGSIZE))) {
     /* Try the first packet again using host byte order. */
@@ -1529,17 +1537,17 @@ void net_reset(void) 
 
 int net_set_interfaceaddress_udp()
 {
+  struct sockaddr_in *  sa4;
+  struct sockaddr_storage remote;
+  struct sockaddr_in *remote4 = (struct sockaddr_in *) &remote;
 #ifdef ENABLE_IPV6
   struct sockaddr_storage name_struct;
+  struct sockaddr_in6 * sa6;
+  struct sockaddr_in6 *remote6 = (struct sockaddr_in6 *) &remote;
 #else
   struct sockaddr_in name_struct;
 #endif
-  struct sockaddr_in *  sa4;
-  struct sockaddr_in6 * sa6;
   struct sockaddr * name = (struct sockaddr *) &name_struct;
-  struct sockaddr_storage remote;
-  struct sockaddr_in *remote4 = (struct sockaddr_in *) &remote;
-  struct sockaddr_in6 *remote6 = (struct sockaddr_in6 *) &remote;
   socklen_t len;
   int s;
 
