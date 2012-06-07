--- ../ngx_http_subs_filter_module-0.5.2.r53/ngx_http_subs_filter_module.c.orig	2012-06-06 16:13:15.000000000 +0400
+++ ../ngx_http_subs_filter_module-0.5.2.r53/ngx_http_subs_filter_module.c	2012-06-06 16:16:06.000000000 +0400
@@ -1300,7 +1300,9 @@
 
     n = 0;
 
-#if defined(nginx_version) && nginx_version >= 1001012
+#if defined(nginx_version) && (nginx_version >= 1003001)
+    rc = pcre_fullinfo(re->code, NULL, PCRE_INFO_CAPTURECOUNT, &n);
+#elif (nginx_version >= 1001012) && (nginx_version < 1003001)
     rc = pcre_fullinfo(re->pcre, NULL, PCRE_INFO_CAPTURECOUNT, &n);
 #else
     rc = pcre_fullinfo(re, NULL, PCRE_INFO_CAPTURECOUNT, &n);
