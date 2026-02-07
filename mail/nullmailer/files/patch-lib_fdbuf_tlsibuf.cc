--- lib/fdbuf/tlsibuf.cc.orig	2018-10-12 20:49:30 UTC
+++ lib/fdbuf/tlsibuf.cc
@@ -27,7 +27,12 @@ tlsibuf::tlsibuf(gnutls_session_t s, unsigned bufsz)
 
 ssize_t tlsibuf::_read(char* buf, ssize_t len)
 {
-  int rc;
+  ssize_t rc;
+  do
+  {
+    rc = gnutls_record_recv(session, buf, len);
+  } while (rc == GNUTLS_E_AGAIN || rc == GNUTLS_E_INTERRUPTED);
+  return rc;
   do
   {
     rc = gnutls_record_recv(session, buf, len);
