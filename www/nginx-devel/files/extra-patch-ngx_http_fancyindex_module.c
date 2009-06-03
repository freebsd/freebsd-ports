--- ../nginx-fancyindex-0.1_beta5/ngx_http_fancyindex_module.c.orig	2007-09-29 01:02:05.000000000 +0400
+++ ../nginx-fancyindex-0.1_beta5/ngx_http_fancyindex_module.c	2009-06-03 16:41:36.000000000 +0400
@@ -290,12 +290,12 @@
     ngx_http_fancyindex_entry_t *entry;
 
     off_t        length;
-    size_t       len, root, copy, allocated;
+    size_t       len, root, utf_len, allocated;
     u_char      *filename, *last, scale;
     ngx_tm_t     tm;
     ngx_array_t  entries;
     ngx_time_t  *tp;
-    ngx_uint_t   i;
+    ngx_uint_t   i, utf8;
     ngx_int_t    size;
     ngx_str_t    path;
     ngx_str_t    readme_path;
@@ -355,6 +355,15 @@
     filename = path.data;
     filename[path.len] = '/';
 
+    if (r->headers_out.charset.len == 5
+        && ngx_strncasecmp(r->headers_out.charset.data, (u_char *) "utf-8", 5)
+           == 0)
+    {
+        utf8 = 1;
+    } else {
+        utf8 = 0;
+    }
+
     /* Read directory entries and their associated information. */
     for (;;) {
         ngx_set_errno(0);
@@ -425,8 +434,8 @@
         entry->dir     = ngx_de_is_dir(&dir);
         entry->mtime   = ngx_de_mtime(&dir);
         entry->size    = ngx_de_size(&dir);
-        entry->utf_len = (r->utf8)
-            ?  ngx_utf_length(entry->name.data, entry->name.len)
+        entry->utf_len = utf8
+            ?  ngx_utf8_length(entry->name.data, entry->name.len)
             : len;
     }
 
@@ -563,12 +572,13 @@
 
         if (entry[i].name.len - len) {
             if (len > NGX_HTTP_FANCYINDEX_NAME_LEN) {
-                copy = NGX_HTTP_FANCYINDEX_NAME_LEN - 3 + 1;
+                utf_len = NGX_HTTP_FANCYINDEX_NAME_LEN - 3 + 1;
             } else {
-                copy = NGX_HTTP_FANCYINDEX_NAME_LEN + 1;
+                utf_len = NGX_HTTP_FANCYINDEX_NAME_LEN + 1;
             }
 
-            b->last = ngx_utf_cpystrn(b->last, entry[i].name.data, copy);
+            b->last = ngx_utf8_cpystrn(b->last, entry[i].name.data,
+                                       utf_len, entry[i].name.len + 1);
             last = b->last;
 
         } else {
