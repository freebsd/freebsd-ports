--- core/Common/3dParty/openssl/openssl.pri.orig	2025-08-02 18:33:34 UTC
+++ core/Common/3dParty/openssl/openssl.pri
@@ -32,8 +32,8 @@ core_windows {
     LIBS += $$OPENSSL_LIBS_DIRECTORY/libssl.lib
 	LIBS += $$OPENSSL_LIBS_DIRECTORY/libcrypto.lib
 } else {
-    LIBS += $$OPENSSL_LIBS_DIRECTORY/libssl.a
-	LIBS += $$OPENSSL_LIBS_DIRECTORY/libcrypto.a
+    LIBS +=  %%OPENSSL_LIB%%/libssl.so
+	LIBS +=  %%OPENSSL_LIB%%/libcrypto.so
 }
 
 INCLUDEPATH += $$OPENSSL_LIBS_DIRECTORY/../include
