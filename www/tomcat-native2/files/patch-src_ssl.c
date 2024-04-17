--- src/ssl.c.orig	2024-02-04 19:32:52 UTC
+++ src/ssl.c
@@ -395,30 +395,14 @@ TCN_IMPLEMENT_CALL(void, SSL, randSet)(TCN_STDARGS, js
 
 TCN_IMPLEMENT_CALL(jint, SSL, fipsModeGet)(TCN_STDARGS)
 {
-#if defined(LIBRESSL_VERSION_NUMBER)
     UNREFERENCED(o);
-    /* LibreSSL doesn't support FIPS */
-    return 0;
+#ifdef OPENSSL_FIPS
+    return FIPS_mode();
 #else
-    EVP_MD              *md;
-    const OSSL_PROVIDER *provider;
-    const char          *name;
-    UNREFERENCED(o);
+    /* FIPS is unavailable */
+    tcn_ThrowException(e, "FIPS was not available to tcnative at build time. You will need to re-build tcnative against an OpenSSL with FIPS.");
 
-    // Maps the OpenSSL 3. x onwards behaviour to theOpenSSL 1.x API
-
-    // Checks that FIPS is the default provider
-    md = EVP_MD_fetch(NULL, "SHA-512", NULL);
-    provider = EVP_MD_get0_provider(md);
-    name = OSSL_PROVIDER_get0_name(provider);
-    // Clean up
-    EVP_MD_free(md);
-
-    if (strcmp("fips", name)) {
-        return 0;
-    } else {
-        return 1;
-    }
+    return 0;
 #endif
 }
 
@@ -427,8 +411,22 @@ TCN_IMPLEMENT_CALL(jint, SSL, fipsModeSet)(TCN_STDARGS
     int r = 0;
     UNREFERENCED(o);
 
-    /* This method should never be called when using Tomcat Native 2.x onwards */
-    tcn_ThrowException(e, "fipsModeSet is not supported in Tomcat Native 2.x onwards.");
+#ifdef OPENSSL_FIPS
+    if(1 != (r = (jint)FIPS_mode_set((int)mode))) {
+      /* arrange to get a human-readable error message */
+      unsigned long err = SSL_ERR_get();
+      char msg[256];
+
+      /* ERR_load_crypto_strings() already called in initialize() */
+
+      ERR_error_string_n(err, msg, 256);
+
+      tcn_ThrowException(e, msg);
+    }
+#else
+    /* FIPS is unavailable */
+    tcn_ThrowException(e, "FIPS was not available to tcnative at build time. You will need to re-build tcnative against an OpenSSL with FIPS.");
+#endif
 
     return r;
 }
