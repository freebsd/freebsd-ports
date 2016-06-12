diff -urN ftimes-3.11.0.old/src/ssl.c ftimes-3.11.0.new/src/ssl.c
--- src/ssl.c	2014-07-18 02:40:44.000000000 -0400
+++ src/ssl.c	2016-01-13 17:18:29.073028573 -0500
@@ -251,7 +251,7 @@
    *
    *********************************************************************
    */
-  psProperties->psslCTX = SSL_CTX_new(SSLv3_client_method());
+  psProperties->psslCTX = SSL_CTX_new(SSLv23_client_method());
   if (psProperties->psslCTX == NULL)
   {
     ERR_error_string(ERR_get_error(), acLocalError);
@@ -262,6 +262,33 @@
   /*-
    *********************************************************************
    *
+   * Disable protocol versions that are no longer safe to use.
+   *
+   *********************************************************************
+   */
+  SSL_CTX_set_options
+  (
+    psProperties->psslCTX,
+    (
+        0
+#ifdef  SSL_OP_NO_SSLv2
+      | SSL_OP_NO_SSLv2
+#endif
+#ifdef  SSL_OP_NO_SSLv3
+      | SSL_OP_NO_SSLv3
+#endif
+#ifdef  SSL_OP_NO_TLSv1
+      | SSL_OP_NO_TLSv1
+#endif
+#ifdef  SSL_OP_NO_TLSv1_1
+      | SSL_OP_NO_TLSv1_1
+#endif
+    )
+  );
+
+  /*-
+   *********************************************************************
+   *
    * Setup SSL certificate verification. Load the bundled certificate
    * authorities file. A common name (CN) and a positive chain length
    * must be specified to activate PEER verification. If you want to
