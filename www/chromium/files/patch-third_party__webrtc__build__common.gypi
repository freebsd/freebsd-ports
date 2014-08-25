--- ./third_party/webrtc/build/common.gypi.orig	2014-04-30 22:44:26.000000000 +0200
+++ ./third_party/webrtc/build/common.gypi	2014-05-04 14:38:49.000000000 +0200
@@ -287,6 +287,13 @@
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
