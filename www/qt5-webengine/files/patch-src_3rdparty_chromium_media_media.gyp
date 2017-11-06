--- src/3rdparty/chromium/media/media.gyp.orig	2016-11-07 14:46:18 UTC
+++ src/3rdparty/chromium/media/media.gyp
@@ -809,7 +809,7 @@
             'capture/video/linux/v4l2_capture_delegate_multi_plane.h',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or os_bsd==1', {
           'conditions': [
             ['use_x11==1', {
               'dependencies': [
@@ -1146,7 +1146,7 @@
             'base/simd/filter_yuv_sse2.cc',
           ],
         }],
-        ['OS!="linux" and OS!="win"', {
+        ['OS!="linux" and OS!="win" and os_bsd!=1', {
           'sources!': [
             'base/keyboard_event_counter.cc',
             'base/keyboard_event_counter.h',
