--- src/3rdparty/chromium/third_party/libjingle/libjingle.gyp.orig	2017-04-11 14:08:45 UTC
+++ src/3rdparty/chromium/third_party/libjingle/libjingle.gyp
@@ -395,7 +395,7 @@
           ],
           'conditions': [
             # TODO(mallinath) - Enable SCTP for iOS.
-            ['OS!="ios"', {
+            ['OS!="ios" and os_bsd!=1', {
               'defines': [
                 'HAVE_SCTP',
               ],
