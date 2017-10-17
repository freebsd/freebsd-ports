--- third_party/libjpeg_turbo/libjpeg_turbo.gyp.orig	2017-10-05 07:45:26 UTC
+++ third_party/libjpeg_turbo/libjpeg_turbo.gyp
@@ -58,8 +58,11 @@
             ],
           },
           'link_settings': {
+            'ldflags': [
+              '<!@(pkg-config --libs libjpeg)',
+            ],
             'libraries': [
-              '-ljpeg',
+              '<!@(pkg-config --libs libjpeg)',
             ],
           },
         }
