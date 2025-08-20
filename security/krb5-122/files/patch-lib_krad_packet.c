--- lib/krad/packet.c.orig	2025-08-05 14:15:15 UTC
+++ lib/krad/packet.c
@@ -477,6 +477,9 @@ verify_msgauth(const char *secret, const krad_packet *
     krb5_error_code retval;
 
     msgauth = krad_packet_get_attr(pkt, KRAD_ATTR_MESSAGE_AUTHENTICATOR, 0);
+/* XXX ENODATA does not exist in FreeBSD. The closest thing we have to */
+/* XXX ENODATA is ENOATTR. We use that instead. */
+#define ENODATA ENOATTR
     if (msgauth == NULL)
         return ENODATA;
 
