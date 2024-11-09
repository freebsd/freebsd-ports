--- node.gypi.orig	2023-05-16 06:58:21 UTC
+++ node.gypi
@@ -349,6 +349,9 @@
     [ 'node_use_openssl=="true"', {
       'defines': [ 'HAVE_OPENSSL=1' ],
       'conditions': [
+        ['openssl_no_asm==1', {
+          'defines': [ 'OPENSSL_NO_ASM' ],
+        }],
         [ 'node_shared_openssl=="false"', {
           'defines': [ 'OPENSSL_API_COMPAT=0x10100000L', ],
           'dependencies': [
