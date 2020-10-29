--- deps/openssl/config/archs/linux-elf/no-asm/openssl.gypi.orig	2020-10-20 11:49:49 UTC
+++ deps/openssl/config/archs/linux-elf/no-asm/openssl.gypi
@@ -698,7 +698,7 @@
       '-Wall -O3 -fomit-frame-pointer',
     ],
     'openssl_ex_libs_linux-elf': [
-      '-ldl -pthread',
+      '-pthread',
     ],
   },
   'include_dirs': [
