--- src/core/ngx_regex.c	2011-12-06 19:49:40.000000000 +0400
+++ src/core/ngx_regex.c	2009-11-17 13:24:45.000000000 +0300
@@ -137,6 +137,23 @@
 
 
 ngx_int_t
+ngx_regex_capture_count(ngx_regex_t *re)
+{
+    int  rc, n;
+
+    n = 0;
+
+    rc = pcre_fullinfo(re, NULL, PCRE_INFO_CAPTURECOUNT, &n);
+
+    if (rc < 0) {
+        return (ngx_int_t) rc;
+    }
+
+    return (ngx_int_t) n;
+}
+
+
+ngx_int_t
 ngx_regex_exec_array(ngx_array_t *a, ngx_str_t *s, ngx_log_t *log)
 {
     ngx_int_t         n;
