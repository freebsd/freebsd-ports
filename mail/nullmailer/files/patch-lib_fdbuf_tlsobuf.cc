--- lib/fdbuf/tlsobuf.cc.orig	2018-10-12 20:49:30 UTC
+++ lib/fdbuf/tlsobuf.cc
@@ -27,5 +27,10 @@ tlsobuf::tlsobuf(gnutls_session_t s, unsigned bufsz)
 
 ssize_t tlsobuf::_write(const char* buf, ssize_t len)
 {
-  return gnutls_record_send(session, buf, len);
+  ssize_t rc;
+  do
+  {
+    rc = gnutls_record_send(session, buf, len);
+  } while(rc == GNUTLS_E_AGAIN || rc == GNUTLS_E_INTERRUPTED);
+  return rc;
 }
