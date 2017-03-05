--- src/network/ssl/qsslsocket_openssl_symbols.cpp.orig	2016-12-01 08:17:04 UTC
+++ src/network/ssl/qsslsocket_openssl_symbols.cpp
@@ -1006,8 +1008,23 @@ bool q_resolveOpenSslSymbols()
 #endif
     return true;
 }
+
 #endif // !defined QT_LINKED_OPENSSL
 
+bool q_LibreSSL()
+{
+    return strncmp(q_SSLeay_version(SSLEAY_VERSION), "LibreSSL", 8) == 0;
+}
+
+long q_LibreSSL_version()
+{
+#ifdef LIBRESSL_VERSION_NUMBER
+    return LIBRESSL_VERSION_NUMBER;
+#else
+    return 0L;
+#endif
+}
+
 //==============================================================================
 // contributed by Jay Case of Sarvega, Inc.; http://sarvega.com/
 // Based on X509_cmp_time() for intitial buffer hacking.
