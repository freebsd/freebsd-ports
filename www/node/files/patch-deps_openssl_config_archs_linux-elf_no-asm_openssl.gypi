--- deps/openssl/config/archs/linux-elf/no-asm/openssl.gypi.orig	2021-10-19 00:48:28 UTC
+++ deps/openssl/config/archs/linux-elf/no-asm/openssl.gypi
@@ -980,7 +980,7 @@
       '-Wall -O3 -fomit-frame-pointer',
     ],
     'openssl_ex_libs_linux-elf': [
-      '-ldl -pthread',
+      '-pthread',
     ],
   },
   'include_dirs': [
