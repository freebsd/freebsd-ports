--- node.gypi.orig	2020-02-18 05:08:36 UTC
+++ node.gypi
@@ -331,6 +331,9 @@
         ['openssl_fips != "" or openssl_is_fips=="true"', {
           'defines': [ 'NODE_FIPS_MODE' ],
         }],
+        ['openssl_no_asm==1', {
+          'defines': [ 'OPENSSL_NO_ASM' ],
+        }],
         [ 'node_shared_openssl=="false"', {
           'dependencies': [
             './deps/openssl/openssl.gyp:openssl',
