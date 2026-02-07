Index: imap/http_client.h
diff -u imap/http_client.h.orig imap/http_client.h
--- imap/http_client.h.orig	2014-07-23 05:25:28.000000000 +0900
+++ imap/http_client.h	2014-07-29 00:33:01.254781310 +0900
@@ -57,7 +57,7 @@
     unsigned char framing;		/* Message framing   */
     unsigned char te;			/* Transfer-Encoding */
     unsigned max;			/* Max allowed len   */
-    ulong len; 				/* Content-Length    */
+    unsigned long len;			/* Content-Length    */
     struct buf payload;			/* Payload	     */
 };
 
