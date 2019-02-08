--- deps/openssl/config/archs/linux-elf/no-asm/openssl.gypi.orig	2019-02-06 21:04:54 UTC
+++ deps/openssl/config/archs/linux-elf/no-asm/openssl.gypi
@@ -691,12 +691,11 @@
       'OPENSSL_PIC',
     ],
     'openssl_cflags_linux-elf': [
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
