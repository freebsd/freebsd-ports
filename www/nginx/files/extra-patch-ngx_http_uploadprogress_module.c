--- ../nginx_uploadprogress_module/ngx_http_uploadprogress_module.c.orig	2009-06-26 15:32:01.000000000 +0400
+++ ../nginx_uploadprogress_module/ngx_http_uploadprogress_module.c	2009-06-26 15:38:30.000000000 +0400
@@ -187,8 +187,9 @@
         if (i) {
             start_p = p += 14;
             while (p < r->args.data + r->args.len) {
-                if (*p++ != '&') {
-                    continue;
+                if (*p++ == '&') {
+                    p--;
+                    break;
                 }
             }
 
