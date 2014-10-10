--- build/linux/unbundle/openssl.gyp.orig	2014-10-02 17:18:52 UTC
+++ build/linux/unbundle/openssl.gyp
@@ -9,15 +9,15 @@
       'type': 'none',
       'direct_dependent_settings': {
         'cflags': [
-          '<!@(pkg-config --cflags openssl)',
+          '',
         ],
       },
       'link_settings': {
         'ldflags': [
-          '<!@(pkg-config --libs-only-L --libs-only-other openssl)',
+          '',
         ],
         'libraries': [
-          '<!@(pkg-config --libs-only-l openssl)',
+          '-lssl',
         ],
       },
     }
