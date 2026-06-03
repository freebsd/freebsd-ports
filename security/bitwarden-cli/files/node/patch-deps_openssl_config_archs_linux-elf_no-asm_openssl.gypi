--- deps/openssl/config/archs/linux-elf/no-asm/openssl.gypi.orig	2025-05-14 12:21:12 UTC
+++ deps/openssl/config/archs/linux-elf/no-asm/openssl.gypi
@@ -974,7 +974,7 @@
       '-Wall -O3 -fomit-frame-pointer',
     ],
     'openssl_ex_libs_linux-elf': [
-      '-ldl -pthread',
+      '-pthread',
     ],
   },
   'include_dirs': [
