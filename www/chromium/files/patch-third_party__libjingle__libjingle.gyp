--- ./third_party/libjingle/libjingle.gyp.orig	2014-04-30 22:43:11.000000000 +0200
+++ ./third_party/libjingle/libjingle.gyp	2014-05-04 14:38:48.000000000 +0200
@@ -472,7 +472,7 @@
               ],
             }],
             # TODO(mallinath) - Enable SCTP for iOS.
-            ['OS!="ios"', {
+            ['OS!="ios" and os_bsd!=1', {
               'defines': [
                 'HAVE_SCTP',
               ],
