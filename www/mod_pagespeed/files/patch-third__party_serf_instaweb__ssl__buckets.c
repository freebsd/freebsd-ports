--- third_party/serf/instaweb_ssl_buckets.c.orig	2017-06-08 22:22:39 UTC
+++ third_party/serf/instaweb_ssl_buckets.c
@@ -1697,11 +1697,15 @@ int serf_ssl_cert_depth(const serf_ssl_c
 int serf_ssl_check_host(const serf_ssl_certificate_t *cert,
                         const char* hostname)
 {
+#if TSI_OPENSSL_ALPN_SUPPORT == 0
+  return (-1);
+#else
   return X509_check_host(cert->ssl_cert,
                          hostname,
                          strlen(hostname),
                          0 /* we don't need to set any flags */,
                          NULL /* we don't need the SAN or CN extracted*/);
+#endif
 }
 
 apr_hash_t *serf_ssl_cert_issuer(
