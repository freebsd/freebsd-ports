--- src/connobject.c.orig	2008-08-28 12:30:24.000000000 +0000
+++ src/connobject.c	2008-08-28 12:30:35.000000000 +0000
@@ -139,7 +139,7 @@
     bytes_read = 0;
 
     while ((bytes_read < len || len == 0) &&
-           !(b == APR_BRIGADE_SENTINEL(b) ||
+           !(b == APR_BRIGADE_SENTINEL(bb) ||
              APR_BUCKET_IS_EOS(b) || APR_BUCKET_IS_FLUSH(b))) {
 
         const char *data;
