--- ../ngx_echo_module-0.30/src/ngx_http_echo_timer.c.orig	2010-06-07 16:32:51.000000000 +0400
+++ ../ngx_echo_module-0.30/src/ngx_http_echo_timer.c	2010-06-07 16:34:32.000000000 +0400
@@ -25,7 +25,7 @@
 
     /* force the ngx timer to update */
 
-#if defined nginx_version && nginx_version >= 8035
+#if defined nginx_version && (nginx_version >= 8035 || nginx_version >= 7066)
     ngx_time_update();
 #else
     ngx_time_update(0, 0);
@@ -62,7 +62,7 @@
 
     /* force the ngx timer to update */
 
-#if defined nginx_version && nginx_version >= 8035
+#if defined nginx_version && (nginx_version >= 8035 || nginx_version >= 7066)
     ngx_time_update();
 #else
     ngx_time_update(0, 0);
