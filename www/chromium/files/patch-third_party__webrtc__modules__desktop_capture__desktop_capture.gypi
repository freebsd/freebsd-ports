--- ./third_party/webrtc/modules/desktop_capture/desktop_capture.gypi.orig	2014-04-30 22:44:20.000000000 +0200
+++ ./third_party/webrtc/modules/desktop_capture/desktop_capture.gypi	2014-05-04 14:38:49.000000000 +0200
@@ -101,6 +101,11 @@
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
