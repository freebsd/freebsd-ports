--- ./include/http_core.h.orig	2006-07-12 07:40:55.000000000 +0000
+++ ./include/http_core.h	2010-10-21 05:40:55.842621572 +0000
@@ -493,7 +493,7 @@
     
     /* Access control */
     apr_array_header_t *sec_file;
-    regex_t *r;
+    ap_regex_t *r;
 
     const char *mime_type;       /* forced with ForceType  */
     const char *handler;         /* forced with SetHandler */
