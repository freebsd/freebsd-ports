--- third_party/openssl/openssl.gyp.orig	2011-11-21 22:53:37.000000000 +0200
+++ third_party/openssl/openssl.gyp	2011-11-21 22:54:53.000000000 +0200
@@ -576,7 +576,7 @@
         'openssl/engines/e_ubsec.c',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'defines': [
             # ENGINESDIR must be defined if OPENSSLDIR is.
             'ENGINESDIR="/dev/null"',
