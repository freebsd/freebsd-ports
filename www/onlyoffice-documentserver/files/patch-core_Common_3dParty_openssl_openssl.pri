--- core/Common/3dParty/openssl/openssl.pri.orig	2023-06-14 14:31:26.960051000 +0200
+++ core/Common/3dParty/openssl/openssl.pri	2023-06-14 14:31:00.960232000 +0200
@@ -32,8 +32,8 @@ core_windows {
     LIBS += $$OPENSSL_LIBS_DIRECTORY/libssl.lib
 	LIBS += $$OPENSSL_LIBS_DIRECTORY/libcrypto.lib
 } else {
-    LIBS += $$OPENSSL_LIBS_DIRECTORY/libssl.a
-	LIBS += $$OPENSSL_LIBS_DIRECTORY/libcrypto.a
+    LIBS +=  /usr/local/lib/libssl.a
+	LIBS +=  /usr/local/lib/libcrypto.a
 }
 
 INCLUDEPATH += $$OPENSSL_LIBS_DIRECTORY/../include
