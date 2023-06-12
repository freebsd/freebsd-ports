--- node.gypi.orig	2023-03-28 21:14:21 UTC
+++ node.gypi
@@ -338,6 +338,9 @@
     [ 'node_use_openssl=="true"', {
       'defines': [ 'HAVE_OPENSSL=1' ],
       'conditions': [
+        ['openssl_no_asm==1', {
+          'defines': [ 'OPENSSL_NO_ASM' ],
+        }],
         [ 'node_shared_openssl=="false"', {
           'dependencies': [
             './deps/openssl/openssl.gyp:openssl',
