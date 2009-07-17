--- ../nginx-notice-2/ngx_http_notice_module.c.orig	2009-07-16 18:37:57.000000000 +0200
+++ ../nginx-notice-2/ngx_http_notice_module.c	2009-07-16 08:09:38.000000000 +0200
@@ -153,7 +153,7 @@
         return NGX_HTTP_NOT_ALLOWED;
     }
 
-    rc = ngx_http_discard_body(r);
+    rc = ngx_http_discard_request_body(r);
 
     if (rc != NGX_OK && rc != NGX_AGAIN) {
         return rc;
