--- src/openssl/app.c.orig	2022-11-28 21:40:24 UTC
+++ src/openssl/app.c
@@ -46,6 +46,29 @@
 
 #include "../cast_helpers.h"
 
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
 static int      xmlSecOpenSSLDefaultPasswordCallback    (char *buf,
                                                          int bufsiz,
                                                          int verify,
@@ -462,6 +485,11 @@ xmlSecOpenSSLAppEngineKeyLoad(const char *engineName, 
     EVP_PKEY* pKey = NULL;
     int engineInit = 0;
     int ret;
+#if defined(XMLSEC_OPENSSL_API_110) && defined(LIBRESSL_VERSION_NUMBER)
+    UI_METHOD *ui_null = ui_null_create();
+#else
+    const UI_METHOD *ui_null = ui_null_create();
+#endif
 
     xmlSecAssert2(engineName != NULL, NULL);
     xmlSecAssert2(engineKeyId != NULL, NULL);
@@ -487,7 +515,7 @@ xmlSecOpenSSLAppEngineKeyLoad(const char *engineName, 
         }
     }
 
-    if(ENGINE_ctrl_cmd(engine, "SET_USER_INTERFACE", 0, (void *)UI_null(), 0, 1) < 0) {
+    if(ENGINE_ctrl_cmd(engine, "SET_USER_INTERFACE", 0, (void *)ui_null, 0, 1) < 0) {
         xmlSecOpenSSLError("ENGINE_ctrl_cmd_string(SET_USER_INTERFACE)", NULL);
         goto done;
     }
@@ -503,7 +531,7 @@ xmlSecOpenSSLAppEngineKeyLoad(const char *engineName, 
 
     /* load private key */
     pKey = ENGINE_load_private_key(engine, engineKeyId,
-                                   (UI_METHOD *)UI_null(),
+                                   (UI_METHOD *)ui_null,
                                    NULL);
     if(pKey == NULL) {
         xmlSecOpenSSLError("ENGINE_load_private_key", NULL);
@@ -534,6 +562,7 @@ done:
     data = NULL;
 
 done:
+    ui_null_destroy(ui_null);
     /* cleanup */
     if(pKey != NULL) {
         EVP_PKEY_free(pKey);
