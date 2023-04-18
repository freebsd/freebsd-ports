--- deps/openssl/config/archs/linux-elf/no-asm/openssl-cl.gypi.orig	2021-10-19 00:48:28 UTC
+++ deps/openssl/config/archs/linux-elf/no-asm/openssl-cl.gypi
@@ -13,7 +13,7 @@
       '-Wall -O3 -fomit-frame-pointer',
     ],
     'openssl_ex_libs_linux-elf': [
-      '-ldl -pthread',
+      '-pthread',
     ],
     'openssl_cli_srcs_linux-elf': [
       'openssl/apps/lib/cmp_mock_srv.c',
