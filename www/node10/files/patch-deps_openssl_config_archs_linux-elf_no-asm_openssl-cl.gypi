--- deps/openssl/config/archs/linux-elf/no-asm/openssl-cl.gypi.orig	2018-05-11 11:01:14 UTC
+++ deps/openssl/config/archs/linux-elf/no-asm/openssl-cl.gypi
@@ -9,10 +9,10 @@
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
     'openssl_cli_srcs_linux-elf': [
       'openssl/apps/app_rand.c',
