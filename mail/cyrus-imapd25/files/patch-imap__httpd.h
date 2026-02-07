Index: imap/httpd.h
diff -u imap/httpd.h.orig imap/httpd.h
--- imap/httpd.h.orig	2014-07-23 05:25:28.000000000 +0900
+++ imap/httpd.h	2014-07-29 00:31:32.053782690 +0900
@@ -224,7 +224,7 @@
 
 /* Meta-data for response body (payload & representation headers) */
 struct resp_body_t {
-    ulong len; 		/* Content-Length   */
+    unsigned long len;	/* Content-Length   */
     struct range *range;/* Content-Range    */
     const char *fname;	/* Content-Dispo    */
     unsigned char enc;	/* Content-Encoding */
