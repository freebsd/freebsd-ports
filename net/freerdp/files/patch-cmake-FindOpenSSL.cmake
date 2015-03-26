--- cmake/FindOpenSSL.cmake.orig	2013-07-10 04:00:21.000000000 -0400
+++ cmake/FindOpenSSL.cmake	2015-03-25 19:26:35.154024000 -0400
@@ -270,7 +270,7 @@
     set(OPENSSL_VERSION "${_OPENSSL_VERSION}")
   elseif(OPENSSL_INCLUDE_DIR AND EXISTS "${OPENSSL_INCLUDE_DIR}/openssl/opensslv.h")
     file(STRINGS "${OPENSSL_INCLUDE_DIR}/openssl/opensslv.h" openssl_version_str
-         REGEX "^#define[\t ]+OPENSSL_VERSION_NUMBER[\t ]+0x([0-9a-fA-F])+.*")
+         REGEX "^#[\t ]*define[\t ]+OPENSSL_VERSION_NUMBER[\t ]+0x([0-9a-fA-F])+.*")
 
     # The version number is encoded as 0xMNNFFPPS: major minor fix patch status
     # The status gives if this is a developer or prerelease and is ignored here.
