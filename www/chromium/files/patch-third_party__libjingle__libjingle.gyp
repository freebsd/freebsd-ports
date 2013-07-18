--- third_party/libjingle/libjingle.gyp.orig	2013-07-16 18:48:40.000000000 +0300
+++ third_party/libjingle/libjingle.gyp	2013-07-16 18:50:49.000000000 +0300
@@ -531,7 +531,7 @@
             '<(libjingle_source)/talk/base/unixfilesystem.h',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or os_bsd==1', {
           'sources': [
             '<(libjingle_source)/talk/base/latebindingsymboltable.cc',
             '<(libjingle_source)/talk/base/latebindingsymboltable.h',
