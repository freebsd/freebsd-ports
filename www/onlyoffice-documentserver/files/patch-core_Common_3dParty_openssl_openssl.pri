--- core/Common/3dParty/openssl/openssl.pri.orig	2023-06-14 14:31:26.960051000 +0200
+++ core/Common/3dParty/openssl/openssl.pri	2023-06-14 14:31:00.960232000 +0200
@@ -41,8 +41,8 @@ core_windows {
     LIBS += $$OPENSSL_LIBS_DIRECTORY/libssl.lib
 	LIBS += $$OPENSSL_LIBS_DIRECTORY/libcrypto.lib
 } else {
-    LIBS += $$OPENSSL_LIBS_DIRECTORY/libssl.a
-	LIBS += $$OPENSSL_LIBS_DIRECTORY/libcrypto.a
+    LIBS +=  %%LOCALBASE%%/lib/libssl.a
+	LIBS +=  %%LOCALBASE%%/lib/libcrypto.a
 }
 
 INCLUDEPATH += $$OPENSSL_LIBS_DIRECTORY/../include
