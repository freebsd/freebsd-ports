--- cmake/Depends.cmake.orig	2023-05-02 20:13:29 UTC
+++ cmake/Depends.cmake
@@ -42,6 +42,7 @@ else ()
     set (TFDN_ENABLE_WEBREQUEST OFF CACHE BOOL "")
     add_subdirectory (lib/the_Foundation)
     add_library (the_Foundation::the_Foundation ALIAS the_Foundation)
+    find_package (OpenSSL)
     if (NOT OPENSSL_FOUND)
         message (FATAL_ERROR "Lagrange requires OpenSSL for TLS. Please check if pkg-config can find 'openssl'.")
     endif ()
