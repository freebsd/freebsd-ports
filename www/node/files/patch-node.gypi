--- node.gypi.orig	2018-10-23 15:59:38 UTC
+++ node.gypi
@@ -304,6 +304,9 @@
         ['openssl_fips != ""', {
           'defines': [ 'NODE_FIPS_MODE' ],
         }],
+        ['openssl_no_asm==1', {
+          'defines': [ 'OPENSSL_NO_ASM' ],
+        }],
         [ 'node_shared_openssl=="false"', {
           'dependencies': [
             './deps/openssl/openssl.gyp:openssl',
