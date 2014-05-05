--- ./third_party/libjingle/libjingle.gyp.orig	2014-04-24 22:35:58.000000000 +0200
+++ ./third_party/libjingle/libjingle.gyp	2014-04-24 23:23:47.000000000 +0200
@@ -543,7 +543,7 @@
             '<(libjingle_source)/talk/base/unixfilesystem.h',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or os_bsd==1', {
           'sources': [
             '<(libjingle_source)/talk/base/latebindingsymboltable.cc',
             '<(libjingle_source)/talk/base/latebindingsymboltable.h',
@@ -795,7 +795,7 @@
               ],
             }],
             # TODO(mallinath) - Enable SCTP for iOS.
-            ['OS!="ios"', {
+            ['OS!="ios" and os_bsd!=1', {
               'defines': [
                 'HAVE_SCTP',
               ],
