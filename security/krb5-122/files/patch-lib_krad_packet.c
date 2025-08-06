--- lib/krad/packet.c.orig	2025-08-05 07:15:15.000000000 -0700
+++ lib/krad/packet.c	2025-08-06 00:16:54.383533000 -0700
@@ -477,6 +477,9 @@
     krb5_error_code retval;
 
     msgauth = krad_packet_get_attr(pkt, KRAD_ATTR_MESSAGE_AUTHENTICATOR, 0);
+/* XXX ENODATA does not exist in FreeBSD. The closest thing we have to */
+/* XXX ENODATA is ENOATTR. We use that instead. */
+#define ENODATA ENOATTR
     if (msgauth == NULL)
         return ENODATA;
 
