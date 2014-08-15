--- ./third_party/webrtc/modules/desktop_capture/desktop_capture.gypi.orig	2014-08-12 21:04:10.000000000 +0200
+++ ./third_party/webrtc/modules/desktop_capture/desktop_capture.gypi	2014-08-13 09:57:00.000000000 +0200
@@ -107,6 +107,11 @@
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
             "mouse_cursor_monitor_null.cc",
