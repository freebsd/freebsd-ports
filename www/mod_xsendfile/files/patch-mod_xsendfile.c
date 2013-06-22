--- mod_xsendfile.c.orig	2013-05-16 02:15:41.000000000 +0800
+++ mod_xsendfile.c	2013-05-16 02:15:48.000000000 +0800
@@ -439,7 +439,7 @@
     conf->ignoreLM == XSENDFILE_ENABLED
     || (
       !apr_table_get(r->headers_out, "last-modified")
-      && !apr_table_get(r->headers_out, "last-modified")
+      && !apr_table_get(r->err_headers_out, "last-modified")
     )
   ) {
     apr_table_unset(r->err_headers_out, "last-modified");
