--- ../ngx_http_subs_filter_module-0.5.2.r59/ngx_http_subs_filter_module.c.orig	2012-07-03 20:55:52.000000000 +0400
+++ ../ngx_http_subs_filter_module-0.5.2.r59/ngx_http_subs_filter_module.c	2012-07-03 20:56:52.000000000 +0400
@@ -1302,7 +1302,7 @@
 
     n = 0;
 
-#if defined(nginx_version) && nginx_version >= 1003001
+#if defined(nginx_version) && nginx_version >= 1002002
     rc = pcre_fullinfo(re->code, NULL, PCRE_INFO_CAPTURECOUNT, &n);
 #elif defined(nginx_version) && nginx_version >= 1001012
     rc = pcre_fullinfo(re->pcre, NULL, PCRE_INFO_CAPTURECOUNT, &n);
