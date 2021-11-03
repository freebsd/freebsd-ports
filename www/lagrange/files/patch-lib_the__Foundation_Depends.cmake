--- lib/the_Foundation/Depends.cmake.orig	2021-11-03 22:54:49 UTC
+++ lib/the_Foundation/Depends.cmake
@@ -10,9 +10,8 @@ if (NOT IOS)
         set (iHaveCurl NO)
     endif ()
     if (TFDN_ENABLE_TLSREQUEST)
-        pkg_check_modules (OPENSSL eopenssl11)  # BSD
         if (NOT OPENSSL_FOUND)
-            pkg_check_modules (OPENSSL openssl)
+		find_package (OpenSSL REQUIRED) 
         endif ()
     else ()
         set (OPENSSL_FOUND NO)
