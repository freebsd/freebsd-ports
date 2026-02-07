--- deps/sqlcipher/sqlcipher.gyp.orig	2025-04-10 21:58:12 UTC
+++ deps/sqlcipher/sqlcipher.gyp
@@ -90,7 +90,7 @@
         }, {
           'link_settings': {
             'libraries': [
-              '<(SHARED_INTERMEDIATE_DIR)/libsignal_sqlcipher_extension.a',
+              'PREFIX/lib/libsignal_sqlcipher_extension.a',
             ]
           },
         }],
