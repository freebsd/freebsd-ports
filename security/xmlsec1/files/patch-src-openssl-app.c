--- src/openssl/app.c.orig	2022-05-03 23:36:17.000000000 +0900
+++ src/openssl/app.c	2022-05-07 05:18:46.065103000 +0900
@@ -43,6 +43,29 @@
 
 #include "openssl_compat.h"
 
+#if defined(XMLSEC_OPENSSL_API_110) && defined(LIBRESSL_VERSION_NUMBER)
+static UI_METHOD *
+ui_null_create(void)
+{
+	return (UI_create_method("OpenSSL NULL UI"));
+}
+static void
+ui_null_destroy(UI_METHOD *ui)
+{
+	UI_destroy_method(ui);
+}
+#else
+static const UI_METHOD *
+ui_null_create(void)
+{
+	return (UI_null());
+}
+static void
+ui_null_destroy(const UI_METHOD *ui)
+{
+}
+#endif
+
 static int      xmlSecOpenSSLAppLoadRANDFile            (const char *filename);
 static int      xmlSecOpenSSLAppSaveRANDFile            (const char *filename);
 static int      xmlSecOpenSSLDefaultPasswordCallback    (char *buf,
@@ -415,6 +438,11 @@
     EVP_PKEY* pKey = NULL;
     int engineInit = 0;
     int ret;
+#if defined(XMLSEC_OPENSSL_API_110) && defined(LIBRESSL_VERSION_NUMBER)
+    UI_METHOD *ui_null = ui_null_create();
+#else
+    const UI_METHOD *ui_null = ui_null_create();
+#endif
 
 #ifndef OPENSSL_NO_ENGINE
     xmlSecAssert2(engineName != NULL, NULL);
@@ -437,7 +465,7 @@
         }
     }
 
-    if(ENGINE_ctrl_cmd(engine, "SET_USER_INTERFACE", 0, (void *)UI_null(), 0, 1) < 0) {
+    if(ENGINE_ctrl_cmd(engine, "SET_USER_INTERFACE", 0, (void *)ui_null, 0, 1) < 0) {
         xmlSecOpenSSLError("ENGINE_ctrl_cmd_string(SET_USER_INTERFACE)", NULL);
         goto done;
     }
@@ -453,7 +481,7 @@
 
     /* load private key */
     pKey = ENGINE_load_private_key(engine, engineKeyId,
-                                   (UI_METHOD *)UI_null(),
+                                   (UI_METHOD *)ui_null,
                                    NULL);
     if(pKey == NULL) {
         xmlSecOpenSSLError("ENGINE_load_private_key", NULL);
@@ -484,6 +512,7 @@
     data = NULL;
 
 done:
+    ui_null_destroy(ui_null);
     /* cleanup */
     if(pKey != NULL) {
         EVP_PKEY_free(pKey);
