--- ../lua-nginx-module-0.10.8/src/ngx_http_lua_ssl_ocsp.c.orig	2017-04-30 17:32:37.211186000 -0400
+++ ../lua-nginx-module-0.10.8/src/ngx_http_lua_ssl_ocsp.c	2017-04-30 17:33:42.926721000 -0400
@@ -490,7 +490,9 @@
 
     dd("set ocsp resp: resp_len=%d", (int) resp_len);
     (void) SSL_set_tlsext_status_ocsp_resp(ssl_conn, p, resp_len);
+#ifndef LIBRESSL_VERSION_NUMBER
     ssl_conn->tlsext_status_expected = 1;
+#endif

     return NGX_OK;
 
