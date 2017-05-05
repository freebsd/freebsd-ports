Define WEBRTC_BSD, to better handle FreeBSD in the sources.

Copied from www/chromium.

--- src/3rdparty/chromium/third_party/webrtc/build/common.gypi.orig	2016-11-07 14:46:18 UTC
+++ src/3rdparty/chromium/third_party/webrtc/build/common.gypi
@@ -352,6 +352,11 @@
           'WEBRTC_LINUX',
         ],
       }],
+      ['os_bsd==1', {
+        'defines': [
+          'BSD',
+        ],
+      }],
       ['OS=="mac"', {
         'defines': [
           'WEBRTC_MAC',
