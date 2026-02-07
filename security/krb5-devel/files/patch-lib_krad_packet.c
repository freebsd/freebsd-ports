--- lib/krad/packet.c.orig	2024-10-26 16:40:40.000000000 -0700
+++ lib/krad/packet.c	2024-10-29 08:05:22.833913000 -0700
@@ -472,6 +472,9 @@
 verify_msgauth(const char *secret, const krad_packet *pkt,
                const uint8_t auth[AUTH_FIELD_SIZE])
 {
+#ifndef ENODATA
+#define ENODATA ENOATTR
+#endif
     uint8_t mac[MD5_DIGEST_SIZE];
     const krb5_data *msgauth;
     krb5_error_code retval;
