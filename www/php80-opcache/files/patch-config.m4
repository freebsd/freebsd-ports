--- config.m4.orig	2021-06-01 18:43:05 UTC
+++ config.m4
@@ -29,7 +29,7 @@ if test "$PHP_OPCACHE" != "no"; then
 
   if test "$PHP_OPCACHE_JIT" = "yes"; then
     case $host_cpu in
-      i[[34567]]86*|x86*)
+      i[[34567]]86*|x86*|amd64)
         ;;
       *)
         AC_MSG_WARN([JIT not supported by host architecture])
@@ -60,7 +60,7 @@ if test "$PHP_OPCACHE" != "no"; then
         *x86_64-*-darwin*)
           DASM_FLAGS="-D X64APPLE=1 -D X64=1"
         ;;
-        *x86_64*)
+        *x86_64*|amd64-*-freebsd*)
           DASM_FLAGS="-D X64=1"
         ;;
       esac
