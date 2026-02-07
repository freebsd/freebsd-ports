--- cmake/openssl.cmake.orig	2020-07-14 19:27:32 UTC
+++ cmake/openssl.cmake
@@ -32,7 +32,7 @@ macro (find_libcrypto)
             if(OPENSSL_STATIC_LINK)
                 set(OPENSSL_USE_STATIC_LIBS TRUE) #Need to be set so that find_package would find the static library
             endif(OPENSSL_STATIC_LINK)
-            find_package(OpenSSL REQUIRED)
+            find_package(OpenSSL)
 
             if(OpenSSL_FOUND)
                 set(LIBCRYPTO_LDFLAGS OpenSSL::Crypto)
@@ -60,7 +60,7 @@ macro (find_libcrypto)
         if(NOT LIBCRYPTO_FOUND)
 
             set(ENV{PKG_CONFIG_PATH} "${OPENSSL_PKG_PATH}:$ENV{PKG_CONFIG_PATH}")
-            pkg_check_modules(LIBCRYPTO REQUIRED libcrypto)
+            pkg_check_modules(LIBCRYPTO libcrypto)
             if(LIBCRYPTO_FOUND)
                 if(VERBOSE_CMAKE)
                     message("LIBCRYPTO_FOUND: ${LIBCRYPTO_FOUND}")
@@ -76,7 +76,7 @@ macro (find_libcrypto)
                     message("LIBCRYPTO_LIBDIR: ${LIBCRYPTO_LIBDIR}")
                 endif(VERBOSE_CMAKE)
             else(LIBCRYPTO_FOUND)
-                message (FATAL_ERROR "libcrypto not found. Aborting...")
+                #message (FATAL_ERROR "libcrypto not found. Aborting...")
             endif(LIBCRYPTO_FOUND)
             set(OPENSSL_VERSION ${LIBCRYPTO_VERSION})
 
@@ -89,4 +89,4 @@ macro (find_libcrypto)
     link_directories(${LIBCRYPTO_LIBRARY_DIRS})
     include_directories(${LIBCRYPTO_INCLUDE_DIRS})
 
-endmacro()
\ No newline at end of file
+endmacro()
