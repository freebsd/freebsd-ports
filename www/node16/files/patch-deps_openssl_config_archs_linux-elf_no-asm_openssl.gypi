--- deps/openssl/config/archs/linux-elf/no-asm/openssl.gypi.orig	2023-03-28 21:14:18 UTC
+++ deps/openssl/config/archs/linux-elf/no-asm/openssl.gypi
@@ -699,7 +699,7 @@
       '-Wall -O3 -fomit-frame-pointer',
     ],
     'openssl_ex_libs_linux-elf': [
-      '-ldl -pthread',
+      '-pthread',
     ],
   },
   'include_dirs': [
