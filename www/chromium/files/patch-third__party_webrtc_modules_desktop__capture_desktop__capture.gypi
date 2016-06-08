--- third_party/webrtc/modules/desktop_capture/desktop_capture.gypi.orig	2016-05-11 19:04:03 UTC
+++ third_party/webrtc/modules/desktop_capture/desktop_capture.gypi
@@ -114,6 +114,11 @@
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
