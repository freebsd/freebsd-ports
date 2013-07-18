--- third_party/WebKit/Source/core/features.gypi.orig	2013-07-15 19:58:55.000000000 +0300
+++ third_party/WebKit/Source/core/features.gypi	2013-07-15 20:00:22.000000000 +0300
@@ -103,7 +103,7 @@
           'ENABLE_WEB_AUDIO=1',
         ],
       }],
-      ['OS=="linux" or OS=="mac" or OS=="android"', {
+      ['OS=="linux" or OS=="mac" or OS=="android" or os_bsd==1', {
         'feature_defines': [
           # 8Bit text runs should be enabled for all platforms webkit.org/b/111348
           'ENABLE_8BIT_TEXTRUN=1',
@@ -128,7 +128,7 @@
           'ENABLE_WEB_AUDIO=1',
         ],
       }],
-      ['OS=="win" or OS=="android" or OS=="linux"', {
+      ['OS=="win" or OS=="android" or OS=="linux" or os_bsd==1', {
         'feature_defines': [
           'ENABLE_OPENTYPE_VERTICAL=1',
         ],
@@ -143,7 +143,7 @@
           'ENABLE_RUBBER_BANDING=1',
         ],
       }],
-      ['OS=="linux" or OS=="android"', {
+      ['OS=="linux" or OS=="android" or os_bsd==1', {
         'feature_defines': [
           'WTF_USE_HARFBUZZ=1',
         ],
