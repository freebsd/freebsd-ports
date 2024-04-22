--- ../nginx_mod_h264_streaming-2.2.7/src/ngx_http_streaming_module.c.orig	2010-05-24 18:04:43.000000000 +0400
+++ ../nginx_mod_h264_streaming-2.2.7/src/ngx_http_streaming_module.c	2010-05-24 18:05:02.000000000 +0400
@@ -155,10 +155,6 @@
   }
 
   /* TODO: Win32 */
-  if (r->zero_in_uri)
-  {
-    return NGX_DECLINED;
-  }
 
   rc = ngx_http_discard_request_body(r);
 
