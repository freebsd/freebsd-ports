--- ../nginx-fancyindex-0.1_beta5/ngx_http_fancyindex_module.c.orig	2007-09-29 01:02:05.000000000 +0400
+++ ../nginx-fancyindex-0.1_beta5/ngx_http_fancyindex_module.c	2008-08-11 17:33:42.810249087 +0400
@@ -290,7 +290,7 @@
     ngx_http_fancyindex_entry_t *entry;
 
     off_t        length;
-    size_t       len, root, copy, allocated;
+    size_t       len, root, utf_len, allocated;
     u_char      *filename, *last, scale;
     ngx_tm_t     tm;
     ngx_array_t  entries;
@@ -426,7 +426,7 @@
         entry->mtime   = ngx_de_mtime(&dir);
         entry->size    = ngx_de_size(&dir);
         entry->utf_len = (r->utf8)
-            ?  ngx_utf_length(entry->name.data, entry->name.len)
+            ?  ngx_utf8_length(entry->name.data, entry->name.len)
             : len;
     }
 
@@ -563,12 +563,13 @@
 
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
