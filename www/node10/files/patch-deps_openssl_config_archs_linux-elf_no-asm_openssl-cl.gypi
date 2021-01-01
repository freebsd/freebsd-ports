--- deps/openssl/config/archs/linux-elf/no-asm/openssl-cl.gypi.orig	2019-05-28 21:32:15 UTC
+++ deps/openssl/config/archs/linux-elf/no-asm/openssl-cl.gypi
@@ -7,12 +7,11 @@
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
     'openssl_cli_srcs_linux-elf': [
       'openssl/apps/asn1pars.c',
