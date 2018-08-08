--- cmake/modules/FindLibCrypto.cmake.orig	2018-06-25 03:06:06 UTC
+++ cmake/modules/FindLibCrypto.cmake
@@ -28,7 +28,7 @@ find_path(LibCrypto_INCLUDE_DIR
         )
 
 find_library(LibCrypto_LIBRARY
-        NAMES libcrypto.a libcrypto.so
+        NAMES libcrypto.so
         HINTS ${LibCrypto_ROOT_DIR}/build/crypto
         ${LibCrypto_ROOT_DIR}/build
         ${LibCrypto_ROOT_DIR}
