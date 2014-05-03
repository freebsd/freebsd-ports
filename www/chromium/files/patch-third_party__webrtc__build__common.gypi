--- ./third_party/webrtc/build/common.gypi.orig	2014-04-24 22:37:12.000000000 +0200
+++ ./third_party/webrtc/build/common.gypi	2014-04-24 23:23:48.000000000 +0200
@@ -272,6 +272,13 @@
           'WEBRTC_LINUX',
         ],
       }],
+      ['os_bsd==1', {
+        'defines': [
+          'WEBRTC_BSD',
+          'WEBRTC_LINUX',
+          'WEBRTC_THREAD_RR',
+        ],
+      }],
       ['OS=="mac"', {
         'defines': [
           'WEBRTC_MAC',
