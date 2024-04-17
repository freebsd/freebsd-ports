--- src/sslutils.c.orig	2024-02-04 19:32:52 UTC
+++ src/sslutils.c
@@ -946,11 +946,7 @@ static OCSP_RESPONSE *get_ocsp_response(apr_pool_t *p,
     int ok = 0;
     apr_socket_t *apr_sock = NULL;
     apr_pool_t *mp;
-#ifdef LIBRESSL_VERSION_NUMBER
     if (OCSP_parse_url(url, &hostname, &c_port, &path, &use_ssl) == 0)
-#else
-    if (OSSL_HTTP_parse_url(url, &use_ssl, NULL, &hostname, &c_port, NULL, &path, NULL, NULL) == 0)
-#endif
         goto end;
 
     if (sscanf(c_port, "%d", &port) != 1)
