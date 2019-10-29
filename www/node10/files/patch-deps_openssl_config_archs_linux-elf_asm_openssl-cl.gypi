--- deps/openssl/config/archs/linux-elf/asm/openssl-cl.gypi.orig	2019-10-22 16:36:22 UTC
+++ deps/openssl/config/archs/linux-elf/asm/openssl-cl.gypi
@@ -24,12 +24,11 @@
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
     'openssl_cli_srcs_linux-elf': [
       'openssl/apps/asn1pars.c',
