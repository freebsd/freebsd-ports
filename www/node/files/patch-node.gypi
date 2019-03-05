--- node.gypi.orig	2019-01-30 20:43:35 UTC
+++ node.gypi
@@ -322,6 +322,9 @@
         ['openssl_fips != "" or openssl_is_fips=="true"', {
           'defines': [ 'NODE_FIPS_MODE' ],
         }],
+        ['openssl_no_asm==1', {
+          'defines': [ 'OPENSSL_NO_ASM' ],
+        }],
         [ 'node_shared_openssl=="false"', {
           'dependencies': [
             './deps/openssl/openssl.gyp:openssl',
