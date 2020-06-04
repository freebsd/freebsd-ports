--- node.gypi.orig	2020-04-28 09:45:25 UTC
+++ node.gypi
@@ -341,6 +341,9 @@
         ['openssl_fips != "" or openssl_is_fips=="true"', {
           'defines': [ 'NODE_FIPS_MODE' ],
         }],
+        ['openssl_no_asm==1', {
+          'defines': [ 'OPENSSL_NO_ASM' ],
+        }],
         [ 'node_shared_openssl=="false"', {
           'dependencies': [
             './deps/openssl/openssl.gyp:openssl',
