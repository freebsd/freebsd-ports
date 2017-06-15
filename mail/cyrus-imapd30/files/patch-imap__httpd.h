--- imap/httpd.h.orig	2016-04-11 02:02:11 UTC
+++ imap/httpd.h
@@ -264,7 +264,7 @@ struct patch_doc_t {
 
 /* Meta-data for response body (payload & representation headers) */
 struct resp_body_t {
-    ulong len;                          /* Content-Length   */
+    unsigned long len;                  /* Content-Length   */
     struct range *range;                /* Content-Range    */
     const char *fname;                  /* Content-Dispo    */
     unsigned char enc;                  /* Content-Encoding */
