--- net/ssl/ssl_config.h.orig	2014-10-02 17:19:00 UTC
+++ net/ssl/ssl_config.h
@@ -32,6 +32,9 @@
 // Default maximum protocol version.
 NET_EXPORT extern const uint16 kDefaultSSLVersionMax;
 
+// Default minimum protocol version that it's acceptable to fallback to.
+NET_EXPORT extern const uint16 kDefaultSSLVersionFallbackMin;
+
 // A collection of SSL-related configuration settings.
 struct NET_EXPORT SSLConfig {
   // Default to revocation checking.
@@ -73,6 +76,12 @@
   uint16 version_min;
   uint16 version_max;
 
+  // version_fallback_min contains the minimum version that is acceptable to
+  // fallback to. Versions before this may be tried to see whether they would
+  // have succeeded and thus to give a better message to the user, but the
+  // resulting connection won't be used in these cases.
+  uint16 version_fallback_min;
+
   // Presorted list of cipher suites which should be explicitly prevented from
   // being used in addition to those disabled by the net built-in policy.
   //
