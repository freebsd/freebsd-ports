--- lib/gnutls_handshake.c.orig	2012-11-03 06:03:47.000000000 -0700
+++ lib/gnutls_handshake.c	2014-06-04 07:55:49.138570114 -0700
@@ -1797,7 +1797,7 @@
   DECR_LEN (len, 1);
   session_id_len = data[pos++];
 
-  if (len < session_id_len)
+  if (len < session_id_len || session_id_len > TLS_MAX_SESSION_ID_SIZE)
     {
       gnutls_assert ();
       return GNUTLS_E_UNSUPPORTED_VERSION_PACKET;
