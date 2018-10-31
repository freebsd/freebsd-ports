--- node.gypi.orig	2018-06-06 12:52:40 UTC
+++ node.gypi
@@ -294,6 +294,9 @@
         ['openssl_fips != ""', {
           'defines': [ 'NODE_FIPS_MODE' ],
         }],
+        ['openssl_no_asm==1', {
+          'defines': [ 'OPENSSL_NO_ASM' ],
+        }],
         [ 'node_shared_openssl=="false"', {
           'dependencies': [
             './deps/openssl/openssl.gyp:openssl',
