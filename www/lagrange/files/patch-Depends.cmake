--- Depends.cmake.orig	2021-09-09 10:00:30 UTC
+++ Depends.cmake
@@ -138,6 +138,7 @@ else ()
     set (TFDN_ENABLE_WEBREQUEST OFF CACHE BOOL "")
     add_subdirectory (lib/the_Foundation)
     add_library (the_Foundation::the_Foundation ALIAS the_Foundation)
+    find_package (OpenSSL)
     if (NOT OPENSSL_FOUND)
         message (FATAL_ERROR "Lagrange requires OpenSSL for TLS. Please check if pkg-config can find 'openssl'.")
     endif ()
