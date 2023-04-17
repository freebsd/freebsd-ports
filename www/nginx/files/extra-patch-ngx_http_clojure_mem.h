--- ../nginx-clojure-4347955/src/c/ngx_http_clojure_mem.h.orig	2022-07-11 13:38:32.426478000 -0400
+++ ../nginx-clojure-4347955/src/c/ngx_http_clojure_mem.h	2022-07-11 13:38:45.346434000 -0400
@@ -421,7 +421,7 @@
 #define NGX_HTTP_CLOJURE_HEADERSI_PASSWD_IDX  90
 #define NGX_HTTP_CLOJURE_HEADERSI_PASSWD_OFFSET offsetof(ngx_http_headers_in_t, passwd)
 #define NGX_HTTP_CLOJURE_HEADERSI_COOKIE_IDX  91
-#define NGX_HTTP_CLOJURE_HEADERSI_COOKIE_OFFSET offsetof(ngx_http_headers_in_t, cookies)
+#define NGX_HTTP_CLOJURE_HEADERSI_COOKIE_OFFSET offsetof(ngx_http_headers_in_t, cookie)
 #define NGX_HTTP_CLOJURE_HEADERSI_SERVER_IDX  92
 #define NGX_HTTP_CLOJURE_HEADERSI_SERVER_OFFSET offsetof(ngx_http_headers_in_t, server)
 #define NGX_HTTP_CLOJURE_HEADERSI_CONTENT_LENGTH_N_IDX  93
