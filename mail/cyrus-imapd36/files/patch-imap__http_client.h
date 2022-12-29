--- imap/http_client.h.orig	2016-04-11 02:02:11 UTC
+++ imap/http_client.h
@@ -57,7 +57,7 @@ struct body_t {
     unsigned char framing;              /* Message framing   */
     unsigned char te;                   /* Transfer-Encoding */
     unsigned max;                       /* Max allowed len   */
-    ulong len;                          /* Content-Length    */
+    unsigned long len;                  /* Content-Length    */
     struct buf payload;                 /* Payload           */
 };
 
