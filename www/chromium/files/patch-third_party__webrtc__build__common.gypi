--- ./third_party/webrtc/build/common.gypi.orig	2014-08-20 21:04:25.000000000 +0200
+++ ./third_party/webrtc/build/common.gypi	2014-08-23 16:42:44.000000000 +0200
@@ -321,6 +321,13 @@
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
