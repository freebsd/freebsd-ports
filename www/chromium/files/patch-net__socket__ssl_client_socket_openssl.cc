--- net/socket/ssl_client_socket_openssl.cc.orig	2014-10-02 17:39:47 UTC
+++ net/socket/ssl_client_socket_openssl.cc
@@ -890,6 +890,11 @@
                << " is: " << (SSL_session_reused(ssl_) ? "Success" : "Fail");
     }
 
+    if (ssl_config_.version_fallback &&
+        ssl_config_.version_max < ssl_config_.version_fallback_min) {
+      return ERR_SSL_FALLBACK_BEYOND_MINIMUM_VERSION;
+    }
+
     // SSL handshake is completed. If NPN wasn't negotiated, see if ALPN was.
     if (npn_status_ == kNextProtoUnsupported) {
       const uint8_t* alpn_proto = NULL;
