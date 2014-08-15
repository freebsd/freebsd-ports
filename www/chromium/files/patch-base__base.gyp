--- ./base/base.gyp.orig	2014-08-12 21:01:28.000000000 +0200
+++ ./base/base.gyp	2014-08-13 09:57:00.000000000 +0200
@@ -129,7 +129,7 @@
           ],
           'link_settings': {
             'libraries': [
-              '-L/usr/local/lib -lexecinfo',
+              '-L/usr/local/lib -lexecinfo -lkvm',
             ],
           },
         }],
