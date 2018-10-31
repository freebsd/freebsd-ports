--- deps/openssl/config/archs/linux-elf/asm/openssl-cl.gypi.orig	2018-05-11 12:05:05 UTC
+++ deps/openssl/config/archs/linux-elf/asm/openssl-cl.gypi
@@ -26,10 +26,10 @@
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
     'openssl_cli_srcs_linux-elf': [
       'openssl/apps/app_rand.c',
