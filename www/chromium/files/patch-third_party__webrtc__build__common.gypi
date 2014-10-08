--- third_party/webrtc/build/common.gypi.orig	2014-10-02 17:40:33 UTC
+++ third_party/webrtc/build/common.gypi
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
