--- deps/openssl/config/archs/linux-elf/no-asm/openssl.gypi.orig	2024-02-13 21:43:29 UTC
+++ deps/openssl/config/archs/linux-elf/no-asm/openssl.gypi
@@ -976,7 +976,7 @@
       '-Wall -O3 -fomit-frame-pointer',
     ],
     'openssl_ex_libs_linux-elf': [
-      '-ldl -pthread',
+      '-pthread',
     ],
   },
   'include_dirs': [
