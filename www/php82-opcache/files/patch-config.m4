--- config.m4.orig	2021-12-15 02:00:45 UTC
+++ config.m4
@@ -29,7 +29,7 @@ if test "$PHP_OPCACHE" != "no"; then
 
   if test "$PHP_OPCACHE_JIT" = "yes"; then
     case $host_cpu in
-      i[[34567]]86*|x86*|aarch64)
+      i[[34567]]86*|x86*|aarch64|amd64)
         ;;
       *)
         AC_MSG_WARN([JIT not supported by host architecture])
@@ -48,7 +48,7 @@ if test "$PHP_OPCACHE" != "no"; then
         DASM_FLAGS="-D X64APPLE=1 -D X64=1"
         DASM_ARCH="x86"
         ;;
-      x86_64*)
+      *x86_64*|amd64-*-freebsd*)
         DASM_FLAGS="-D X64=1"
         DASM_ARCH="x86"
         ;;
