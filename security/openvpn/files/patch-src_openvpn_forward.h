--- src/openvpn/forward.h.orig	2025-04-02 06:53:10 UTC
+++ src/openvpn/forward.h
@@ -189,6 +189,21 @@ void process_incoming_link_part2(struct context *c, st
 void process_incoming_link_part2(struct context *c, struct link_socket_info *lsi, const uint8_t *orig_buf);
 
 /**
+ * Transfers \c float_sa data extracted from an incoming DCO
+ * PEER_FLOAT_NTF to \c out_osaddr for later processing.
+ *
+ * @param socket_family - The address family of the socket
+ * @param out_osaddr - openvpn_sockaddr struct that will be filled the new
+ *      address data
+ * @param float_sa - The sockaddr struct containing the data received from the
+ *      DCO notification
+ */
+void
+extract_dco_float_peer_addr(sa_family_t socket_family,
+                            struct openvpn_sockaddr *out_osaddr,
+                            const struct sockaddr *float_sa);
+
+/**
  * Write a packet to the external network interface.
  * @ingroup external_multiplexer
  *
