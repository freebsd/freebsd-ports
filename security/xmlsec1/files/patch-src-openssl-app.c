--- src/openssl/app.c.orig	2023-10-30 22:27:05 UTC
+++ src/openssl/app.c
@@ -59,6 +59,29 @@
 #include "../cast_helpers.h"
 #include "private.h"
 
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
@@ -490,6 +513,11 @@ xmlSecOpenSSLAppEngineKeyLoad(const char *engineName, 
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
@@ -538,7 +566,7 @@ xmlSecOpenSSLAppEngineKeyLoad(const char *engineName, 
         }
     }
 
-    if(ENGINE_ctrl_cmd(engine, "SET_USER_INTERFACE", 0, (void *)UI_null(), 0, 1) < 0) {
+    if(ENGINE_ctrl_cmd(engine, "SET_USER_INTERFACE", 0, (void *)ui_null, 0, 1) < 0) {
         xmlSecOpenSSLError("ENGINE_ctrl_cmd_string(SET_USER_INTERFACE)", NULL);
         goto done;
     }
@@ -601,6 +629,7 @@ done:
     data = NULL;
 
 done:
+    ui_null_destroy(ui_null);
     /* cleanup */
     if(pKey != NULL) {
         EVP_PKEY_free(pKey);
