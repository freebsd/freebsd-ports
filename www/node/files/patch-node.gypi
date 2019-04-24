--- node.gypi.orig	2019-04-23 12:30:45 UTC
+++ node.gypi
@@ -315,6 +315,9 @@
         ['openssl_fips != "" or openssl_is_fips=="true"', {
           'defines': [ 'NODE_FIPS_MODE' ],
         }],
+        ['openssl_no_asm==1', {
+          'defines': [ 'OPENSSL_NO_ASM' ],
+        }],
         [ 'node_shared_openssl=="false"', {
           'dependencies': [
             './deps/openssl/openssl.gyp:openssl',
