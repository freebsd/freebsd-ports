--- ./base/base.gyp.orig	2014-08-20 21:02:42.000000000 +0200
+++ ./base/base.gyp	2014-08-22 15:06:27.000000000 +0200
@@ -129,7 +129,7 @@
           ],
           'link_settings': {
             'libraries': [
-              '-L/usr/local/lib -lexecinfo',
+              '-L/usr/local/lib -lexecinfo -lkvm',
             ],
           },
         }],
