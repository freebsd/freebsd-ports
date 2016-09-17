--- src/connobject.c.orig	2006-12-03 04:36:37 UTC
+++ src/connobject.c
@@ -139,7 +139,7 @@ static PyObject * _conn_read(conn_rec *c
     bytes_read = 0;
 
     while ((bytes_read < len || len == 0) &&
-           !(b == APR_BRIGADE_SENTINEL(b) ||
+           !(b == APR_BRIGADE_SENTINEL(bb) ||
              APR_BUCKET_IS_EOS(b) || APR_BUCKET_IS_FLUSH(b))) {
 
         const char *data;
