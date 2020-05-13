--- lib/transport/transport-udp-socket.c.orig	2020-04-29 16:02:15 UTC
+++ lib/transport/transport-udp-socket.c
@@ -47,10 +47,12 @@ _extract_dest_ip4_addr_from_cmsg(struct cmsghdr *cmsg,
 {
   if (cmsg->cmsg_level == IPPROTO_IP && cmsg->cmsg_type == IP_RECVDSTADDR)
     {
-      gint cmsg_header_len = (gchar *) CMSG_DATA(cmsg) - (gchar *) cmsg;
-      struct sockaddr *sa = (struct sockaddr *) CMSG_DATA(cmsg);
+      struct sockaddr_in sin = *(struct sockaddr_in *) &bind_addr->sa;
 
-      return g_sockaddr_new(sa, cmsg->cmsg_len - cmsg_header_len);
+      struct in_addr *sin_addr = (struct in_addr *) CMSG_DATA(cmsg);
+      sin.sin_addr = *sin_addr;
+
+      return g_sockaddr_new((struct sockaddr *) &sin, sizeof(sin));
     }
   return NULL;
 }
