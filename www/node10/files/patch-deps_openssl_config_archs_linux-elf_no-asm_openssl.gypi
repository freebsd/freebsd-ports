--- deps/openssl/config/archs/linux-elf/no-asm/openssl.gypi.orig	2018-08-15 13:53:23 UTC
+++ deps/openssl/config/archs/linux-elf/no-asm/openssl.gypi
@@ -654,10 +654,10 @@
       'OPENSSL_PIC',
     ],
     'openssl_cflags_linux-elf': [
-      '-Wall -O3 -pthread -DL_ENDIAN -fomit-frame-pointer',
+      '-Wall -O3 -pthread -DL_ENDIAN',
     ],
     'openssl_ex_libs_linux-elf': [
-      '-ldl -pthread',
+      '',
     ],
   },
   'include_dirs': [
