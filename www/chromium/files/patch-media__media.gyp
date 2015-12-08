--- media/media.gyp.orig	2015-10-21 18:00:38.000000000 -0400
+++ media/media.gyp	2015-10-23 12:57:14.545450000 -0400
@@ -780,13 +780,19 @@
             ['exclude', '_alsa\\.(h|cc)$'],
           ],
         }],
-        ['OS=="openbsd"', {
+        ['OS=="freebsd"', {
+          'sources!': [
+            'capture/video/linux/v4l2_capture_delegate.cc',
+            'capture/video/linux/video_capture_device_factory_linux.cc',
+          ],
+        }],
+        ['OS=="openbsd" or OS=="freebsd"', {
           'sources!': [
             'capture/video/linux/v4l2_capture_delegate_multi_plane.cc',
             'capture/video/linux/v4l2_capture_delegate_multi_plane.h',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or os_bsd==1', {
           'conditions': [
             ['use_x11==1', {
               'dependencies': [
@@ -1122,7 +1128,7 @@
             'base/simd/filter_yuv_sse2.cc',
           ],
         }],
-        ['OS!="linux" and OS!="win"', {
+        ['OS!="linux" and OS!="win" and os_bsd!=1', {
           'sources!': [
             'base/keyboard_event_counter.cc',
             'base/keyboard_event_counter.h',
