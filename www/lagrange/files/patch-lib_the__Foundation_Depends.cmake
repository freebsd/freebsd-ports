--- lib/the_Foundation/Depends.cmake.orig	2023-05-02 20:08:20 UTC
+++ lib/the_Foundation/Depends.cmake
@@ -24,13 +24,12 @@ if (NOT IOS AND NOT ANDROID)
                 target_link_libraries (libssl INTERFACE ${LIBSSL} ${LIBCRYPTO})
                 set (OPENSSL_FOUND YES)
             else ()
-                pkg_check_modules (OPENSSL eopenssl11)
                 if (OPENSSL_FOUND)
                     set (EOPENSSL_FOUND YES)
                 endif ()
             endif ()
         else ()
-             pkg_check_modules (OPENSSL openssl)
+            find_package (OpenSSL REQUIRED)
         endif ()
     endif ()
     # Unicode text strings
