--- ../nginx-upload-module-2.3.0/ngx_http_upload_module.c.orig
+++ ../nginx-upload-module-2.3.0/ngx_http_upload_module.c
@@ -989,7 +989,11 @@
         if (u->limit_rate) {
             remaining = ((ssize_t) r->headers_in.content_length_n) - u->received;
             next_buf_size = (buf_read_size > remaining) ? remaining : buf_read_size;
+#if defined freenginx && nginx_version >= 1029000
+            limit = u->limit_rate * (ngx_time() - ((ngx_current_msec - r->start_time) / 1000) + 1) - (u->received + next_buf_size);
+#else
             limit = u->limit_rate * (ngx_time() - r->start_sec + 1) - (u->received + next_buf_size);
+#endif
             if (limit < 0) {
                 rev->delayed = 1;
                 ngx_add_timer(rev, (ngx_msec_t) ((limit * -1000 / u->limit_rate) + 1));
@@ -1580,7 +1584,7 @@
                 /*
                  * If at least one filter succeeds, we pass the field
                  */
-                if(rc == 0)
+                if(rc >= 0)
                     pass_field = 1;
 #else
                 if(ngx_strncmp(f[i].text.data, u->field_name.data, u->field_name.len) == 0)
@@ -3518,7 +3522,11 @@
             }
 
             if (u->limit_rate) {
+#if defined freenginx && nginx_version >= 1029000
+                limit = u->limit_rate * (ngx_time() - ((ngx_current_msec - r->start_time) / 1000) + 1) - u->received;
+#else
                 limit = u->limit_rate * (ngx_time() - r->start_sec + 1) - u->received;
+#endif
 
                 if (limit < 0) {
                     c->read->delayed = 1;
