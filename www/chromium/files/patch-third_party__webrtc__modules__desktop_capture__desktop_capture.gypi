--- third_party/webrtc/modules/desktop_capture/desktop_capture.gypi.orig	2014-10-02 17:40:34 UTC
+++ third_party/webrtc/modules/desktop_capture/desktop_capture.gypi
@@ -109,6 +109,11 @@
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
