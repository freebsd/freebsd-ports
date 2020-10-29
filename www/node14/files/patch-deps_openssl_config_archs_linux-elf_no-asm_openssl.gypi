--- deps/openssl/config/archs/linux-elf/no-asm/openssl.gypi.orig	2019-08-06 20:46:23 UTC
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
