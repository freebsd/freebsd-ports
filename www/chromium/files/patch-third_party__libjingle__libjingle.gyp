--- third_party/libjingle/libjingle.gyp.orig	2013-08-09 22:05:45.000000000 +0300
+++ third_party/libjingle/libjingle.gyp	2013-08-18 00:43:44.000000000 +0300
@@ -532,7 +532,7 @@
             '<(libjingle_source)/talk/base/unixfilesystem.h',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or os_bsd==1', {
           'sources': [
             '<(libjingle_source)/talk/base/latebindingsymboltable.cc',
             '<(libjingle_source)/talk/base/latebindingsymboltable.h',
@@ -772,7 +772,7 @@
               ],
             }],
             # TODO(mallinath) - Enable SCTP for Android and iOS platforms.
-            ['OS!="android" and OS!="ios"', {
+            ['OS!="android" and OS!="ios" and os_bsd!=1', {
               'conditions': [
                 ['OS!="win"', {
                   'defines': [
