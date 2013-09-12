--- mod_wsgi.c.orig	2012-08-22 23:10:44.000000000 -0400
+++ mod_wsgi.c		2013-09-12 06:29:36.718830524 -0400
@@ -10600,7 +10600,13 @@
      * will add their own input/output filters to the chain.
      */
 
+#if AP_MODULE_MAGIC_AT_LEAST(20110619,0)
+    /* For 2.4 a NULL sbh pointer should work. */
+    sbh = NULL;
+#else
+    /* For 2.2 a dummy sbh pointer is needed. */
     ap_create_sb_handle(&sbh, p, -1, 0);
+#endif
 
     c = (conn_rec *)apr_pcalloc(p, sizeof(conn_rec));
 
