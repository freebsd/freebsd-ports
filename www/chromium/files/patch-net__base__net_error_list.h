--- net/base/net_error_list.h.orig	2014-10-02 17:18:59 UTC
+++ net/base/net_error_list.h
@@ -336,6 +336,10 @@
 // library.
 NET_ERROR(SSL_CLIENT_AUTH_CERT_BAD_FORMAT, -164)
 
+// The SSL server requires falling back to a version older than the configured
+// minimum fallback version, and thus fallback failed.
+NET_ERROR(SSL_FALLBACK_BEYOND_MINIMUM_VERSION, -165)
+
 // Certificate error codes
 //
 // The values of certificate error codes must be consecutive.
