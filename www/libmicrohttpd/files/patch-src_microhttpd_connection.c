--- src/microhttpd/connection.c.orig	2026-04-13 09:38:40 UTC
+++ src/microhttpd/connection.c
@@ -4902,10 +4902,9 @@ parse_connection_headers (struct MHD_Connection *conne
 
     for (pos = connection->rq.headers_received; NULL != pos; pos = pos->next)
       if ( (0 != (pos->kind & MHD_HEADER_KIND)) &&
-           (MHD_str_equal_caseless_bin_n_ (MHD_HTTP_HEADER_CONTENT_LENGTH,
-                                           pos->header,
-                                           MHD_STATICSTR_LEN_ (
-                                             MHD_HTTP_HEADER_CONTENT_LENGTH))) )
+           (MHD_str_equal_caseless_s_bin_n_ (MHD_HTTP_HEADER_CONTENT_LENGTH,
+                                             pos->header,
+                                             pos->header_size)) )
       {
         const char *clen;
         size_t val_len;
