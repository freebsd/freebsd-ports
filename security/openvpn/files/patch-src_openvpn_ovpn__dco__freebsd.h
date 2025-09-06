--- src/openvpn/ovpn_dco_freebsd.h.orig	2025-04-02 06:53:10 UTC
+++ src/openvpn/ovpn_dco_freebsd.h
@@ -37,6 +37,7 @@ enum ovpn_notif_type {
 enum ovpn_notif_type {
     OVPN_NOTIF_DEL_PEER,
     OVPN_NOTIF_ROTATE_KEY,
+    OVPN_NOTIF_FLOAT,
 };
 
 enum ovpn_del_reason {
