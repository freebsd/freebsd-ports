--- deps/openssl/config/archs/linux-elf/asm/openssl.gypi.orig	2019-01-30 20:43:11 UTC
+++ deps/openssl/config/archs/linux-elf/asm/openssl.gypi
@@ -722,12 +722,11 @@
     ],
     'openssl_cflags_linux-elf': [
       '-Wa,--noexecstack',
-      '-Wall -O3 -fomit-frame-pointer',
+      '-Wall -O3',
       '-pthread',
-      '-Wall -O3 -fomit-frame-pointer',
     ],
     'openssl_ex_libs_linux-elf': [
-      '-ldl -pthread',
+      '',
     ],
   },
   'include_dirs': [
