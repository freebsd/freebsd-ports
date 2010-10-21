--- ./modules/filters/mod_include.h.orig	2006-07-12 07:40:55.000000000 +0000
+++ ./modules/filters/mod_include.h	2010-10-21 05:40:55.843621981 +0000
@@ -140,7 +140,7 @@
     int          start_seq_len;
     char         *end_seq;
     char         *re_string;
-    regmatch_t   (*re_result)[10];
+    ap_regmatch_t   (*re_result)[10];
 } include_ctx_t;
 
 /* These flags are used to set flag bits. */
