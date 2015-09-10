--- media/media.gyp.orig	2014-10-10 09:15:31 UTC
+++ media/media.gyp
@@ -760,6 +760,12 @@
             ['exclude', '_alsa\\.(h|cc)$'],
           ],
         }],
+        ['OS=="freebsd"', {
+          'sources!': [
+            'video/capture/linux/v4l2_capture_delegate.cc',
+            'video/capture/linux/video_capture_device_factory_linux.cc',
+          ]
+        }],
         ['OS!="openbsd"', {
           'sources!': [
             'audio/openbsd/audio_manager_openbsd.cc',
@@ -771,7 +777,7 @@
             'video/capture/linux/v4l2_capture_delegate_multi_plane.h',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or os_bsd==1', {
           'conditions': [
             ['use_x11==1', {
               'dependencies': [
@@ -1085,7 +1091,7 @@
             'base/simd/convert_yuv_to_rgb_x86.cc',
           ],
         }],
-        ['OS!="linux" and OS!="win"', {
+        ['OS!="linux" and OS!="win" and os_bsd!=1', {
           'sources!': [
             'base/keyboard_event_counter.cc',
             'base/keyboard_event_counter.h',
