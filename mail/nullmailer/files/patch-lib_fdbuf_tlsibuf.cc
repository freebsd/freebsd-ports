--- lib/fdbuf/tlsibuf.cc.orig
+++ lib/fdbuf/tlsibuf.cc
@@ -27,5 +27,10 @@
 
 ssize_t tlsibuf::_read(char* buf, ssize_t len)
 {
-  return gnutls_record_recv(session, buf, len);
+  ssize_t rc;
+  do
+  {
+    rc = gnutls_record_recv(session, buf, len);
+  } while (rc == GNUTLS_E_AGAIN || rc == GNUTLS_E_INTERRUPTED);
+  return rc;
 }
