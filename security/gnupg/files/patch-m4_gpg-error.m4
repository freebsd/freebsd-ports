--- m4/gpg-error.m4.orig	2024-05-15 10:33:38 UTC
+++ m4/gpg-error.m4
@@ -67,7 +67,7 @@ AC_DEFUN([_AM_PATH_GPGRT_CONFIG],[dnl
     # Get the prefix of gpgrt-config assuming it's something like:
     #   <PREFIX>/bin/gpgrt-config
     gpgrt_prefix=${GPGRT_CONFIG%/*/*}
-    possible_libdir1=${gpgrt_prefix}/lib
+    possible_libdir1=${gpgrt_prefix}/libdata
     # Determine by using system libdir-format with CC, it's like:
     #   Normal style: /usr/lib
     #   GNU cross style: /usr/<triplet>/lib
