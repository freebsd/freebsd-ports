--- lib/fdbuf/tlsobuf.cc.orig
+++ lib/fdbuf/tlsobuf.cc
@@ -27,5 +27,10 @@
 
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
