--- lib/openssl.pri.orig	2020-08-27 19:18:49 UTC
+++ lib/openssl.pri
@@ -11,7 +11,5 @@ win32 {
     LIBS += -llibssl
     LIBS += -llibcrypto
 } else {
-    PKGCONFIG += openssl
-
     LIBS += -lssl -lcrypto
 }
