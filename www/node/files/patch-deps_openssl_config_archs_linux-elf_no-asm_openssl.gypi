--- deps/openssl/config/archs/linux-elf/no-asm/openssl.gypi.orig	2021-02-02 17:47:01 UTC
+++ deps/openssl/config/archs/linux-elf/no-asm/openssl.gypi
@@ -696,7 +696,7 @@
       '-Wall -O3 -fomit-frame-pointer',
     ],
     'openssl_ex_libs_linux-elf': [
-      '-ldl -pthread',
+      '-pthread',
     ],
   },
   'include_dirs': [
