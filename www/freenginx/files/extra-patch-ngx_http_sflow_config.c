--- ../nginx-sflow-module-543c72a/ngx_http_sflow_config.c.orig	2012-06-07 04:52:57.000000000 +0400
+++ ../nginx-sflow-module-543c72a/ngx_http_sflow_config.c	2012-06-07 04:59:18.000000000 +0400
@@ -26,7 +26,6 @@
         ngx_log_error(NGX_LOG_ERR, log, 0, "getaddrinfo() failed: %s", gai_strerror(err));
         switch(err) {
         case EAI_NONAME: break;
-        case EAI_NODATA: break;
         case EAI_AGAIN: break; // loop and try again?
         default: ngx_log_error(NGX_LOG_ERR, log, 0, "getaddrinfo() error: %s", gai_strerror(err)); break;
         }
