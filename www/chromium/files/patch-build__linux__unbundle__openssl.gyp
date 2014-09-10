--- ./build/linux/unbundle/openssl.gyp.orig	2014-08-20 21:02:29.000000000 +0200
+++ ./build/linux/unbundle/openssl.gyp	2014-08-22 15:06:24.000000000 +0200
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
