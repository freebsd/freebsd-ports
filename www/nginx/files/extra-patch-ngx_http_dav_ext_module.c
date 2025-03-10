--- ../nginx-dav-ext-module-3.0.0/ngx_http_dav_ext_module.c    2018-12-17 11:45:12.000000000 +0300
+++ ../nginx-dav-ext-module-3.0.0/ngx_http_dav_ext_module.c    2020-03-13 01:20:47.498199000 +0300
@@ -862,7 +862,7 @@
         name.len = ngx_de_namelen(&dir);
         name.data = ngx_de_name(&dir);
 
-        if (name.data[0] == '.') {
+        if ((name.len == 1 && name.data[0] == '.') || (name.len == 2 && name.data[0] == '.' && name.data[1] == '.')) {
             continue;
         }
 
@@ -896,10 +896,9 @@
             ngx_cpystrn(last, name.data, name.len + 1);
 
             if (ngx_de_info(filename, &dir) == NGX_FILE_ERROR) {
-                ngx_log_error(NGX_LOG_CRIT, r->connection->log, ngx_errno,
+                ngx_log_error(NGX_LOG_ERR, r->connection->log, ngx_errno,
                               ngx_de_info_n " \"%s\" failed", filename);
-                rc = NGX_HTTP_INTERNAL_SERVER_ERROR;
-                break;
+                continue;
             }
         }
 
