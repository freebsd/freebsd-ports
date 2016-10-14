--- node.gyp.orig	2016-10-12 21:30:37 UTC
+++ node.gyp
@@ -477,6 +477,8 @@
         }],
         [ 'node_shared_zlib=="false"', {
           'dependencies': [ 'deps/zlib/zlib.gyp:zlib' ],
+        }, {
+          'defines': [ 'ZLIB_CONST' ],
         }],
 
         [ 'node_shared_http_parser=="false"', {
