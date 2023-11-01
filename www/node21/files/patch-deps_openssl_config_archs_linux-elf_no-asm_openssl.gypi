--- deps/openssl/config/archs/linux-elf/no-asm/openssl.gypi.orig	2023-05-16 06:58:19 UTC
+++ deps/openssl/config/archs/linux-elf/no-asm/openssl.gypi
@@ -977,7 +977,7 @@
       '-Wall -O3 -fomit-frame-pointer',
     ],
     'openssl_ex_libs_linux-elf': [
-      '-ldl -pthread',
+      '-pthread',
     ],
   },
   'include_dirs': [
