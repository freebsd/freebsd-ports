--- lib/src/gretl_matrix.c.orig	Wed Mar 14 09:25:57 2007
+++ lib/src/gretl_matrix.c	Sat Apr 14 03:50:51 2007
@@ -432,12 +432,13 @@
 {
     int reverse = (start > end);
     int i, k, n = 1 + (reverse ? (start-end) : (end-start));
+    gretl_matrix *v;
 
     if (n == 0) {
 	return NULL;
     }
 
-    gretl_matrix *v = gretl_vector_alloc(n);
+    v = gretl_vector_alloc(n);
   
     if (v == NULL) {
 	return v;
