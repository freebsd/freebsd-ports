--- dep/jwt-cpp/include/jwt-cpp/jwt.h.orig	2022-10-18 11:00:07 UTC
+++ dep/jwt-cpp/include/jwt-cpp/jwt.h
@@ -45,11 +45,6 @@
 #define OPENSSL110
 #endif
 
-#if defined(LIBRESSL_VERSION_NUMBER)
-#define OPENSSL10
-#define OPENSSL110
-#endif
-
 #ifndef JWT_CLAIM_EXPLICIT
 #define JWT_CLAIM_EXPLICIT explicit
 #endif
