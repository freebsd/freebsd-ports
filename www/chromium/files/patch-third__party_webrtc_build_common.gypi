--- third_party/webrtc/build/common.gypi.orig	2016-05-25 15:02:41.000000000 -0400
+++ third_party/webrtc/build/common.gypi	2016-06-05 15:36:40.916550000 -0400
@@ -402,6 +402,13 @@
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
@@ -485,7 +492,7 @@
             'WEBRTC_WIN',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or os_bsd==1', {
           'defines': [
             'WEBRTC_LINUX',
           ],
