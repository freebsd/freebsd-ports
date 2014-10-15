--- net/socket/ssl_client_socket_nss.cc.orig	2014-10-02 17:39:47 UTC
+++ net/socket/ssl_client_socket_nss.cc
@@ -3330,6 +3330,11 @@
   EnterFunction(result);
 
   if (result == OK) {
+    if (ssl_config_.version_fallback &&
+        ssl_config_.version_max < ssl_config_.version_fallback_min) {
+      return ERR_SSL_FALLBACK_BEYOND_MINIMUM_VERSION;
+    }
+
     // SSL handshake is completed. Let's verify the certificate.
     GotoState(STATE_VERIFY_CERT);
     // Done!
