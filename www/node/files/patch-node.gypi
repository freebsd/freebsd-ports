--- node.gypi.orig	2018-04-30 18:52:35 UTC
+++ node.gypi
@@ -298,6 +298,9 @@
         ['openssl_fips != ""', {
           'defines': [ 'NODE_FIPS_MODE' ],
         }],
+        ['openssl_no_asm==1', {
+          'defines': [ 'OPENSSL_NO_ASM' ],
+        }],
         [ 'node_shared_openssl=="false"', {
           'dependencies': [
             './deps/openssl/openssl.gyp:openssl',
