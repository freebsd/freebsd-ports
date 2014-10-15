--- net/ssl/ssl_config.cc.orig	2014-10-02 17:39:47 UTC
+++ net/ssl/ssl_config.cc
@@ -25,6 +25,8 @@
     SSL_PROTOCOL_VERSION_TLS1_2;
 #endif
 
+const uint16 kDefaultSSLVersionFallbackMin = SSL_PROTOCOL_VERSION_TLS1;
+
 SSLConfig::CertAndStatus::CertAndStatus() : cert_status(0) {}
 
 SSLConfig::CertAndStatus::~CertAndStatus() {}
@@ -34,6 +36,7 @@
       rev_checking_required_local_anchors(false),
       version_min(kDefaultSSLVersionMin),
       version_max(kDefaultSSLVersionMax),
+      version_fallback_min(kDefaultSSLVersionFallbackMin),
       channel_id_enabled(true),
       false_start_enabled(true),
       signed_cert_timestamps_enabled(true),
