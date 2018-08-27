--- deps/openssl/config/archs/linux-elf/asm/openssl.gypi.orig	2018-08-15 13:53:23 UTC
+++ deps/openssl/config/archs/linux-elf/asm/openssl.gypi
@@ -683,10 +683,10 @@
       'POLY1305_ASM',
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
