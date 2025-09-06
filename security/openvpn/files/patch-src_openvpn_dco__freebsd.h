--- src/openvpn/dco_freebsd.h.orig	2025-04-02 06:53:10 UTC
+++ src/openvpn/dco_freebsd.h
@@ -36,6 +36,7 @@ enum ovpn_message_type_t {
     OVPN_CMD_DEL_PEER,
     OVPN_CMD_PACKET,
     OVPN_CMD_SWAP_KEYS,
+    OVPN_CMD_FLOAT_PEER,
 };
 
 enum ovpn_del_reason_t {
@@ -55,6 +56,7 @@ typedef struct dco_context {
     int dco_message_type;
     int dco_message_peer_id;
     int dco_del_peer_reason;
+    struct sockaddr_storage dco_float_peer_ss;
     uint64_t dco_read_bytes;
     uint64_t dco_write_bytes;
 } dco_context_t;
