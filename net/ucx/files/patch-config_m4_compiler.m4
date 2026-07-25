--- config/m4/compiler.m4.orig	2026-07-01 18:11:37 UTC
+++ config/m4/compiler.m4
@@ -10,7 +10,12 @@
 #
 # Initialize CFLAGS
 #
-BASE_CFLAGS="-g -Wall -Werror"
+case $host_os in
+freebsd*)
+    BASE_CFLAGS="-g -Wall" ;;
+*)
+    BASE_CFLAGS="-g -Wall -Werror" ;;
+esac
 
 # Prevent libtool from suppression of warnings
 LT_CFLAGS="-no-suppress"
