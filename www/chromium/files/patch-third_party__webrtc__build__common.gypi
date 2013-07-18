--- third_party/webrtc/build/common.gypi.orig	2013-07-16 16:41:06.000000000 +0300
+++ third_party/webrtc/build/common.gypi	2013-07-16 17:21:31.000000000 +0300
@@ -272,6 +272,13 @@
           #'WEBRTC_CLOCK_TYPE_REALTIME',
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
