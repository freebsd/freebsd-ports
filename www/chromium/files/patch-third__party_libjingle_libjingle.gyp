--- third_party/libjingle/libjingle.gyp.orig	2016-05-25 15:01:12.000000000 -0400
+++ third_party/libjingle/libjingle.gyp	2016-05-27 11:30:30.507965000 -0400
@@ -121,6 +121,8 @@
         ['os_bsd==1', {
           'defines': [
             'BSD',
+            'WEBRTC_LINUX',
+            'WEBRTC_BSD',
           ],
         }],
         ['OS=="openbsd"', {
@@ -191,6 +193,8 @@
       ['os_bsd==1', {
         'defines': [
           'BSD',
+          'WEBRTC_LINUX',
+          'WEBRTC_BSD',
         ],
       }],
       ['OS=="openbsd"', {
