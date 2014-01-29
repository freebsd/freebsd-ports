--- third_party/WebKit/Source/build/features.gypi.orig	2013-08-30 06:55:03.000000000 +0300
+++ third_party/WebKit/Source/build/features.gypi	2013-09-03 22:27:08.777629842 +0300
@@ -94,7 +94,7 @@
           'ENABLE_WEB_AUDIO=1',
         ],
       }],
-      ['OS=="win" or OS=="android" or OS=="linux"', {
+      ['OS=="win" or OS=="android" or OS=="linux" or os_bsd==1', {
         'feature_defines': [
           'ENABLE_OPENTYPE_VERTICAL=1',
         ],
