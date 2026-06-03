--- ../nginx-upload-module-96e6460/ngx_http_upload_module.c.orig	2025-11-02 20:25:39.277074000 -0500
+++ ../nginx-upload-module-96e6460/ngx_http_upload_module.c	2025-11-02 20:31:22.912698000 -0500
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
@@ -3370,7 +3373,11 @@
             }
 
             if (u->limit_rate) {
+#if defined freenginx && nginx_version >= 1029000
+                limit = u->limit_rate * (ngx_time() - ((ngx_current_msec - r->start_time) / 1000) + 1) - u->received;
+#else
                 limit = u->limit_rate * (ngx_time() - r->start_sec + 1) - u->received;
+#endif
 
                 if (limit < 0) {
                     c->read->delayed = 1;
