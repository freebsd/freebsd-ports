--- m4/check-ssl.m4.orig	2008-09-17 10:41:08.000000000 -0500
+++ m4/check-ssl.m4	2008-09-17 10:41:45.000000000 -0500
@@ -45,7 +45,7 @@
 [
     AC_MSG_CHECKING([for OpenSSL])
 
-    for dir in $withval /usr/local/ssl /usr/lib/ssl /usr/ssl /usr/pkg /usr/local /usr; do
+    for dir in $with_ssl /usr/local/ssl /usr/lib/ssl /usr/ssl /usr/pkg /usr/local /usr; do
         ssldir="$dir"
         if test -f "$dir/include/openssl/ssl.h"; then
             found_ssl="yes";
