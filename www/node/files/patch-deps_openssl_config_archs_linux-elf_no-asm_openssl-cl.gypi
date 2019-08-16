--- deps/openssl/config/archs/linux-elf/no-asm/openssl-cl.gypi.orig	2019-08-06 20:46:23 UTC
+++ deps/openssl/config/archs/linux-elf/no-asm/openssl-cl.gypi
@@ -12,7 +12,7 @@
       '-Wall -O3 -fomit-frame-pointer',
     ],
     'openssl_ex_libs_linux-elf': [
-      '-ldl -pthread',
+      '-pthread',
     ],
     'openssl_cli_srcs_linux-elf': [
       'openssl/apps/asn1pars.c',
