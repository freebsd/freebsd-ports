--- ./third_party/libjingle/libjingle.gyp.orig	2014-08-12 21:02:51.000000000 +0200
+++ ./third_party/libjingle/libjingle.gyp	2014-08-13 09:56:58.000000000 +0200
@@ -473,7 +473,7 @@
               ],
             }],
             # TODO(mallinath) - Enable SCTP for iOS.
-            ['OS!="ios"', {
+            ['OS!="ios" and os_bsd!=1', {
               'defines': [
                 'HAVE_SCTP',
               ],
