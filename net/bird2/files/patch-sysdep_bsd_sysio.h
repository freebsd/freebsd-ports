diff --git sysdep/bsd/sysio.h sysdep/bsd/sysio.h
index f1887fb4..5167a5dd 100644
--- sysdep/bsd/sysio.h
+++ sysdep/bsd/sysio.h
@@ -48,11 +48,16 @@
 static inline int
 sk_setup_multicast4(sock *s)
 {
-  struct in_addr ifa = ip4_to_in4(s->iface->sysdep);
   u8 ttl = s->ttl;
   u8 n = 0;
 
   /* This defines where should we send _outgoing_ multicasts */
+#ifdef __FreeBSD__
+  struct ip_mreqn ifa = { .imr_ifindex = s->iface->index };
+#else
+  struct in_addr ifa = ip4_to_in4(s->iface->sysdep);
+#endif
+
   if (setsockopt(s->fd, IPPROTO_IP, IP_MULTICAST_IF, &ifa, sizeof(ifa)) < 0)
     ERR("IP_MULTICAST_IF");
 
@@ -68,8 +73,11 @@ sk_setup_multicast4(sock *s)
 static inline int
 sk_join_group4(sock *s, ip_addr maddr)
 {
+#ifdef __FreeBSD__
+  struct ip_mreqn mr = { .imr_multiaddr = ipa_to_in4(maddr), .imr_ifindex = s->iface->index };
+#else
   struct ip_mreq mr = INIT_MREQ4(maddr, s->iface);
-
+#endif
   if (setsockopt(s->fd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mr, sizeof(mr)) < 0)
     ERR("IP_ADD_MEMBERSHIP");
 
@@ -79,8 +87,11 @@ sk_join_group4(sock *s, ip_addr maddr)
 static inline int
 sk_leave_group4(sock *s, ip_addr maddr)
 {
+#ifdef __FreeBSD__
+  struct ip_mreqn mr = { .imr_multiaddr = ipa_to_in4(maddr), .imr_ifindex = s->iface->index };
+#else
   struct ip_mreq mr = INIT_MREQ4(maddr, s->iface);
-
+#endif
   if (setsockopt(s->fd, IPPROTO_IP, IP_DROP_MEMBERSHIP, &mr, sizeof(mr)) < 0)
     ERR("IP_ADD_MEMBERSHIP");
 
