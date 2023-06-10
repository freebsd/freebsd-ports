--- config.m4.orig	2023-06-06 15:54:29 UTC
+++ config.m4
@@ -35,7 +35,7 @@ if test "$PHP_OPCACHE" != "no"; then
 
   if test "$PHP_OPCACHE_JIT" = "yes"; then
     case $host_cpu in
-      i[[34567]]86*|x86*|aarch64)
+      i[[34567]]86*|x86*|aarch64|amd64)
         ;;
       *)
         AC_MSG_WARN([JIT not supported by host architecture])
@@ -54,7 +54,7 @@ if test "$PHP_OPCACHE" != "no"; then
         DASM_FLAGS="-D X64APPLE=1 -D X64=1"
         DASM_ARCH="x86"
         ;;
-      x86_64*)
+      *x86_64*|amd64-*-freebsd*)
         DASM_FLAGS="-D X64=1"
         DASM_ARCH="x86"
         ;;
