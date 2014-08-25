--- ./third_party/libjingle/libjingle.gyp.orig	2014-08-20 21:03:06.000000000 +0200
+++ ./third_party/libjingle/libjingle.gyp	2014-08-22 15:06:26.000000000 +0200
@@ -477,7 +477,7 @@
               ],
             }],
             # TODO(mallinath) - Enable SCTP for iOS.
-            ['OS!="ios"', {
+            ['OS!="ios" and os_bsd!=1', {
               'defines': [
                 'HAVE_SCTP',
               ],
