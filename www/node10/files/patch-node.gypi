--- node.gypi.orig	2019-07-31 17:45:05 UTC
+++ node.gypi
@@ -316,6 +316,9 @@
         ['openssl_fips != ""', {
           'defines': [ 'NODE_FIPS_MODE' ],
         }],
+        ['openssl_no_asm==1', {
+          'defines': [ 'OPENSSL_NO_ASM' ],
+        }],
         [ 'node_shared_openssl=="false"', {
           'dependencies': [
             './deps/openssl/openssl.gyp:openssl',
