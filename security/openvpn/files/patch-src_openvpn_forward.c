--- src/openvpn/forward.c.orig	2025-04-02 06:53:10 UTC
+++ src/openvpn/forward.c
@@ -1234,6 +1234,41 @@ process_incoming_link(struct context *c)
     perf_pop();
 }
 
+void
+extract_dco_float_peer_addr(const sa_family_t socket_family,
+                            struct openvpn_sockaddr *out_osaddr,
+                            const struct sockaddr *float_sa)
+{
+    if (float_sa->sa_family == AF_INET)
+    {
+        struct sockaddr_in *float4 = (struct sockaddr_in *)float_sa;
+        /* DCO treats IPv4-mapped IPv6 addresses as pure IPv4. However, on a
+         * dual-stack socket, we need to preserve the mapping otherwise openvpn
+         * will not be able to find the peer by its transport address.
+         */
+        if (socket_family == AF_INET6)
+        {
+            out_osaddr->addr.in6.sin6_family = AF_INET6;
+            out_osaddr->addr.in6.sin6_port = float4->sin_port;
+
+            memset(&out_osaddr->addr.in6.sin6_addr.s6_addr, 0, 10);
+            out_osaddr->addr.in6.sin6_addr.s6_addr[10] = 0xff;
+            out_osaddr->addr.in6.sin6_addr.s6_addr[11] = 0xff;
+            memcpy(&out_osaddr->addr.in6.sin6_addr.s6_addr[12],
+                   &float4->sin_addr.s_addr, sizeof(in_addr_t));
+        }
+        else
+        {
+            memcpy(&out_osaddr->addr.in4, float4, sizeof(struct sockaddr_in));
+        }
+    }
+    else
+    {
+        struct sockaddr_in6 *float6 = (struct sockaddr_in6 *)float_sa;
+        memcpy(&out_osaddr->addr.in6, float6, sizeof(struct sockaddr_in6));
+    }
+}
+
 static void
 process_incoming_dco(struct context *c)
 {
