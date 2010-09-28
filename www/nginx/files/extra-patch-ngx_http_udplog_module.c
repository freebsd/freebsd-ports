--- ../nginx_udplog_module-1.0.0/ngx_http_udplog_module.c.orig	2010-01-11 19:16:46.000000000 +0300
+++ ../nginx_udplog_module-1.0.0/ngx_http_udplog_module.c	2010-01-11 19:20:17.000000000 +0300
@@ -280,7 +280,7 @@
     uc->sockaddr = endpoint->peer_addr.sockaddr;
     uc->socklen = endpoint->peer_addr.socklen;
     uc->server = endpoint->peer_addr.name;
-#if defined nginx_version && nginx_version >= 7054
+#if defined nginx_version && ( nginx_version >= 7054 && nginx_version < 8032 )
     uc->log = &cf->cycle->new_log;
 #else
     uc->log = cf->cycle->new_log;
@@ -335,7 +335,11 @@
     }
 
     if ((size_t) n != (size_t) len) {
+#if defined nginx_version && nginx_version >= 8032
+        ngx_log_error(NGX_LOG_CRIT, &uc->log, 0, "send() incomplete");
+#else
         ngx_log_error(NGX_LOG_CRIT, uc->log, 0, "send() incomplete");
+#endif
         return NGX_ERROR;
     }
 
