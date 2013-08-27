--- third_party/webrtc/modules/desktop_capture/desktop_capture.gypi.orig	2013-08-16 22:24:59.000000000 +0300
+++ third_party/webrtc/modules/desktop_capture/desktop_capture.gypi	2013-08-16 22:27:28.000000000 +0300
@@ -75,6 +75,11 @@
             ],
           },
         }],
+        ['os_bsd==1', {
+          'include_dirs': [
+            '<(prefix_dir)/include',
+          ],
+        }],
         ['OS!="win" and OS!="mac" and use_x11==0', {
           'sources': [
             "screen_capturer_null.cc",
